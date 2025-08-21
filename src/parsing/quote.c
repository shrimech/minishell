/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:12:57 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/16 13:12:58 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void is_quoted(bool *dq, int *index, char *c)
{
	while (c[*index])
	{
		if (c[*index] == '\'' || c[*index] == '"')
			*dq = true;
		(*index)++;
	}
}

void quoting_choice(bool *dq, bool *sq, int *index, char c)
{
	if ((c == '\'' || c == '"') && !*sq && !*dq)
	{
		if (c == '\'' && !*dq)
			*sq = true;
		else if (c == '"' && !*sq)
			*dq = true;
		if (index)
			++(*index);
	}
	else if ((c == '\'' || c == '"'))
	{
		if (c == '\'' && !*dq && *sq)
			*sq = false;
		else if (c == '"' && !*sq && *dq)
			*dq = false;
		if (index)
			++(*index);
	}
}

int open_quote(t_data *data, char *line)
{
	bool dq;
	bool sq;
	int i;

	i = 0;
	dq = false;
	sq = false;
	while (line && line[i])
	{

		quoting_choice(&dq, &sq, &i, line[i]);
		if (line[i] && line[i] != '\'' && line[i] != '"')
			++i;
	}
	if (dq || sq)
	{
		print_error("open quote\n");
		data->exit_code = 2;
		return (1);
	}
	return (0);
}
