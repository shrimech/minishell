/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:14:16 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/19 12:36:32 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/minishell.h"

pid_t	g_signal_pid;

int	make_env(t_data *data, char **env)
{
	t_list	*list;
	int		i;
	char	*tmp;

	if (!(*env))
		return (make_env2(data));
	i = -1;
	list = NULL;
	while (env[++i])
	{
		tmp = ft_strdup(env[i]);
		if (!tmp)
			return (free_list(&list));
		if (!append(&list, tmp))
			return (free_list(&list));
	}
	data->env = list;
	return (1);
}

void	init_data(t_data *data, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	data->env = NULL;
	data->token = NULL;
	data->cmd = NULL;
	data->exit_code = 0;
	data->pip[0] = -1;
	data->pip[1] = -1;
	g_signal_pid = 0;
	signals(&data);
}

bool	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (i == (int)ft_strlen(line))
	{
		free(line);
		return (true);
	}
	return (false);
}


t_here *global_her(t_here *status)
{
	static t_here *value;
	if (status == NULL)
		return (value);
	value = status;
	return (value);
}
char  	*get_del(char *line)
{
	int i = 0, j = 0;
	while (line[i] && is_space(line[i]))
		i++;
	j = i;
	while (line[j] && !is_space(line[j]))
		j++;
	char *dest = malloc(j-i+1);
	ft_strlcpy(dest,line +i, j - i + 1);
	return(dest);
}

t_here *he_creat_node(char *del, int flag)
{
	t_here *node;
	if (!(node = malloc(sizeof(t_here))))
		return (NULL);
	node->del = del;
	node->index = flag;
	node->next = NULL;
	return (node);
}
t_here	*ft_lstlast(t_here *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
void	he_lstadd_back(t_here **lst, t_here *new)
{
	t_here	*tmp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ft_lstlast(*lst);
			tmp -> next = new;
		}
	}
}

void ft_delimitre(char *line)
{
	char *del;
	t_here *herdoc = NULL;
	int flag = 0;
	int i = 0;
	while (line[i])
	{
		if (line[i] == '<' && line[i + 1] == '<')
		{
			del = get_del(line + i + 2);
			flag++;
			t_here	*node = he_creat_node(del, flag);
			he_lstadd_back(&herdoc, node);
		}
		i++;
	}
	global_her(herdoc);
	// while (herdoc)
	// {
	// 	printf("i %d  del %s\n", herdoc->index, herdoc->del);
	// 	herdoc = herdoc->next;
	// }
	// exit(1);
}

bool	parseline(t_data *data, char *line)
{
	ft_delimitre(line);
	if (open_quote(data, line))
	{
		free(line);
		return (false);
	}
	// printf("%s",line);
	if (!replace_dollar(&line, data) || !create_list_token(&data->token, line))
	{
		free(line);
		free_all(data, ERR_MALLOC, EXT_MALLOC);
	}
	// free(line);
	// print_token(data->token);
	if (data->token && (data->token->prev->type == PIPE || data->token->type == PIPE))
	{
		write(2, "Error: syntax error near unexpected token '|'\n", 46);
		data->exit_code = 2;
		free_token(&data->token);
		return (false);
	}
	// printf("%s\n",line);
	if (!data->token || !create_list_cmd(data))
	{
		free_token(&data->token);
		free_cmd(&data->cmd);
		return (false);
	}
	// if(data->fd > 0 && data->token->prev->prev->type ==HEREDOC)
		// data->cmd->prev->infile = data->fd;
	data->fd = loop_here_doc(data);
	if (data->fd == -5)
		return (false);
	return (check_pipe(data));
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	char	*line;

	while (1)
	{
		init_data(&data, argc, argv);
		if (!make_env(&data, env))
			free_all(&data, ERR_MALLOC, EXT_MALLOC);
		line = readline("minishell> ");
		if (g_signal_pid != 0)
			data.exit_code = 128 + g_signal_pid;
		if (!line)
			free_all(&data, "exit\n", data.exit_code);
		if (empty_line(line))
		continue ;
		add_history(line);
		if (!parseline(&data, line))
		{
			free_all(&data,NULL,-1);
			continue ;
		}
		if (is_builtin(data.cmd->cmd_param[0]))
			launch_builtin(&data, data.cmd);
		else if (!pipes(&data))
			free_all(&data, ERR_PIPE, EXT_PIPE);
		free_cmd(&data.cmd);
		free_token(&data.token);
		g_signal_pid = 0;

	}
	rl_clear_history();
	free_all(&data, NULL, -1);
	return (0);
}
