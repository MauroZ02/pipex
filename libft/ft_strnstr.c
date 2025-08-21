/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:34:38 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/07 16:47:06 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
	{
		return ((char *)big);
	}
	while ((big[i] != '\0') && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*int main(void)
{
    const char big[] = "Hello, welcome to the test!";
    const char little[] = "welcome";
    char *result;

    result = ft_strnstr(big, little, 20);

    if (result != NULL)
    {
        write(1, result, 20);
		write(1, "\n", 1);
    }
    else
    {
        write(1, "Not found\n", 10);
    }

    return 0;
}*/