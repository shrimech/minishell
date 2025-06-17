/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:44:42 by shrimech          #+#    #+#             */
/*   Updated: 2025/06/17 00:42:07 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void cntr_c(int sig) {
    (void)sig;
    rl_on_new_line();
    rl_replace_line("", 0);
    write(1, "\n", 1);
    rl_redisplay();
}

void signal_handler(void)
{
    signal(SIGQUIT,SIG_IGN);
    signal(SIGINT,cntr_c);
}