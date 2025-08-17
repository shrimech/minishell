/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:13:16 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/16 13:15:21 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

void	print_token(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp->next != token)
	{
		printf("Type : %d, [%s]\n", tmp->type, tmp->str);
		tmp = tmp->next;
	}
	printf("Type : %d, [%s]\n",  tmp->type, tmp->str);
}

void	print_tab(char **tab)
{
	int	i;

	if (!(tab))
	{
		printf("NULL");
		return ;
	}
	i = 0;
	printf("[");
	while (tab[i])
	{
		printf("%s", tab[i]);
		if (tab[i + 1])
			printf(", ");
		i++;
	}
	printf("]");
}

void	print_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp->next != cmd)
	{
		printf("Skip -> %d, infile -> %d, outfile -> %d, cmd : ",
		tmp->skip_cmd, tmp->infile, tmp->outfile);
		print_tab(tmp->cmd_param);
		printf("\n");
		tmp = tmp->next;
	}
	printf("Skip -> %d, infile -> %d, outfile -> %d, cmd : ", tmp->skip_cmd,
		 tmp->infile, tmp->outfile);
	print_tab(tmp->cmd_param);
	printf("\n");
}
