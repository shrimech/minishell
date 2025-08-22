/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 19:04:09 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/22 09:02:49 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_envirement **lst, void (*del)(void *))
{
	t_envirement	*tmp;
	t_envirement	*next;

	next = *lst;
	while (next)
	{
		tmp = next;
		next = next->next;
		(*del)(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
