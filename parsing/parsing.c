/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:51:44 by shrimech          #+#    #+#             */
/*   Updated: 2025/06/17 03:23:26 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void parsing(char *input)
{
    t_command *cmd;
    char **command;
    char ***splited;
    int i;

    command = ft_split(input , '|');
    while(command[i])
    {
        splited[i] = ft_split(command[i], ' ');
        i++;
    }
}






//-------------------------|
//echo salah |wc -l        |
//cmd[0] = echo salah      |
//splited[0][0] = echo     |
//
//
//
//
//
//
//