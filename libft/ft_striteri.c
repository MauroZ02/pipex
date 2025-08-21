/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:10:01 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/15 12:36:28 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// // Function that matches the expected signature for ft_striteri
// void my_toupper(unsigned int index, char *c)
// {
//     (void)index;  // Ignore the index if you don't need it
//     if (*c >= 'a' && *c <= 'z')  // Check if the character is lowercase
//         *c = *c - 32;  //to uppercase (modifying the character in place)
// }
// int main(void)
// {

//     char s[] = "hola p4to 54";  // Use a modifiable character array

//     // Call ft_striteri to modify the string in place
//     ft_striteri(s, my_toupper);

//     printf("result: %s\n", s);  // Print the modified string

//     return 0;
// }