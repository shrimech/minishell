/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:51:51 by shrimech          #+#    #+#             */
/*   Updated: 2025/06/03 11:53:52 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PARSING_H
#define PARSING_H

typedef struct s_command
{
    char    *word;
    int     flag;
    struct s_command *next;
}   t_command;


#endif