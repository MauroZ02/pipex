/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:54:58 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/14 21:01:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (s == 0)
		return (NULL);
	substr = ft_calloc(len + 1, sizeof(char));
	if (substr == 0)
		return (NULL);
	ft_strlcpy(substr, (char *)s + start, len + 1);
	return (substr);
}

/*int main(void)
{
	char const *s = "Home la como esto";
	unsigned int start = 2;
	size_t len = 11;
	char *result = ft_substr(s, start, len);

	printf("substr: %s", result);
	return 0;
}*/