/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 19:04:09 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/16 19:04:09 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

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
