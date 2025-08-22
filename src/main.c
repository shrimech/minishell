/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:14:16 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/22 23:35:16 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

pid_t	g_signal_pid;

bool	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (i == (int)ft_strlen(line))
	{
		free(line);
		return (true);
	}
	return (false);
}

bool	parseline(t_data *data, char *line)
{
	ft_delimitre(line);
	if (open_quote(data, line))
	{
		free(line);
		return (false);
	}
	if (!replace_dollar(&line, data) || !create_list_token(&data->token, line))
	{
		free(line);
		free_all(data, ERR_MALLOC, EXT_MALLOC);
	}
	if (data->token && (data->token->prev->type == PIPE
			|| data->token->type == PIPE))
	{
		write(2, "Error: syntax error near unexpected token '|'\n", 46);
		data->exit_code = 2;
		free_token(&data->token);
		return (false);
	}
	if (!data->token || !create_list_cmd(data))
	{
		free_token(&data->token);
		free_cmd(&data->cmd);
		return (false);
	}
	data->fd = loop_here_doc(data);
	if (data->fd == -5)
		return (false);
	return (check_pipe(data));
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	char	*line;

	init_data(&data, argc, argv);
	if (!make_env(&data, env))
		free_all(&data, ERR_MALLOC, EXT_MALLOC);
	while (1)
	{
		data.cmd = NULL;
		line = readline("minishell> ");
		if (g_signal_pid != 0)
			data.exit_code = 128 + g_signal_pid;
		if (!line)
			free_all(&data, "exit\n", data.exit_code);
		if (empty_line(line))
			continue ;
		add_history(line);
		if (!parseline(&data, line))
		{
			free_cmd(&data.cmd);
			continue ;
		}
		if (data.cmd->next == data.cmd && is_builtin(data.cmd))
			launch_builtin(&data, data.cmd);
		else if (data.cmd->cmd_param && data.cmd->cmd_param[0] && !pipes(&data))
			free_all(&data, ERR_PIPE, EXT_PIPE);
		free_cmd(&data.cmd);
		free_token(&data.token);
		g_signal_pid = 0;
	}
	rl_clear_history();
	free_all(&data, NULL, -1);
	return (0);
}
