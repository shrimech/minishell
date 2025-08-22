/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:12:19 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/22 06:50:22 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	open_file(t_data *data, char *filename, int type)
{
	int	fd;

	(void)data;
	fd = -2;
	if (type == RED_IN)
		fd = open(filename, O_RDONLY, 0644);
	else if (type == RED_OUT)
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (type == APPEND)
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (type != HEREDOC && fd < 0)
		perror(filename);
	return (fd);
}

static bool	get_in(t_data *data, t_token *tmp, t_cmd *cmd)
{
	if (tmp->type == RED_IN)
	{
		if (cmd->infile >= 0)
			close(cmd->infile);
		if (tmp == tmp->next || tmp->next->type <= 5)
			return (print_error_token(tmp, data));
		cmd->infile = open_file(data, tmp->next->str, RED_IN);
		if (cmd->infile == -1)
			return (false);
	}
	return (true);
}

bool	get_infile(t_data *data, t_token *token, t_cmd *cmd)
{
	t_token	*tmp;

	tmp = token;
	if (tmp->type != PIPE && !get_in(data, tmp, cmd))
		return (false);
	if (tmp->type == PIPE)
		return (true);
	tmp = tmp->next;
	while (tmp->type != PIPE && tmp != data->token)
	{
		if (!get_in(data, tmp, cmd))
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

static bool	get_out(t_token *tmp, t_cmd *cmd, t_data *data)
{
	if (tmp->type == RED_OUT)
	{
		if (cmd->outfile >= 0)
			close(cmd->outfile);
		if (tmp == tmp->next || tmp->next->type <= 5)
			return (print_error_token(tmp, data));
		cmd->outfile = open_file(NULL, tmp->next->str, RED_OUT);
		if (cmd->outfile == -1)
			return (false);
	}
	else if (tmp->type == APPEND)
	{
		if (cmd->outfile >= 0)
			close(cmd->outfile);
		if (tmp == tmp->next || tmp->next->type <= 5)
			return (print_error_token(tmp, data));
		cmd->outfile = open_file(NULL, tmp->next->str, APPEND);
		if (cmd->outfile == -1)
			return (false);
	}
	return (true);
}

bool	get_outfile(t_token *token, t_cmd *cmd, t_data *data)
{
	t_token	*tmp;

	tmp = token;
	if (tmp->type != PIPE && !get_out(tmp, cmd, data))
		return (false);
	tmp = tmp->next;
	while (tmp != data->token && tmp->type != PIPE)
	{
		if (!get_out(tmp, cmd, data))
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
