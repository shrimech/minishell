/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:19:08 by shrimech          #+#    #+#             */
/*   Updated: 2025/06/17 15:20:13 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/minishell.h"

char    *get_prompt(void)
{
    char *prompt;
    
    prompt = ft_strjoin(ft_strjoin(getenv("USER"),"@"),getenv("DESKTOP_SESSION"));
    prompt = ft_strjoin(ft_strjoin(prompt,":>>"),getenv("PWD"));
    prompt = ft_strjoin(prompt,">>$");
    return(prompt);
}

void program_loop(t_env **envp)
{
    char *input;
    char *prompt;

    (void)envp;
    prompt = get_prompt();
    while (1)
    {
        input = readline(prompt);
        exit_cmd(input);
        // parsing(input);
        printf("%s\n",input);
    }
}

int main(int ac,char **av, char**env)
{
    t_env *envp;
    (void)ac;
    (void)av;
    envp = convert_env(env);
    (void)envp;
    signal_handler();
    program_loop(&envp);    
}
