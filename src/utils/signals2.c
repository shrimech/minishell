/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:14:04 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/22 21:05:22 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	signals2(void)
{
	signal(SIGQUIT, SIG_DFL);
}

void	handle_here_doc_sigint(int code)
{
	g_signal_pid = code;
	rl_done = 1;
	printf("\n");
	exit(130);
}
