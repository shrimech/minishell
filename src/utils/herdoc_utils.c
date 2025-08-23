/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:17:01 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/23 01:01:12 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_here	*global_her(t_here *status)
{
	static t_here	*value;

	if (status == NULL)
		return (value);
	value = status;
	return (value);
}

t_here	*he_creat_node(char *del, int flag)
{
	t_here	*node;

	node = malloc(sizeof(t_here));
	if (!node)
		return (NULL);
	node->del = del;
	node->index = flag;
	node->next = NULL;
	return (node);
}

t_here	*ft_lstlast(t_here *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	he_lstadd_back(t_here **lst, t_here *new)
{
	t_here	*tmp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ft_lstlast(*lst);
			tmp->next = new;
		}
	}
}

void	ft_delimitre(char *line)
{
	char	*del;
	t_here	*herdoc;
	int		flag;
	int		i;
	t_here	*node;

	herdoc = NULL;
	flag = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '<' && line[i + 1] == '<')
		{
			del = get_del(line + i + 2);
			flag++;
			node = he_creat_node(del, flag);
			he_lstadd_back(&herdoc, node);
		}
		i++;
	}
	global_her(herdoc);
}
