/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:26:28 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/09 22:56:25 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*result;

	i = 0;
	len = ft_strlen(s);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (0);
	while (i < len)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
// Function that matches the expected signature for ft_strmapi
/*char my_toupper(unsigned int index, char c)
{
    (void)index;  // Ignore the index if you don't need it
    if (c >= 'a' && c <= 'z')
        return (c - 32);  // Convert lowercase to uppercase
    return c;
}
int main (void)
{

    const char *s = "hola p4to 54";
    char *result = ft_strmapi(s, my_toupper);

    if (result != NULL) {
        printf("result: %s\n", result);  // Print the transformed string
        free(result);  // Free the allocated memory to prevent memory leaks
    } else {
        printf("Error: Memory allocation failed.\n");
    }
    return 0;
}*/