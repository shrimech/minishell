/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaissam <slaissam@.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:14:04 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/23 04:25:59 by slaissam         ###   ########.fr       */
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
	printf("\n");
	exit(130);
}
