/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 23:45:22 by shrimech          #+#    #+#             */
/*   Updated: 2025/06/15 05:40:11 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cmp(const char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (!s1[i])
		return (1);
	return (0);
}

void	old_pwd_check(char **str)
{
	if (ft_cmp(str[0], "OLDPWD"))
	{
		free(str[1]);
		str[1] = ft_strdup("");
	}
}

t_env	*convert_env(char **env)
{
	char	**str;
	int		i;
	t_env	*envp;
	t_env	*tmp;

	i = 0;
	str = NULL;
	envp = 0;
	while (env[i])
	{
		str = ft_split_env(env[i]);
		old_pwd_check(str);
		tmp = ft_lstnew_env(str[0], str[1]);
		ft_lstadd_back_env(&envp, tmp);
		free(str);
		i++;
	}
	return (envp);
}
