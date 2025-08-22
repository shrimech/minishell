/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:32:54 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/22 09:03:19 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_envirement_gnl
{
	char				*content;
	struct s_envirement_gnl	*next;
	struct s_envirement_gnl	*prev;
}						t_envirement_gnl;

int						free_list_gnl(t_envirement_gnl **list);
int						how_many(t_envirement_gnl *list, char **line);
int						make_line(t_envirement_gnl *list, char **line);
int						new_line(t_envirement_gnl *list);
int						add_to_list_gnl(t_envirement_gnl **list, char *buf);
int						write_in_list_gnl(int fd, t_envirement_gnl **list);
int						clear_list_gnl(t_envirement_gnl **list);
char					*get_next_line(int fd);

#endif
