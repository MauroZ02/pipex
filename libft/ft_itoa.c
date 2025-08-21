/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:11:44 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/15 13:21:59 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizeint(int n)
{
	int	cont;

	cont = 1;
	while ((n / 10) != 0)
	{
		cont++;
		n = n / 10;
	}
	return (cont);
}

char	*ft_itoa(int n)
{
	char			*str_num;
	size_t			size_n;
	unsigned int	num;

	num = n;
	size_n = ft_sizeint(n);
	if (n < 0)
	{
		num *= -1;
		size_n++;
	}
	str_num = ft_calloc(size_n + 1, sizeof(char));
	if (!str_num)
		return (NULL);
	str_num[size_n] = '\0';
	while (size_n--)
	{
		str_num[size_n] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str_num[0] = '-';
	return (str_num);
}

/*int main()
{
	int n = 435967;
	printf("result: %s", ft_itoa(n));
}*/