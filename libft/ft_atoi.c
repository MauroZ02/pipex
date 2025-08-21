/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:16:45 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/14 20:28:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	ft_atoi(const char *nptr)
{
	int	i;
	int	negative;
	int	convert;

	i = 0;
	negative = 1;
	convert = 0;
	while (nptr[i] != '\0')
	{
		if (!(nptr[0] == '-' || nptr[0] == '+' || (nptr[0] >= '0'
					&& nptr[i] <= '9')))
			return (0);
		if (nptr[i] == '-' || nptr[i] == '+')
		{
			if (nptr[i] == '-')
				negative = -1;
			i++;
		}
		if (nptr[i] >= '0' && nptr[i] <= '9')
			convert = (convert * 10) + (nptr[i] - '0');
		else
			return (0);
		i++;
	}
	return (convert * negative);
}*/

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		sign;
	int		num;

	str = (char *)nptr;
	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str < '0' || *str > '9')
		str--;
	while ((*str >= '0' && *str <= '9'))
		num = (num * 10) + (*str++) - '0';
	return (num * sign);
}

/*#include <string.h>

int main ()
{
	char	nptr[] = "-77r7";
	printf("atoi: %d\n", atoi(nptr));
	printf("ft_atoi: %d\n", ft_atoi(nptr));
	return 0;
}*/