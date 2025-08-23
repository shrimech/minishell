/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:16:11 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/23 01:00:12 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	make_env(t_data *data, char **env)
{
	t_envirement	*list;
	int				i;
	char			*tmp;

	if (!(*env))
		return (make_env2(data));
	i = -1;
	list = NULL;
	while (env[++i])
	{
		tmp = ft_strdup(env[i]);
		if (!tmp)
			return (free_list(&list));
		if (!append(&list, tmp))
			return (free_list(&list));
	}
	data->env = list;
	return (1);
}

void	init_data(t_data *data, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	data->env = NULL;
	data->token = NULL;
	data->cmd = NULL;
	data->pip[0] = -1;
	data->pip[1] = -1;
	g_signal_pid = 0;
	signals(&data);
}

char	*get_del(char *line)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] && is_space(line[i]))
		i++;
	j = i;
	while (line[j] && !is_space(line[j]))
		j++;
	dest = malloc(j - i + 1);
	ft_strlcpy(dest, line + i, j - i + 1);
	return (dest);
}
