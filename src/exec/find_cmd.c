/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:11:49 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/16 13:11:50 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

int	ft_strslashjoin(char *dest, char *str, char *env, int *index)
{
	int			i;
	int			j;

	i = 0;
	while (*index < (PATH_MAX - 1) && env[(*index)] && env[(*index)] != ':')
		dest[i++] = env[(*index)++];
	++(*index);
	dest[i++] = '/';
	j = 0;
	while (j < (PATH_MAX - 1) && str[j])
		dest[i++] = str[j++];
	dest[i] = '\0';
	return (0);
}

static char	*create_paths(t_list *env, int len)
{
	t_list	*tmp;

	tmp = env;
	while (len--)
	{
		if (ft_strncmp(tmp->str, "PATH=", 5) == 0)
			return (&(tmp->str[5]));
		tmp = tmp->next;
	}
	return (NULL);
}

static char	*cmd_not_found(char *sample)
{
	(void)sample;
	// write(2, sample, ft_strlen(sample));
	write(2, "blach : command not found\n", 27);
	return (NULL);
}

char	*find_cmd(t_data *data, char *sample, t_list *env)
{
	char		*paths;
	char		path[PATH_MAX];
	int			i;
	int			len;

	paths = create_paths(env, len_list(env));
	if (!paths || ft_strlen(sample) > PATH_MAX / 2)
		return (cmd_not_found(sample));
	i = 0;
	len = ft_strlen(paths);
	while (i < len)
	{
		ft_strslashjoin(path, sample, paths, &i);
		if (access(path, F_OK) == 0)
		{
			sample = ft_strdup(path);
			if (!sample)
			{
				print_error(ERR_MALLOC);
				data->exit_code = -1;
			}
			return (sample);
		}
	}
	return (cmd_not_found(sample));
}
