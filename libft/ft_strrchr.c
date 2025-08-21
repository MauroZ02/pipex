/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:06:14 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/15 14:18:33 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_occurrence;

	last_occurrence = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			last_occurrence = (char *)&s[i];
		}
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (last_occurrence);
}

/*int main(void)
{
	const char *s = "Hola Mundano";
	int c = 'z';
	char *result = ft_strrchr(s, c);

	if (result != NULL)
		write (1, result, 1);
	else 
		write(1, "Not Found\n", 10);
	return (0);
}
*/