/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:41:27 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/21 17:14:33 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(t_pipex *p)
{
	if (p->fd1 >= 0)
		close(p->fd1);
	if (p->fd2 >= 0)
		close(p->fd2);
	if (p->pipe_fd[0] >= 0)
		close(p->pipe_fd[0]);
	if (p->pipe_fd[1] >= 0)
		close(p->pipe_fd[1]);
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

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}
