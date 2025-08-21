/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:00:28 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/20 22:58:28 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct pipex
{
	char	**cmd1;
	char	**cmd2;
	char	*path;
	char	*path2;
	int		fd1;
	int		fd2;
	int		pipe_fd[2];
	int		pid1;
	int		pid2;
}	t_pipex;

/* checks.c */
void	close_fds(t_pipex *p);
//int		check_args(int argc, char **argv, char **envp);
int		check_args(int argc);
char	**free_array(char **split);
/* utils.c */
int		open_fds(t_pipex *p, char **argv);
void	init_child_1(char **argv, char **envp, t_pipex *p);
void	init_child_2(char **argv, char **envp, t_pipex *p);
/* pipex.c */
//char	*find_path(char **envp, char *cmd);
char	**find_path(char **envp, t_pipex *p);
char	*aux_find_path(char *cmd, char **split_path, t_pipex *p);
int		main(int argc, char **argv, char **envp);

#endif