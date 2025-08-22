/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:56:34 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/16 19:05:11 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	size_t			pos;
	unsigned char	*tmp;

	tmp = (unsigned char *)memoryBlock;
	pos = -1;
	while (++pos < size)
		if (tmp[pos] == (unsigned char)searchedChar)
			return (&(tmp[pos]));
	return (NULL);
}

// #include <stdio.h>
// #include "libft.h"
// #include <string.h>

// int main() {

//     char data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
//     const unsigned int size = 10;

//     // On recherche une valeur inhéxistante :
//     void * found = ft_memchr( data, 57, size );
//     printf( "57 is %s\n", ( found != NULL ? "found" : "not found" ) );

//     // On recherche une valeur existante :
//     found = ft_memchr( data, 50, size );
//     printf( "50 is %s\n", ( found != NULL ? "found" : "not found" ) );
//     if ( found != NULL )
//		{
//         printf( "La valeur à la position calculée est %d\n",
//		*((char *) found) );
//     }

//     return (EXIT_SUCCESS);
// }