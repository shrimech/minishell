/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaissam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:13:31 by slaissam          #+#    #+#             */
/*   Updated: 2025/06/09 03:16:23 by slaissam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int pwd_cmd(t_tools tool)
{
    if (getcwd(tool.pwd, sizeof(cwd)) != NULL)
        printf("Current directory: %s\n", tool.pwd);
    else {
        perror("getcwd() error");
        return 1;
    }
    return 0;
}
