/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaissam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:15:55 by slaissam          #+#    #+#             */
/*   Updated: 2025/06/09 04:44:05 by slaissam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
int is_builtin(char *cmd)
{
    char *built[]  = {"cd", "pwd", "echo", "export", "unset", "env", "exit", NULL};
    int i;

    i = 0;
    while (built[i])
    {
        if (strcmp(built[i],cmd) == 0)
            return 0;
        else
            i++;
    }
    return 1;
}

int execute_builtin(t_tools *tool) {
    char *cmd ;
    
    cmd = tools->args[0];
    
    if (strcmp(cmd, "echo") == 0)
        return echo_cmd(tool);
    // else if (strcmp(cmd, "cd") == 0)
    //     return cd(args);
    else if (strcmp(cmd, "pwd") == 0)
        return pwd_cmd(tool);
    // else if (strcmp(cmd, "export") == 0)
    //     return export(args);
    // else if (strcmp(cmd, "unset") == 0)
    //     return unset(args);
    else if (strcmp(cmd, "env") == 0)
        return env_cmd(tool);
    // else if (strcmp(cmd, "exit") == 0)
    //     return exit(args);
    return 1;
}

int main(int ac, char **av, char **env)
{
    t_tools tools;
    // tools = (t_tools)malloc(sizeof(t_tools));
    tools.envp = env;
    if (ac != 1)
    {
        printf("Too many args\n");
        return 1;
    }
    while(1) {
        tools.av = readline("mshell$");
        tools.args = ft_split(tools.av, ' ');
        if (is_builtin(tools.args[0]) == 0)
        {
            if (execute_builtin(&tools))
                printf("failed\n");
        }
        // free(avv);
        // free(tools->args);
    }
    // free_tools(tools);
    return 0;
}
