/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaissam <slaissam@.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:26:22 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/23 04:15:20 by slaissam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "defines.h"
# include "parsing.h"

typedef struct s_data	t_data;

typedef struct s_cmd
{
	bool				skip_cmd;
	int					infile;
	int					outfile;
	int					fd_her;
	char				**cmd_param;
	struct s_cmd		*prev;
	struct s_cmd		*next;
}						t_cmd;

/* ---------- Execution ---------- */
bool					exec(t_data *data);
bool					is_builtin(t_cmd *cmd);
bool					cmd_exist(char **path, t_data *data, char *cmd);
bool					launch_builtin(t_data *data, t_cmd *cmd);
char					*find_cmd(t_data *data, char *sample,
							t_envirement *env);
void					child_process(t_data *data, t_cmd *cmd, int *pip);

/* ---------- Pipes ---------- */
int						pipes(t_data *data);
void					advance_token(t_token **token, t_data *data);
int						count_cmds(t_cmd *cmd);
void					controlfds(int *prev, int *fd, t_cmd *cmd,
							t_data *data);
void					wait_all(int *pid, int n, t_data *data);
int						prev_set_up(int a);

/* ---------- Commands ---------- */
int						append_cmd(t_cmd **list, int infile, int outfile,
							char **cmd_param);
void					free_cmd(t_cmd **list);
bool					create_list_cmd(t_data *data);
bool					get_infile(t_data *data, t_token *token, t_cmd *cmd);
bool					get_outfile(t_token *token, t_cmd *cmd, t_data *data);
char					**get_param(t_data *data, t_token *token);

/* ---------- Builtins ---------- */
int						ft_env(t_envirement *env);
int						ft_export(char **str, t_envirement **env);
bool					export(char *str, t_envirement **env);
int						ft_echo(char **args);
int						ft_unset(char **str, t_envirement **env);
int						ft_pwd(void);
int						ft_cd(t_data *data, char **params);
void					ft_exit(t_data *data, char **args);

#endif
