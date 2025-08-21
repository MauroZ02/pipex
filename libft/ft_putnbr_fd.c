/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:14:58 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/11 15:47:53 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	d;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			d = n + '0';
			write (fd, &d, 1);
		}
	}
}

// int main()
// {
//     int test_numbers[] = {0, 123, -123, 2147483647, -2147483648};
//     int size = sizeof(test_numbers) / sizeof(test_numbers[0]);

//     for (int i = 0; i < size; i++)
//     {
//         ft_putnbr_fd(test_numbers[i], 1);  
// Use file descriptor 1 (stdout) to print to the terminal

//         write(1, "\n", 1);  
// Print a newline after each number to make the output readable
//     }
//     return 0;
// }
