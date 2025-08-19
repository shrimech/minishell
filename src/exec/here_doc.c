/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:11:58 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/19 12:52:46 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

static bool	read_in_stdin(t_data *data, int fd, char *word)
{
	char	*buf;

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
		if (!replace_dollar(&buf, data))
			free_all(data, ERR_MALLOC, EXT_MALLOC);
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
		free(buf);
	}
	free(buf);
	close(fd);
	return (true);
}

int	here_doc(t_data *data, char *word)
{
	int	fd;

	fd = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);
	if (!read_in_stdin(data, fd, word))
	{
		unlink(".heredoc.tmp");
		return (-1);
	}
	fd = open(".heredoc.tmp", O_RDONLY);
	if (fd > 0)
		unlink(".heredoc.tmp");
	return (fd);
}

// int	loop_here_doc(t_data *data)
// {
// 	t_token *tmp;
// 	int fd;
// 	tmp = data->token;

// 	fd = -1;
// 	while (tmp->next != data->token)
// 	{
// 		if (tmp->type == HEREDOC)
// 			fd = here_doc(data, tmp->next->str);
// 		tmp = tmp->next;
// 	}
// 	return (dup(fd));
// }