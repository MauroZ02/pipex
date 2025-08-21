/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:21:51 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/15 14:34:20 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (!s[i])
			return (words);
		while (s[i] != c && s[i] != '\0')
			i++;
		words++;
	}
	return (words);
}

int	ft_count_letters(char const *s, char c, int j)
{
	int	i;

	i = 0;
	while ((s[j] != '\0') && (s[j] != c))
	{
		i++;
		j++;
	}
	return (i);
}

char	**free_split(char	**split)
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

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**split;
	int		words;
	int		j;

	if (!s)
		return (NULL);
	words = ft_countwords((char *)s, c);
	split = ft_calloc(words + 1, sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (words-- != 0)
	{
		while (s[j] && s[j] == c)
			j++;
		split[i] = ft_substr(s, j, ft_count_letters(s, c, j));
		if (!split[i])
			return (free_split(split));
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	return (split);
}

/*int main(void)
{
	char *s = "holas comos estas";
	char c = ' ';
	int i = 0;
	char **p = ft_split(s, c);
	while(p[i])
	{
		printf("p -->%s\n", p[i]);
		i++;
	}
	return 0;
}*/
