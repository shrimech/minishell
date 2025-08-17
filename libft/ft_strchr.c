/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:56:34 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/16 19:17:51 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	int	i;

	i = -1;
	while (string[++i])
		if (string[i] == (unsigned char)searchedChar)
			return ((char *)&string[i]);
	if (string[i] == (unsigned char)searchedChar)
		return ((char *)&string[i]);
	return (NULL);
}

// void main()
// {
// 	printf("%s\n", strchr("je cherche une lettre", 'e'));
// 	printf("%s\n", ft_strchr("je cherche une lettre", 'e'));
// 	char *f = NULL;
// 	printf("%d\n", (f || NULL));
// }