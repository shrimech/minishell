/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:56:34 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/16 19:25:32 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	int	i;

	i = 0;
	while (string[i])
		++i;
	if (searchedChar == 0)
		return ((char *)&string[i]);
	while (--i >= 0)
		if (string[i] == (unsigned char)searchedChar)
			return ((char *)&string[i]);
	return (NULL);
}

// int main(void)
// {
// 	printf("%s\n", ft_strrchr("je cherche une lettre", 'e'));
// 	printf("%s\n", strrchr("je cherche une lettre", 'e'));
// 	return (0);
// }
