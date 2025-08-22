/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:41:27 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/22 21:03:45 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_fds(t_pipex *p, char **argv)
{
	if (!p)
		return (1);
	p->fd1 = open(argv[1], O_RDONLY);
	if (p->fd1 == -1)
		perror("infile");
	p->fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p->fd2 == -1)
		perror("outfile");
	if (p->fd1 == -1 || p->fd2 == -1)
	{
		close_one(&p->fd1);
		close_one(&p->fd2);
		return (1);
	}
	if (pipe(p->pipe_fd) == -1)
	{
		perror("pipe");
		close_one(&p->fd1);
		close_one(&p->fd2);
		return (1);
	}
	return (0);
}

void	close_one(int *fd)
{
	if (fd && *fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
}

void	close_fds(t_pipex *p)
{
	if (!p)
		return ;
	close_one(&p->fd1);
	close_one(&p->fd2);
	close_one(&p->pipe_fd[0]);
	close_one(&p->pipe_fd[1]);
}

int	check_args(int argc)
{
	if (argc != 5)
	{
		ft_putendl_fd("Usage: ./pipex infile cmd1 cmd2 outfile", 2);
		return (1);
	}
	else
		return (0);
}

char	**free_array(char **split)
{
	int	i;

	if (!split)
		return (NULL);
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}
