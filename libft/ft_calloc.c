/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:06:22 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/09 18:33:44 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(n * size);
	if (ptr == NULL)
		return (NULL);
	while (i < n * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

/* int main(void)
{
	char	*string;
	int		i;
	int		cant;

	cant = 5;
	string = ft_calloc(cant, sizeof(char));
	if (!string)
		return (printf("Fallé"), 1);
	i = 0;
	while (i < cant)
	{
		printf("%d\n", string[i]);
		i++;
	}
	free(string);
	return 0;
}

 */
/* 


0123456789ABCDEF

0x00000000000

FALSE
0 --> 0x000000000
'\0' --> 0x000000000
NULL --> 0x000000000 | (void *)0

TRUE




 */

	/*char *pito;
	char *ex;
	int i = 0;

	ex = "Mundo";
	pito = (char *) malloc(sizeof(char) * 5 + 1)
	while (i < size)
	{
		pito[i] = ex[i];
		i++;
	}
	while (i < size)
	{
		pito[i] = NULL;
		i++;
	}
	free(pito);*/