/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaissam <slaissam@.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 02:41:59 by slaissam          #+#    #+#             */
/*   Updated: 2025/08/23 02:49:57 by slaissam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	check_buf(char *buf, char *word)
{
	if (!buf)
	{
		print_error("warning: here-document delimited by end-of-file ");
		print_error("(wanted '");
		print_error(word);
		print_error("')\n");
		return (false);
	}
	return (true);
}

char	*get_del(char *line)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] && is_space(line[i]))
		i++;
	j = i;
	while (line[j] && !is_space(line[j]))
		j++;
	dest = malloc(j - i + 1);
	ft_strlcpy(dest, line + i, j - i + 1);
	return (dest);
}

char	*h_name(void)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		exit(0);
	return (ft_strjoin("/tmp/", ft_itoa(pid)));
}
