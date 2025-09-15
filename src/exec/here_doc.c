/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaissam <slaissam@.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:11:58 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/23 05:04:27 by slaissam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	read_in_stdin_loop(char *word, t_data *data, t_here *her, int fd)
{
	int		i;
	char	*buf;

	i = 0;
	while (1)
	{
		buf = NULL;
		buf = readline("> ");
		if (check_buf(buf, word) == false)
			break ;
		if (!ft_strncmp(word, buf, INT_MAX))
			break ;
		while (her->next != NULL)
			her = her->next;
		is_quoted(&data->token->quoted, &i, her->del);
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
}

static int	read_in_stdin(t_data *data, int fd, char *word)
{
	int		status;
	pid_t	pid;
	t_here	*her;

	status = 0;
	her = global_her(NULL);
	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == 0)
	{
		signal(SIGINT, &handle_here_doc_sigint);
		read_in_stdin_loop(word, data, her, fd);
		close(fd);
		exit(0);
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	signal(SIGINT, &handle_sigint);
	if (WIFEXITED(status))
		data->exit_code = WEXITSTATUS(status);
	if (data->exit_code == 130)
		return (2);
	return (true);
}

int	here_doc(t_data *data, char *word)
{
	int		fd;
	char	*he_name;
	int		k;

	he_name = h_name();
	fd = open(he_name, O_CREAT | O_WRONLY, 0644);
	if (fd < 0)
		return (-1);
	k = read_in_stdin(data, fd, word);
	if (k == 2)
	{
		unlink(he_name);
		close(fd);
		return (-5);
	}
	fd = open(he_name, O_RDONLY);
	if (fd > 0)
		unlink(he_name);
	return (fd);
}

int	loop_loop_here_doc(t_data *data, int i, t_cmd *current_cmd, t_token *tmp)
{
	int	k;

	k = 0;
	while (k < i)
	{
		current_cmd->fd_her = -1;
		while (tmp->next != data->token && tmp->type != PIPE)
		{
			if (tmp->type == HEREDOC)
			{
				current_cmd->fd_her = here_doc(data, tmp->next->str);
				if (current_cmd->fd_her == -5)
					return (-5);
			}
			tmp = tmp->next;
		}
		tmp = tmp->next;
		k++;
		current_cmd = current_cmd->next;
	}
	return (0);
}

int	loop_here_doc(t_data *data)
{
	t_cmd	*current_cmd;
	t_token	*tmp;
	int		i;

	current_cmd = data->cmd;
	tmp = data->token;
	i = 1;
	while (current_cmd->next != data->cmd)
	{
		i++;
		current_cmd = current_cmd->next;
	}
	current_cmd = data->cmd;
	if (loop_loop_here_doc(data, i, current_cmd, tmp) == -5)
		return (-5);
	return (0);
}
