/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:52:11 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/21 22:30:11 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_fds(t_pipex *p, char **argv)
{
	if (p != NULL)
	{
		p->fd1 = open(argv[1], O_RDONLY);
		if (p->fd1 == -1)
			perror("infile");
		p->fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (p->fd2 == -1)
			perror("outfile");
		if (p->fd1 == -1 || p->fd2 == -1)
			return (1);
		if (pipe(p->pipe_fd) == -1)
			return (perror("pipe"), 1);
		return (0);
	}
	else
		return (1);
}

void	init_child_1(char **argv, char **envp, t_pipex *p)
{
	char	**temp;

	if (dup2(p->fd1, STDIN_FILENO) == -1
		||dup2(p->pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup first child");
		exit (1);
	}
	close_fds(p);
	p->cmd1 = ft_split(argv[2], ' ');
	if (!p->cmd1 || !p->cmd1[0] || !p->cmd1[0][0])
	{
		ft_putendl_fd("first command not found", 2);
		if (p->cmd1)
			free_array(p->cmd1);
		exit (127);
	}
	temp = find_path(envp, p);
	p->path = aux_find_path(temp, p->cmd1[0], p);
	if (!p->path){
		ft_putendl_fd("first command not found", 2);
		free_array(p->cmd1);
		exit(127);
	}
	execve(p->path, p->cmd1, envp);
	perror("execve");
	free(p->path);
	free_array(p->cmd1);
	exit (126);
}

void	init_child_2(char **argv, char **envp, t_pipex *p)
{
	char	**temp;

	if (dup2(p->pipe_fd[0], STDIN_FILENO) == -1
		|| dup2(p->fd2, STDOUT_FILENO) == -1)
	{
		perror("dup second child");
		exit (1);
	}
	close_fds(p);
	p->cmd2 = ft_split(argv[3], ' ');
	if (!p->cmd2 || !p->cmd2[0] || !p->cmd2[0][0])
	{
		ft_putendl_fd("second command not found", 2);
		if (p->cmd2)
			free_array(p->cmd2);
		exit (127);
	}
	temp = find_path(envp, p);
	p->path2 = aux_find_path(temp, p->cmd2[0], p);
	if (!p->path2) {
		ft_putendl_fd("second command not found", 2);
		free_array(p->cmd2);
		exit(127);
	}
	execve(p->path2, p->cmd2, envp);
	perror("execve");
	free(p->path2);
	free_array(p->cmd2);
	exit (126);
}
