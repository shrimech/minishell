/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaissam <slaissam@.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 04:01:34 by slaissam          #+#    #+#             */
/*   Updated: 2025/08/23 04:14:34 by slaissam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	redirect_in_out(t_cmd *cmd, t_token *token)
{
	t_token	*current_token;

	current_token = token;
	while (current_token->next != token && current_token->type != PIPE)
	{
		if (current_token->type == HEREDOC && cmd->fd_her >= 0)
			dup2(cmd->fd_her, 0);
		if (current_token->type == RED_IN && cmd->infile >= 0)
			dup2(cmd->infile, 0);
		if ((current_token->type == RED_OUT || current_token->type == APPEND)
			&& cmd->outfile >= 0)
			dup2(cmd->outfile, 1);
		current_token = current_token->next;
	}
	if (cmd->fd_her >= 0)
		close(cmd->fd_her);
	if (cmd->infile >= 0)
		close(cmd->infile);
	if (cmd->outfile >= 0)
		close(cmd->outfile);
}

void	processall(t_data *data, t_cmd *cmd, t_token *token)
{
	char	*path;
	char	**env;

	path = NULL;
	if (cmd->skip_cmd)
		data->exit_code = 1;
	else if (is_builtin(cmd))
		launch_builtin(data, cmd);
	else if (cmd_exist(&path, data, cmd->cmd_param[0]))
	{
		env = lst_to_arr(data->env);
		if (!env)
			free_all(data, ERR_MALLOC, EXT_MALLOC);
		redirect_in_out(cmd, token);
		execve(path, cmd->cmd_param, env);
		free(env);
	}
	if (path)
		free(path);
	free_all(data, NULL, data->exit_code);
}

static void	run_fork(t_data *data, t_cmd *cmd, int *pid, int *fd)
{
	int	prev;

	prev = prev_set_up(-500);
	*pid = fork();
	if (*pid == -1)
		perror("fork");
	signal(SIGINT, SIG_IGN);
	if (*pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		setupin(prev);
		setupout(cmd, data, fd);
		processall(data, cmd, data->token);
	}
}

static void	exec_cmd_loop(t_data *data, int *pid, int n)
{
	int		fd[2];
	int		prev;
	int		k;
	t_cmd	*cmd;
	t_token	*token;

	prev = -1;
	cmd = data->cmd;
	token = data->token;
	k = -1;
	while (++k < n)
	{
		if (cmd->next != data->cmd && pipe(fd) == -1)
			perror("pipe");
		prev_set_up(prev);
		run_fork(data, cmd, &pid[k], fd);
		advance_token(&token, data);
		controlfds(&prev, fd, cmd, data);
		cmd = cmd->next;
	}
	if (prev != -1)
		close(prev);
}

int	pipes(t_data *data)
{
	int	i;
	int	*pid;

	i = count_cmds(data->cmd);
	pid = malloc(sizeof(int) * i);
	if (!pid)
		return (0);
	exec_cmd_loop(data, pid, i);
	wait_all(pid, i, data);
	signal(SIGINT, &handle_sigint);
	return (1);
}
