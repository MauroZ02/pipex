/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:52:11 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/22 21:02:46 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_child(t_pipex *p, int in_fd, int out_fd)
{
	if (dup2(in_fd, STDIN_FILENO) == -1)
	{
		perror("dup2 infile");
		exit(1);
	}
	if (dup2(out_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2 outfile");
		exit(1);
	}
	close_fds(p);
}

void	exec_child(t_pipex  *p, char **argv, char **envp)
{
	if (!p->path)
	{
		ft_putendl_fd("command not found", 2);
		exit(127);
	}
	if (access(p->path, F_OK) != 0)
	{
		perror("no such file");
		exit(127);
	}
	if (access(p->path, X_OK) != 0)
	{
		perror("permission");
		exit(126);
	}
	execve(p->path, argv, envp);
	perror("execve");
	exit(126);
}

void	init_child_1(char **argv, char **envp, t_pipex *p)
{
	char	**temp;

	dup_child(p, p->fd1, p->pipe_fd[1]);
	p->cmd1 = ft_split(argv[2], ' ');
	if (!p->cmd1 || !p->cmd1[0] || !p->cmd1[0][0])
	{
		if (p->cmd1)
			free_array(p->cmd1);
		ft_putendl_fd("first command not found", 2);
		exit (127);
	}
	temp = get_envp(envp,p);
	p->path = aux_find_path(temp, p->cmd1[0], p);
	if (temp)
		free_array(temp);
	exec_child(p->path, p->cmd1, envp);
}

void	init_child_2(char **argv, char **envp, t_pipex *p)
{
	char	**temp2;

	dup_child(p, p->pipe_fd[0], p->fd2);
	p->cmd2 = ft_split(argv[3], ' ');
	if (!p->cmd2 || !p->cmd2[0] || !p->cmd2[0][0])
	{
		if (p->cmd2)
			free_array(p->cmd2);
		ft_putendl_fd("second command not found", 2);
		exit (127);
	}
	temp2 = get_envp(envp, p);
	p->path2 = aux_find_path(temp2, p->cmd2[0], p);
	if (temp2)
		free_array(temp2);
	exec_child(p->path2, p->cmd2, envp);
}
