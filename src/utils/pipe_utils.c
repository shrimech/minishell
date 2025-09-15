/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaissam <slaissam@.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 02:59:57 by slaissam          #+#    #+#             */
/*   Updated: 2025/08/23 03:54:51 by slaissam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	setupin(int prev)
{
	if (prev != -1)
	{
		dup2(prev, 0);
		close(prev);
	}
}

void	setupout(t_cmd *current_cmd, t_data *data, int *fd)
{
	if (current_cmd->next != data->cmd)
	{
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd[0]);
	}
}

void	advance_token(t_token **token, t_data *data)
{
	while ((*token)->next != data->token && (*token)->prev->type != PIPE)
		*token = (*token)->next;
	*token = (*token)->next;
}

int	count_cmds(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	i = 1;
	tmp = cmd;
	while (tmp->next != cmd)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	controlfds(int *prev, int *fd, t_cmd *cmd, t_data *data)
{
	if (*prev != -1)
		close(*prev);
	else if (cmd->next != data->cmd)
	{
		*prev = fd[0];
		close(fd[1]);
	}
}
