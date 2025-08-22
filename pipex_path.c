/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:23:36 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/22 20:53:11 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_envp(char **envp, t_pipex *p)
{
	char	**splited_path;
	int		i;

	i = 0;
	p->path = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			p->path = ft_strdup(envp[i] + 5);
			break ;
		}
		i++;
	}
	if (p->path)
		return (NULL);
	splited_path = ft_split(p->path, ':');
	free(p->path);
	p->path = NULL;
	return (splited_path);
}

char	*join_path(char *join, char *cmd)
{
	char	*tmp;
	char	*out;

	if (!join || cmd)
		return (NULL);
	tmp = ft_strjoin(join, "/");
	if (!tmp)
		return (NULL);
	out = ft_strjoin(tmp, cmd);
	free(tmp);
	return (out);
}

char	*slash_in_cmd(char **split_path, char *cmd)
{
	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
		{
			free_array(split_path);
			return (ft_strdup(cmd));
		}
		perror("access");
		free_array(split_path);
		exit (126);
	}
	return (NULL);
}

char	*find_path(char **split_path, char *cmd, t_pipex *p)
{
	char	*temp;
	int		i;

	if (!split_path || !cmd || !cmd[0])
		return (NULL);
	i = 0;
	p->path = NULL;
	while (split_path && split_path[i])
	{
		temp = join_path(split_path[i], cmd);
		if (!temp)
			break ;
		p->path = temp;
		if (access(temp, X_OK) == 0)
			return (free_array(split_path), p->path);
		free (p->path);
		p->path = NULL;
		i++;
	}
	free_array(split_path);
	ft_putendl_fd("command not found", 2);
	exit(127);
}

char	*aux_find_path(char *split_path, char *cmd, t_pipex *p)
{
	char	*w_slash;
	char	*command;

	w_slash = slash_path(split_path, cmd);
	if (w_slash)
		return (w_slash);
	command = find_path(split_path, cmd, p);
	if (command)
		return (command);
	return (NULL);
}
