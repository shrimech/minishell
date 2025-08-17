/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:06:31 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/16 19:06:40 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)destination;
	s = (unsigned char *)source;
	i = -1;
	while (++i < size)
		d[i] = s[i];
	return (destination);
}
// #include <stdio.h>
// #include "libft.h"
// #include <string.h>
// 
// int main() {
// 
// int array [] = { 54, 85, 20, 63, 21 };
// int * copy = NULL;
// int length = sizeof( int ) * 5;
//    
// /* Memory allocation and copy */
// copy = (int *) malloc( length );
// ft_memcpy( copy, array, length );
	// 
// /* Display the copied values */
// for( length=0; length<5; length++ ) {
	// printf( "%d ", copy[ length ] );
// }
// printf( "\n" );
	// 
// free( copy );
// 
// return EXIT_SUCCESS;
// }