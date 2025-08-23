/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:00:28 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/23 21:42:12 by mzangaro         ###   ########.fr       */
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

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd1;
	char	**cmd2;
	char	*path;
	char	*path2;
	int		fd1;
	int		fd2;
	int		pipe_fd[2];
}	t_pipex;

/* checks.c */
int		open_fds(t_pipex *p, char **argv);
void	close_one(int *fd);
void	close_fds(t_pipex *p);
int		check_args(int argc);
char	**free_array(char **split);
/* path.c */
char	**get_envp(char **envp);
char	*join_path(char *join, char *cmd);
char	*slash_in_cmd(char *cmd);
char	*find_path(char **envp, char *cmd);
char	*aux_find_path(char **split_path, char *cmd);
/* utils.c */
void	dup_child(t_pipex *p, int in_fd, int out_fd);
void	die(int code, char *path, char **cmd, const char *msg);
void	exec_child(char *path, char **cmd, char **envp);
void	init_child_1(char **argv, char **envp, t_pipex *p);
void	init_child_2(char **argv, char **envp, t_pipex *p);
/* main.c */
void	init_pipex(t_pipex *p);
int		main(int argc, char **argv, char **envp);

#endif