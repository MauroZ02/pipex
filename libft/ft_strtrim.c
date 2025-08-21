/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:11:44 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/14 21:51:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*trim;
	size_t	len_substr;

	i = 0;
	j = ft_strlen(s1);
	if (!s1)
		return (NULL);
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[j]))
		j--;
	if (j < i)
		return (NULL);
	len_substr = j - i + 1;
	trim = ft_substr(s1, i, len_substr);
	return (trim);
}

/*int main(void)
{
	char *s1 = "!_(hola!__(";
	char *set = "!_(";
	char *result;

	result = ft_strtrim(s1, set);
	printf("string without set: %s\n", result);
	free (result);
	return 0;
}*/