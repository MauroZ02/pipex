/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:12:53 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/07 16:47:44 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cast_s;

	cast_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (cast_s[i] == (unsigned char)c)
			return (&cast_s[i]);
		i++;
	}
	return (NULL);
}

/*int main (void)
{
	char s[30] = "Hola Mundo";
	unsigned char c = 'M';
	char	*result;

	result = ft_memchr(s, c, 15);
	write(1, result, 1);
	return (0);
}*/