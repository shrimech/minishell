/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:08:53 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/16 19:05:41 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t			pos;
	unsigned char	*cs1;
	unsigned char	*cs2;

	pos = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	if (len == 0)
		return (0);
	while (pos < len - 1)
	{
		if (cs1[pos] != cs2[pos])
			return (cs1[pos] - cs2[pos]);
		pos++;
	}
	return (cs1[pos] - cs2[pos]);
}

// int main()
// {
// 	printf("%d\n", memcmp("Hello world", "Hello  ", 6));
// 	printf("%d\n", ft_memcmp("Hello world", "Hello  ", 6));
// }

// #include <string.h>

// int main ()
// {
// 	char s[] = {-128, 0, 127, 0};
// 	char sCpy[] = {-128, 0, 127, 0};
// 	char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};
// 	int	size = sizeof( int ) * 5;

// 	printf("ft : %d - n : %d\n", ft_memcmp(s, s2, 0), memcmp(s, s2, 0));
// 	printf("ft : %d - n : %d\n", ft_memcmp(s2, s, 1), memcmp(s2, s, 1));
// 	printf("ft : %d - n : %d\n", ft_memcmp(s2, s3, 4), memcmp(s2, s3, 4));
// }