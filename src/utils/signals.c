/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:13:57 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/16 13:13:58 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

void	clear_rl_line(void)
{
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	handle_here_doc_sigint(int code)
{
	g_signal_pid = code;
	rl_done = 1;
	printf("\n");
	exit(130);
}

void	handle_sigint(int code)
{
	g_signal_pid = code ;
	clear_rl_line();
	printf("\n");
	rl_redisplay();
}

static void	handle_sigsegv(int code)
{
	g_signal_pid = code ;
	write(2, "Segmentation fault\n", 19);
	exit(11);
}

static void	handle_sigabrt(int code)
{
	g_signal_pid = code ;
	write(1, "abort\n", 6);
}

void	signals(t_data **data)
{
	(void)data;
	signal(SIGINT, &handle_sigint);
	signal(SIGSEGV, &handle_sigsegv);
	signal(SIGABRT, &handle_sigabrt);
	signal(SIGQUIT, SIG_IGN);
}
