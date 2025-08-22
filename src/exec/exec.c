/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:11:35 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/22 08:17:42 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_builtin(t_cmd *cmd)
{
	if (!cmd->cmd_param)
		return (false);
	if (!cmd->cmd_param[0])
		return (false);
	if (!ft_strncmp("echo", cmd->cmd_param[0], INT_MAX) || !ft_strncmp("cd",
			cmd->cmd_param[0], INT_MAX) || !ft_strncmp("pwd", cmd->cmd_param[0],
			INT_MAX) || !ft_strncmp("export", cmd->cmd_param[0], INT_MAX)
		|| !ft_strncmp("unset", cmd->cmd_param[0], INT_MAX)
		|| !ft_strncmp("env", cmd->cmd_param[0], INT_MAX) || !ft_strncmp("exit",
			cmd->cmd_param[0], INT_MAX))
		return (true);
	return (false);
}
