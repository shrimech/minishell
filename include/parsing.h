/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:25:06 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/23 01:01:47 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "defines.h"
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_data	t_data;

typedef struct s_token
{
	char				*str;
	int					type;
	bool				quoted;
	struct s_token		*prev;
	struct s_token		*next;
}						t_token;

typedef struct s_list
{
	char				*str;
	struct s_list		*prev;
	struct s_list		*next;
}						t_envirement;

typedef struct s_here
{
	char				*del;
	int					index;
	int					pipe;
	struct s_here		*next;
}						t_here;

/* ---------- Tokens ---------- */
bool					create_list_token(t_token **begin, char *command);
int						append_token(t_token **list, char *str, int type);
void					free_token(t_token **list);

/* ---------- Env list ---------- */
int						free_list(t_envirement **list);
int						append(t_envirement **list, char *elem);
size_t					len_list(t_envirement *list);

/* ---------- Quotes ---------- */
void					quoting_choice(bool *dq, bool *sq, int *index, char c);
int						open_quote(t_data *data, char *line);
void					is_quoted(bool *dq, int *index, char *c);

/* ---------- Dollar Expansion ---------- */
int						exist_in_env(char *line, int *i, t_data *data);
char					*get_elem_env(t_envirement *env, char *key);
char					*get_dollar_word(char *line, int size);

int						add_dollar(char *line, int *index, char **str,
							t_data *data);
int						add_char(char *c, char **str, t_data *data, int *index);
int						replace_dollar(char **line, t_data *data);

/* ---------- Here Doc ---------- */
t_here					*global_her(t_here *status);
int						loop_here_doc(t_data *data);
int						here_doc(t_data *data, char *word);

#endif
