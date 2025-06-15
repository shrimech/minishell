/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:19:08 by shrimech          #+#    #+#             */
/*   Updated: 2025/06/15 01:08:43 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/minishell.h"
#include "includes/parsing.h"

#include <fcntl.h>

int main(int ac,char **av, char**env)
{
    t_env *envp;
    
    envp = convert_env(env);
}
