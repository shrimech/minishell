/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaissam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 04:21:38 by slaissam          #+#    #+#             */
/*   Updated: 2025/06/07 04:21:38 by slaissam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int is_n_number(char *input)
{
    int i;

    i = 0;
    if (input[i] == '-')
        i++;
    while(input[i])
    {
        if (ft_isdigit(input[i]))
            i++;
        else
            return(1);
    }
    return (0);
}

int exit_cmd(char *input)
{
    char **split;

    if (input)
        split = ft_split(input,' ');
    if ((input == NULL || ft_strcmp(split[0],"exit") == 0) && split[1] == NULL)
        exit((printf("exit\n"),0));
    if (ft_strcmp(split[0],"exit") == 0 && is_n_number(split[1]))
        exit((printf("exit\nminishell: exit: a: numeric argument required\n"),2));
    if (ft_strcmp(split[0],"exit") == 0 && !is_n_number(split[1]) && split[2] == NULL)
        exit((printf("exit\n"),ft_atoi(split[1])));
    if (ft_strcmp(split[0],"exit") == 0 && !is_n_number(split[1]) && split[2] != NULL)
        exit((printf("exit\nminishell: exit: too many arguments\n"),1));
    return(0);
}
