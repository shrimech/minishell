/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:11:11 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/22 09:02:49 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// syntax
static bool	syntax(char *str)
{
	int	i;

	if (str[0] != '_' && !ft_isalpha(str[0]))
		return (false);
	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

// checks if identifier already in env
static int	exist(char *str, t_envirement *env)
{
	int				i;
	int				j;
	t_envirement	*tmp;

	if (!env)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	j = 0;
	tmp = env;
	if (!ft_strncmp(tmp->str, str, i))
		return (j);
	tmp = tmp->next;
	j++;
	while (tmp != env)
	{
		if (!ft_strncmp(tmp->str, str, i))
			return (j);
		tmp = tmp->next;
		j++;
	}
	return (-1);
}

// static bool	unset(char *str, t_envirement **env)
//{
//	int		pos;
//	int		i;
//	t_envirement	**tmp;

//	if (!str || !(*str))
//		return (false);
//	if (!syntax(str))
//	{
//		print_error("unset: invalid identifier\n");
//		return (true);
//	}
//	pos = exist(str, (*env));
//	if (pos == -1)
//		return (false);
//	tmp = env;
//	i = 0;
//	while (i++ < pos)
//		(*env) = (*env)->next;
//	(*env)->prev->next = (*env)->next;
//	(*env)->next->prev = (*env)->prev;
//	free((*env)->str);
//	free((*env));
//	(*env) = NULL;
//	env = tmp;
//	return (false);
//}

static void	check_env(t_envirement *tmp, t_envirement **env)
{
	if (tmp == (*env))
		(*env) = tmp->next;
	if (tmp->next == tmp)
		(*env) = NULL;
}

static bool	unset(char *str, t_envirement **env)
{
	int				pos;
	int				i;
	t_envirement	*tmp;

	if (!str || !(*str))
		return (false);
	if (!syntax(str))
	{
		print_error("unset: invalid identifier\n");
		return (true);
	}
	pos = exist(str, (*env));
	if (pos == -1)
		return (false);
	tmp = (*env);
	i = 0;
	while (i++ < pos)
		tmp = tmp->next;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	free(tmp->str);
	check_env(tmp, env);
	free(tmp);
	tmp = NULL;
	return (false);
}

int	ft_unset(char **str, t_envirement **env)
{
	int	exit_code;
	int	i;

	exit_code = 0;
	i = 0;
	while (str[i])
	{
		if (unset(str[i], env))
			exit_code = 1;
		i++;
	}
	return (exit_code);
}
