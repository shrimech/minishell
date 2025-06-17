/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:51:51 by shrimech          #+#    #+#             */
/*   Updated: 2025/06/17 03:31:10 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PARSING_H
#define PARSING_H

typedef struct s_flags
{
    int ENTER_DOUBL;
    int ENTER_SINGL;
    int ONE_DOUBL;
    int ONE_SINGL;
    int CMD;
    int OPTION;
    int WORD;
    int R_RED;
    int L_RED;
    int HERDOC;
    int PIP;
}   t_flags;

typedef struct s_env
{
	char				*var;
	char				*value;
	struct s_env		*next;
}						t_env;

typedef struct s_command
{
    char    *word;
    int     flag;
    struct s_command *next;
}   t_command;

t_env	*convert_env(char **env);
char	**ft_split_env(char *env);
t_env	*ft_lstnew_env(char *var, char *value);
void	ft_lstadd_back_env(t_env **envp, t_env *new);
void	ft_lstadd_front_env(t_env **lst, t_env *new);
t_env	*ft_lstlast_env(t_env *lst);
t_command	*convert_cmd(char **splited);




// ------------   signals   -------------------------------------
void signal_handler(void);



#endif