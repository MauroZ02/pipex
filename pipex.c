/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:51:04 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/21 22:10:23 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **envp, t_pipex *p)
{
	int		i;
	char	**split_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			p->path = ft_strdup(envp[i] + 5);
			break ;
		}
		i++;
	}
	if (envp[i] == NULL)
	{
		ft_putendl_fd("PATH not found in environment", 2);
		exit(127);
	}
	if (!p->path)
		exit (1);
	split_path = ft_split(p->path, ':');
	free(p->path);
	return (split_path);
}

char	*aux_find_path(char **split_path, char *cmd, t_pipex *p)
{
	char	*temp;
	int		i;

	if (ft_strchr(cmd, '/')){
		if (access(cmd, X_OK) == 0)
			return (free_array(split_path), ft_strdup(cmd));
		perror("execve");
		free_array(split_path);
		exit (126);
	}
	i = 0;
	while (split_path[i]){
		temp = ft_strjoin(split_path[i], "/");
		if (!temp)
			break ;
		p->path = ft_strjoin(temp, cmd);
		free (temp);
		if (!p->path)
			break ;
		if (access(p->path, X_OK) == 0)
			return (free_array(split_path), p->path);
		free (p->path);
		p->path = NULL;
		i++;
	}
	free_array(split_path);
	ft_putendl_fd("command not found", 2);
	exit(127);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	t_pipex	*p;

	pipex = (t_pipex){0};
	p = &pipex;
	if (check_args(argc) != 0)
		return (1);
	if (open_fds(p, argv) != 0)
		return (1);
	p->pid1 = fork();
	if (p->pid1 == -1)
		perror("pid1");
	if (p->pid1 == 0)
		init_child_1(argv, envp, p);
	p->pid2 = fork();
	if (p->pid2 == -1)
		perror("pid2");
	if (p->pid2 == 0)
		init_child_2(argv, envp, p);
	close_fds(p);
	wait(&p->pid1);
	wait(&p->pid2);
	return (0);
}
