/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:20:23 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/14 20:42:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_non_overlapping(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

static void	*ft_overlapping(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		dest[i - 1] = src[i - 1];
		i--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cast_dest;
	char	*cast_src;

	cast_dest = (char *)dest;
	cast_src = (char *)src;
	if (n == 0)
	{
		return (cast_dest);
	}
	if (cast_dest < cast_src)
	{
		return (ft_non_overlapping(dest, src, n));
	}
	else if (cast_dest > cast_src)
	{
		return (ft_overlapping(dest, src, n));
	}
	return (cast_dest);
}

/*int main(void)
{
	char *src[20] = NULL;
	char *dest[20] = NULL;

	ft_memmove(dest, src, 3);
	write(1, dest, 12);
	write(1, "\n", 1);
	ft_memmove(src + 6, src, 4);
	write(1, src, 12);
	write(1, "\n", 1);

	return (0);
}*/

/*int main(void)
{
    char src[20] = "Example Test!";

    // Moving "Example" (7 characters) to start at index 8
    ft_memmove(src + 8, src, 7);

    // Print the result
    write(1, src, 14);  // Should print: "Example Exampl"
    write(1, "\n", 1);

    return (0);
}

int main(void)
{
    char src[20] = "Hello World!";

    // Moving "World" (5 characters) to start at index 0
    ft_memmove(src, src + 6, 5);

    // Print the result
    write(1, src, 12);  // Should print: "World World!"
    write(1, "\n", 1);

    return (0);
}*/
