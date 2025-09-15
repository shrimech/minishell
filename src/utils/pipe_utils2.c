/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaissam <slaissam@.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 03:57:40 by slaissam          #+#    #+#             */
/*   Updated: 2025/08/23 04:31:03 by slaissam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	wait_all(int *pid, int n, t_data *data)
{
	int	status;
	int	j;

	j = 0;
	while (j < n)
	{
		waitpid(pid[j++], &status, 0);
		if (WIFEXITED(status))
			data->exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			if (WTERMSIG(status) == 2)
				write(1, "\n", 1);
			else if (WTERMSIG(status) == 3)
				write(2, "Quit (core dumped)\n", 20);
			data->exit_code = WTERMSIG(status) + 128;
		}
	}
}

int	prev_set_up(int a)
{
	static int	p;

	if (a == -500)
		return (p);
	p = a;
	return (a);
}
