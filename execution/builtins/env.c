/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaissam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:24:42 by slaissam          #+#    #+#             */
/*   Updated: 2025/06/03 20:24:42 by slaissam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int env_cmd(t_tools *tool)
{
    int i;
    
    if (tool->args[1] != NULL)
    {
        printf("env: too many arguments\n");
        return (1);
    }
    i = 0;
    while (tool->envp[i] != NULL)
    {
        printf("%s\n", tool->envp[i]);
        i++;
    }
    return (0);
}
