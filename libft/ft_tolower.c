/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:51:58 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/07 16:46:58 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
	}
	return (c);
}

/*int main (void)
{
	int	c;
	char	cast_c;

	c = ft_tolower('G'); // Store the result of ft_tolower in c
	
	cast_c = (char)c; // Cast c (int) to char so we can pass it to write
	
	write(1, &cast_c, 1);
	return(0);
}*/