/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:16:13 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/14 21:11:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*join;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!join)
		return (NULL);
	if (!s1 || !s2)
		return (NULL);
	ft_strlcpy(join, (char *)s1, len1 + 1);
	ft_strlcat(join, s2, len1 + len2 + 1);
	return (join);
}

/*int main()
{
	const char *s1 = "Hola ";
	const char *s2 = "mundo";
	char *result;

	result = ft_strjoin(s1, s2);
	printf("str_join: %s\n", result);
	free(result);
	return 0;
}*/
