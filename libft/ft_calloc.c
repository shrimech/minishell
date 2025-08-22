/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 2:56:36 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/16 18:58:06 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*tmp;

	if (count != 0 && size != 0 && size > 2147483647 / count)
		return (NULL);
	i = -1;
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (++i < count * size)
		tmp[i] = 0;
	return (tmp);
}
