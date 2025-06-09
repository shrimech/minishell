/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaissam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:02:33 by slaissam          #+#    #+#             */
/*   Updated: 2025/06/07 19:02:33 by slaissam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char *)malloc(ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*y;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	y = (char *)malloc(len + 1);
	if (!y)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		y[i] = s[start];
		i++;
		start++;
	}
	y[i] = 0;
	return (y);
}

static size_t	counting(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	start_end(char *s, size_t *i, size_t *j, char c)
{
	*j = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	while (s[*i + *j] && s[*i + *j] != c)
		(*j)++;
}

static char	**ft_free(char **r, size_t l)
{
	size_t	i;

	i = 0;
	while (l > i)
	{
		free(r[i]);
		i++;
	}
	free(r);
	return (0);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	l;
	size_t	count;
	char	**r;

	i = 0;
	l = 0;
	count = counting(s, c);
	r = (char **)malloc((count + 1) * sizeof(char *));
	if (r == 0)
		return (0);
	while (l < count)
	{
		start_end(s, &i, &j, c);
		r[l] = ft_substr(s, i, j);
		if (r[l] == 0)
			return (ft_free(r, l));
		i = i + j;
		l++;
	}
	r[count] = 0;
	return (r);
}
