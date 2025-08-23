/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:23:36 by mzangaro          #+#    #+#             */
/*   Updated: 2025/08/23 22:10:35 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_envp(char **envp)
{
	char	**splited_path;
	char	*raw;
	int		i;

	i = 0;
	raw = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			raw = ft_strdup(envp[i] + 5);
			if (!raw)
				return (NULL);
			splited_path = ft_split(raw, ':');
			free(raw);
			return (splited_path);
		}
		i++;
	}
	return (NULL);
}

char	*join_path(char *join, char *cmd)
{
	char	*tmp;
	char	*out;

	if (!join || !cmd)
		return (NULL);
	tmp = ft_strjoin(join, "/");
	if (!tmp)
		return (NULL);
	out = ft_strjoin(tmp, cmd);
	free(tmp);
	return (out);
}

char	*slash_in_cmd(char *cmd)
{
	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	return (NULL);
}

char	*find_path(char **envp, char *cmd)
{
	char	*temp;
	int		i;

	if (!envp || !cmd || !cmd[0])
		return (NULL);
	i = 0;
	while (envp[i])
	{
		temp = join_path(envp[i], cmd);
		if (!temp)
			return (NULL);
		if (access(temp, X_OK) == 0)
			return (temp);
		free (temp);
		i++;
	}
	return (NULL);
}

char	*aux_find_path(char **split_path, char *cmd)
{
	char	*w_slash;
	char	*command;

	w_slash = slash_in_cmd(cmd);
	if (w_slash)
		return (w_slash);
	command = find_path(split_path, cmd);
	if (command)
		return (command);
	return (NULL);
}
