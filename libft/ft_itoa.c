/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:56:34 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/16 19:02:27 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nbr(int nbr)
{
	int				count;
	unsigned int	n;

	count = 1;
	if (nbr < 0)
	{
		n = -nbr;
		++count;
	}
	else
		n = nbr;
	while (n >= 10)
	{
		n /= 10;
		++count;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	t;

	i = count_nbr(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		t = -n;
	else
		t = n;
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = (t % 10) + 48;
		t /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

// int main()
// {
//     printf("%s\n", ft_itoa(-123456789));
//     printf("%s\n", ft_itoa(-2147483648));
//     printf("%s\n", ft_itoa(2147483647));
// }
