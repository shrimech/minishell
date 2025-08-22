/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:26:22 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/22 09:31:06 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "defines.h"
# include "parsing.h"

/* ---------- Structures ---------- */
typedef struct s_cmd
{
    bool            skip_cmd;
    int             infile;
    int             outfile;
    int             fd_her;
    char            **cmd_param;
    struct s_cmd    *prev;
    struct s_cmd    *next;
}   t_cmd;

/* ---------- Functions ---------- */
// execution
bool    exec(void *data);
bool    is_builtin(t_cmd *cmd);
bool    launch_builtin(void *data, t_cmd *cmd);
char    *find_cmd(void *data, char *sample, t_envirement *env);
void    child_process(void *data, t_cmd *cmd, int *pip);
int     pipes(void *data);

// cmd utils
int     append_cmd(t_cmd **list, int infile, int outfile, char **cmd_param);
void    free_cmd(t_cmd **list);
size_t  len_cmd(t_cmd *list);
bool    create_list_cmd(void *data);
bool    get_infile(void *data, t_token *token, t_cmd *cmd);
bool    get_outfile(t_token *token, t_cmd *cmd, void *data);
char    **get_param(t_data *data, t_token *token);

// builtins
int     ft_env(t_envirement *env);
int     ft_export(char **str, t_envirement **env);
bool    export(char *str, t_envirement **env);
int     ft_echo(char **args);
int     ft_unset(char **str, t_envirement **env);
int     ft_pwd(void);
int     ft_cd(void *data, char **params);
void    ft_exit(void *data, char **args);

#endif
