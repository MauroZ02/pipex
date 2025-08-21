/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:18:07 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/07 16:47:42 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;
	size_t			i;

	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (cast_s1[i] != cast_s2[i])
		{
			return (cast_s1[i] - cast_s2[i]);
		}
		i++;
	}
	return (0);
}

/*int main (void)
{
	char s1[30] = "Hola Mundo";
	char s2[30] = "Hola a todos";
	int result;

	result = ft_memcmp(s1, s2, 8);
	if (result == 0)
	{
		write(1, "Equal\n", 6);
	}
	else 
	{
		write(1, "Not Equal\n", 10);
	}
	return 0;
}*/