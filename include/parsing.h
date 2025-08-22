/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:25:06 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/22 09:25:08 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "defines.h"
# include <stdbool.h>
# include <stdlib.h>

/* ---------- Structures ---------- */
typedef struct s_token
{
    char            *str;
    int             type;
    bool            quoted;
    struct s_token  *prev;
    struct s_token  *next;
}   t_token;

typedef struct s_list
{
    char            *str;
    struct s_list   *prev;
    struct s_list   *next;
}   t_envirement;

typedef struct s_here
{
    char            *del;
    int             index;
    int             pipe;
    struct s_here   *next;
}   t_here;

/* ---------- Functions ---------- */
// tokens
bool    create_list_token(t_token **begin, char *command);
int     append_token(t_token **list, char *str, int type);
void    free_token(t_token **list);

// env list
int     free_list(t_envirement **list);
int     append(t_envirement **list, char *elem);
size_t  len_list(t_envirement *list);

// quote
void    quoting_choice(bool *dq, bool *sq, int *index, char c);
int     open_quote(void *data, char *line); // using t_data in minishell.h

// dollar env
int     exist_in_env(char *line, int *i, void *data);
char    *get_elem_env(t_envirement *env, char *key);
char    *get_dollar_word(char *line, int size);

// dollar replace
int     add_dollar(char *line, int *index, char **str, void *data);
int     add_char(char *c, char **str, void *data, int *index);
int     replace_dollar(char **line, void *data);

// here_doc
t_here  *global_her(t_here *status);
int     loop_here_doc(void *data);
int     here_doc(void *data, char *word);
void    handle_here_doc_sigint(int code);

#endif
