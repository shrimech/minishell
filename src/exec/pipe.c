#include "../../include/minishell.h"


void	redirect_in_out(t_cmd *cmd)
{
    if (cmd->fd_her >= 0)
    {
        dup2(cmd->fd_her, 0);
        close(cmd->fd_her);
    }
	if (cmd->infile >= 0)
	{
		dup2(cmd->infile, 0);
		close(cmd->infile);
	}
	if (cmd->outfile >= 0)
	{
		dup2(cmd->outfile, 1);
		close(cmd->outfile);
	}
}

void setupin(int prev)
{
    if (prev != -1)
    {
        dup2(prev, 0);
        close(prev);
    }
}

void setupout(t_cmd *current_cmd, t_data *data, int *fd)
{
    if (current_cmd->next != data->cmd)
    {
        dup2(fd[1], 1);
        close(fd[1]);
        close(fd[0]);
    }
}

void controlfds(int *prev, int *fd)
{
    if (*prev != -1)
        close(*prev);
    *prev = fd[0];
    close(fd[1]);
}

void	processall(t_data *data, t_cmd *cmd)
{
	char	*path;
	char	**env;

	path = NULL;
	if (cmd->skip_cmd)
		data->exit_code = 1;
	else if (is_builtin(cmd->cmd_param[0]))
			launch_builtin(data, cmd);
	else if (cmd_exist(&path, data, cmd->cmd_param[0]))
	{
		env = lst_to_arr(data->env);
		if (!env)
			free_all(data, ERR_MALLOC, EXT_MALLOC);
        redirect_in_out(cmd);
	    execve(path, cmd->cmd_param, env);
	    free(env);
	}
	if (path)
		free(path);
	free_all(data, NULL, data->exit_code);
}


int pipes(t_data *data)
{
    int i;
    int status;
    int prev;
    int fd[2];
    int *pid;

    i = 1;
    prev = -1;
    t_cmd *tmp;
    t_cmd *current_cmd;
    tmp = data->cmd;
    while (tmp->next != data->cmd)
    {
        i++;
        tmp = tmp->next;
    }
    pid = malloc(i * 4);
    current_cmd = data->cmd;
    int k = 0;
    while (k < i)
    {
        if (current_cmd->next != data->cmd && pipe(fd) == -1)
            perror("pipe");
        pid[k] = fork();
        if (pid[k] == -1)
            perror("fork");
        signal(SIGINT, SIG_IGN);
        if (pid[k] == 0)
        {
            signal(SIGINT, SIG_DFL);
            signal(SIGQUIT, SIG_DFL);
            setupin(prev);
            setupout(current_cmd, data, fd);
            processall(data, current_cmd);
        }
        controlfds(&prev, fd);
        k++;
        current_cmd = current_cmd->next;
    }
    close(prev);
    int j = 0;
    while(j < i)
    {
        waitpid(pid[j++], &status, 0);
        if (WIFEXITED(status))
	    {
            data->exit_code = WEXITSTATUS(status);
	    }
        else
        {
            data->exit_code = (WTERMSIG(status) + 128);
        }
    }
    signal(SIGINT, &handle_sigint);
    return (1);
}