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

#include "../../includes/minishell.h"

int env_cmd(t_env *tool)
{
    
    // if (tool-> != NULL)
    // {
    //     printf("env: too many arguments\n");
    //     return (1);
    // }
    while (tool != NULL)
    {
        printf("%s=%s\n", tool->var,tool->value);
        tool =  tool->next;
    }
    return (0);
}
