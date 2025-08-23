/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:52:11 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/23 22:36:19 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_child(t_pipex *p, int in_fd, int out_fd)
{
	if (dup2(in_fd, STDIN_FILENO) == -1)
	{
		perror("dup2 infile");
		close_fds(p);
		exit(1);
	}
	if (dup2(out_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2 outfile");
		close_fds(p);
		exit(1);
	}
	close_fds(p);
}

void	die(int code, char *path, char **cmd, const char *msg)
{
	if (msg)
		perror(msg);
	if (path)
		free(path);
	if (cmd)
		free_array(cmd);
	exit(code);
}

void	exec_child(char *path, char **cmd, char **envp)
{
	if (!cmd || !cmd[0] || !cmd[0][0])
		die(127, NULL, cmd, NULL);
	if (!path)
		die(127, NULL, cmd, NULL);
	if (access(path, X_OK) != 0)
	{
		if (access(path, F_OK) != 0)
			die(127, path, cmd, "execve");
		die(126, path, cmd, "execve");
	}
	execve(path, cmd, envp);
	die(126, path, cmd, "execve");
}

void	init_child_1(char **argv, char **envp, t_pipex *p)
{
	char	**temp;
	char	*full_path;

	dup_child(p, p->fd1, p->pipe_fd[1]);
	p->cmd1 = ft_split(argv[2], ' ');
	if (!p->cmd1 || !p->cmd1[0] || !p->cmd1[0][0])
	{
		if (p->cmd1)
			free_array(p->cmd1);
		ft_putendl_fd("first command not found", 2);
		exit (127);
	}
	temp = get_envp(envp);
	full_path = aux_find_path(temp, p->cmd1[0]);
	if (temp)
		free_array(temp);
	p->path = full_path;
	exec_child(full_path, p->cmd1, envp);
}

void	init_child_2(char **argv, char **envp, t_pipex *p)
{
	char	**temp2;
	char	*full_path2;

	dup_child(p, p->pipe_fd[0], p->fd2);
	p->cmd2 = ft_split(argv[3], ' ');
	if (!p->cmd2 || !p->cmd2[0] || !p->cmd2[0][0])
	{
		if (p->cmd2)
			free_array(p->cmd2);
		ft_putendl_fd("second command not found", 2);
		exit (127);
	}
	temp2 = get_envp(envp);
	full_path2 = aux_find_path(temp2, p->cmd2[0]);
	if (temp2)
		free_array(temp2);
	p->path = full_path2;
	exec_child(full_path2, p->cmd2, envp);
}
