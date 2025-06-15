/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 00:04:21 by shrimech          #+#    #+#             */
/*   Updated: 2025/06/15 05:22:08 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


t_env	*ft_lstnew_env(char *var, char *value)
{
	t_env	*lst;

	lst = malloc(sizeof(t_env));
	if (!lst)
		return (NULL);
	lst->var = var;
	lst->value = value;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back_env(t_env **envp, t_env *new)
{
	if (!*envp)
	{
		ft_lstadd_front_env(envp, new);
		return ;
	}
	ft_lstlast_env(*envp)->next = new;
}

void	ft_lstadd_front_env(t_env **envp, t_env *new)
{
	new->next = *envp;
	*envp = new;
}

t_env	*ft_lstlast_env(t_env *envp)
{
	if (!envp)
		return (NULL);
	while (envp->next != NULL)
		envp = envp->next;
	return (envp);
}