/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:09:14 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/07 16:48:24 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*cast_s;

	i = 0;
	cast_s = (char *)s;
	while (i < n)
	{
		cast_s[i] = 0;
		i++;
	}
}

/*int main(void)
{
	char	str[30] = "Hola Mundo";
	ft_bzero(str, 5);
	write(1, str, 30);
	return(0);
}*/