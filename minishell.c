/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:19:08 by shrimech          #+#    #+#             */
/*   Updated: 2025/06/09 05:50:52 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/minishell.h"
#include <fcntl.h>

void ft_fd_print(int fd, char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        write(fd, &str[i],1);
        i++;
    }
}

int main(int argc, char *argv[], char *envp[]) {
    int i = 0;
    int fd = open("file_utils/env.txt" , O_CREAT | O_WRONLY ,0400);
    while (envp[i] != NULL) {
        ft_fd_print(fd, envp[i]);
        ft_fd_print(fd, "\n");
        i++;
    }
    close(fd);
    return 0;
}



char *get_line(int a,int fd)
{
    int i = 1;
    int j = 0;

    
    
    while(i<a)
    {
        read
        
    }
}
