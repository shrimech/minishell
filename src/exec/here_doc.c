/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:11:58 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/23 01:42:59 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

static int	read_in_stdin(t_data *data, int fd, char *word)
{
	char	*buf;
	int status = 0;
	pid_t pid;
	t_here *her = global_her(NULL);
	int i = 0;
	
	pid = fork();
	if (pid == -1)
	perror("fork");
	if (pid == 0)
	{
		signal(SIGINT,&handle_here_doc_sigint);
		while (1)
		{
			buf = NULL;
			buf = readline("> ");
			if (!buf)
			{
				print_error("warning: here-document delimited by end-of-file ");
				print_error("(wanted '");
				print_error(word);
				print_error("')\n");
				break ;
			}
			if (!ft_strncmp(word, buf, INT_MAX))
				break ;
			is_quoted(&data->token->quoted,&i,her->del);
			if (!data->token->quoted)
			{
				if (!replace_dollar(&buf, data))
					free_all(data, ERR_MALLOC, EXT_MALLOC);
			}
			write(fd, buf, ft_strlen(buf));
			write(fd, "\n", 1);
			free(buf);
		}
		free(buf);
		close(fd);
		exit(0);
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	signal(SIGINT, &handle_sigint);
	if (WIFEXITED(status))
	{
		data->exit_code = WEXITSTATUS(status);
	}
	if (data->exit_code == 130)
	{
		return(2);
	}
	return (true);
}

char *h_name(void)
{
	int pid;

	pid = fork();
	if (pid == 0)
		 exit (0);
	return(ft_strjoin("/tmp/" , ft_itoa(pid)));
}

int	here_doc(t_data *data, char *word)
{
	int	fd;
	char *he_name = h_name();

	fd = open(he_name, O_CREAT | O_WRONLY , 0644);
	if (fd < 0)
		return (-1);
	int k = read_in_stdin(data, fd, word);
	if (k == 2)
	{
		unlink(he_name);
		close(fd);
		return(-5);
	}
	fd = open(he_name, O_RDONLY);
	if (fd > 0)
		unlink(he_name);
	return (fd);
}

int	loop_here_doc(t_data *data)
{
	t_cmd *current_cmd = data->cmd;
	t_token *tmp;
	tmp = data->token;
	int i = 1;
	
	int k = 0;
	while (current_cmd->next != data->cmd)
    {
        i++;
        current_cmd = current_cmd->next;
    }
	current_cmd = data->cmd;
	while (k < i)
	{
		current_cmd->fd_her = -1;
		while (tmp->next != data->token && tmp->type != PIPE)
		{
			if (tmp->type == HEREDOC)
			{
				current_cmd->fd_her = here_doc(data, tmp->next->str);
				if (current_cmd->fd_her == -5)
					return(-5);
			}
			tmp = tmp->next;
		}
		tmp = tmp->next;
		k++;
		current_cmd = current_cmd->next;
	}
	return (0);
}