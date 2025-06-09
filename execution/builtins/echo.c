/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaissam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:35:00 by slaissam          #+#    #+#             */
/*   Updated: 2025/06/03 20:35:00 by slaissam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int is_n_option(char *str)
{
    return (str && strcmp(str, "-n") == 0);
}

int echo_cmd(t_tools *tool)
{
    int i = 1;
    int newline = 1;

    while (tool->args[i] && is_n_option(tool->args[i]))
    {
        newline = 0;
        i++;
    }
    
    while (tool->args[i])
    {
        printf("%s", tool->args[i]);
        if (tool->args[i + 1])
            printf(" ");
        i++;
    }
    if (newline)
        printf("\n");
    
    return (0);
}