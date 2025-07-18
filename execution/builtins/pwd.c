/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:13:31 by slaissam          #+#    #+#             */
/*   Updated: 2025/06/17 01:56:49 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int pwd_cmd(t_command *tool)
{
    if (getcwd(tool->pwd, sizeof(tool->pwd)) != NULL)
        printf("Current directory: %s\n", tool->pwd);
    else {
        perror("getcwd() error");
        return 1;
    }
    return 0;
}
