/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:11:22 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/17 01:59:52 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	almost_atoi(char *str, int *err)
{
	unsigned long long	num;
	int					i;
	int					j;
	int					sign;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	j = i;
	num = 0;
	while ('0' <= str[i] && str[i] <= '9')
		num = num * 10 + (str[i++] - 48);
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] || i - j > 20 || ((sign == -1 && (num - 1) > LONG_MAX)
			|| (sign == 1 && (num > LONG_MAX))))
		*err = 1;
	return ((int)((num * sign) % 256));
}

void	ft_exit(t_data *data, char **args)
{
	int	ret;
	int	err;

	ret = 0;
	err = 0;
	if (args[1])
	{
		ret = almost_atoi(args[1], &err);
		if (err)
		{
			print_error("exit: ");
			print_error(args[1]);
			print_error(": numeric argument required\n");
			free_all(data, NULL, 2);
		}
	}
	if (args[1] && args[2])
	{
		print_error("exit: too many arguments\n");
		data->exit_code = 1;
		return ;
	}
	if (!args[1])
		free_all(data, NULL, data->exit_code);
	free_all(data, NULL, ret);
}
