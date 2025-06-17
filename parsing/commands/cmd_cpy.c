/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 03:25:24 by shrimech          #+#    #+#             */
/*   Updated: 2025/06/17 03:52:30 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_command	*convert_cmd(char **command_line)
{
	char	**str;
	int		i;
    int j;
	t_command	*command;
	t_command	*tmp;

	i = 0;
	str = NULL;
	command = 0;
	while (command_line[i])
	{
		str = ft_split(command_line[i],' ');
        j = 0;
        while(str[j])
        {
            tmp = ft_lstnew_cmd(str[j]);
            ft_lstadd_back_cmd(&command, tmp);
        }
		tmp = ft_lstnew_env(str[0], str[1]);
		free(str);
		i++;
	}
	return (command);
}

//echo -n salah