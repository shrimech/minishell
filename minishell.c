/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:19:08 by shrimech          #+#    #+#             */
/*   Updated: 2025/06/15 05:32:23 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/minishell.h"

#include <fcntl.h>

int main(int ac,char **av, char**env)
{
    t_env *envp;
    
    (void)ac;
    (void)av;
    envp = convert_env(env);
    env_cmd(envp);    
}
