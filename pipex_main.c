/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:51:04 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/22 19:24:35 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *p)
{
	p->cmd1 = NULL;
	p->cmd2 = NULL;
	p->path = NULL;
	p->path2 = NULL;
	p->fd1 = -1;
	p->fd2 = -1;
	p->pid1 = -1;
	p->pid2 = -1;
	p->pipe_fd[0] = -1;
	p->pipe_fd[1] = -1;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;
	int		st1;
	int		st2;

	init_pipex(&p);
	if (check_args(argc) != 0 || open_fds(&p, argv) != 0)
		return (1);
	p.pid1 = fork();
	if (p.pid1 == -1)
		return (perror("pid1"), close_fds(&p), 1);
	if (p.pid1 == 0)
		init_child_1(argv, envp, &p);
	p.pid2 = fork();
	if (p.pid2 == -1)
		return (perror("pid2"), close_fds(&p), 1);
	if (p.pid2 == 0)
		init_child_2(argv, envp, &p);
	close_fds(&p);
	waitpid(p.pid1, &st1, 0);
	waitpid(p.pid2, &st2, 0);
	return (WEXITSTATUS(st2));
}
