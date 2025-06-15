/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:21:16 by shrimech          #+#    #+#             */
/*   Updated: 2025/06/15 05:33:24 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
#define EXECUTION_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_tools
{
    char **args;
    char **envp;
    char *av;
    char pwd[1024];
    char *oldpwd;
} t_tools;

int env_cmd(t_env *tool);
int echo_cmd(t_tools *tool);
int pwd_cmd(t_tools tool);
char	**ft_split(char *s, char c);

#endif