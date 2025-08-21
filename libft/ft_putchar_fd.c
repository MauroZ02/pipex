/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:59:17 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/11 15:11:26 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

// int main()
// {
// 	ft_putchar_fd('H', 1);
// 	ft_putchar_fd('O', 1);
// 	ft_putchar_fd('L', 1);
// 	ft_putchar_fd('A', 1);
// 	ft_putchar_fd(' ', 1);
// 	ft_putchar_fd('M', 1);
// 	ft_putchar_fd('E', 1);
// 	ft_putchar_fd('S', 1);
// 	ft_putchar_fd('S', 1);
// 	ft_putchar_fd('I', 1);
// 	ft_putchar_fd(' ', 1);
// 	ft_putchar_fd('D', 1);
// 	ft_putchar_fd('I', 1);
// 	ft_putchar_fd('O', 1);
// 	ft_putchar_fd('S', 1);
// 	ft_putchar_fd(' ', 1);
// 	ft_putchar_fd('1', 1);
// 	ft_putchar_fd('0', 1);
// 	return 0;
// }
