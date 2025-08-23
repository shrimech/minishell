/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:09:07 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/23 01:01:59 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// *********** --- global varillable ---******************//
/* ---------- External Includes ---------- */
# include "../libft/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

// ************* --- Internal Includes --- ****************//
# include "defines.h"
# include "execution.h"
# include "parsing.h"

// *********** --- global varillable ---******************//
extern pid_t	g_signal_pid;

// *********** --- Core Structure --- ******************* //
typedef struct s_data
{
	t_envirement	*env;
	t_token			*token;
	t_cmd			*cmd;
	int				fd;
	int				exit_code;
	int				pip[2];
	bool			sq;
}					t_data;

//******************* --- Init --- ********************** //
int					make_env(t_data *data, char **env);
bool				make_env2(t_data *data);

/* ---------- Signals ---------- */
void				handle_sigint(int code);
void				clear_rl_line(void);
void				signals(t_data **data);
void				signals2(void);
void				handle_here_doc_sigint(int code);

/* ---------- Utils ---------- */
void				free_array(char **arr);
bool				print_error(char *str);
bool				print_error_token(t_token *token, t_data *data);
void				free_all(t_data *data, char *err, int ext);
char				**lst_to_arr(t_envirement *env);
void				sort_array(char **arr, int len);
bool				is_space(char c);
int					is_special(char *str);
bool				check_pipe(t_data *data);
void				absolute_path(char **path, char *cmd, t_data *data);
void				search_and_replace(char *str, char *value,
						t_envirement **env, int pos);
void				ft_delimitre(char *line);
void				init_data(t_data *data, int argc, char **argv);
char				*get_del(char *line);

/* ---------- Debug ---------- */
void				print_token(t_token *token);
void				print_tab(char **tab);
void				print_cmd(t_cmd *cmd);

#endif
