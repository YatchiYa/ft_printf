/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 10:21:04 by yarab             #+#    #+#             */
/*   Updated: 2019/12/30 10:30:03 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_putadr_maj(unsigned long n, int *p)
{
	if (n > 15)
	{
		ft_putadr_maj((n / 16), p);
		ft_putadr_maj((n % 16), p);
	}
	else if (n < 10)
	{
		ft_putchar(n + '0', p);
	}
	else
	{
		n == 10 ? ft_putchar('A', p) : 0;
		n == 11 ? ft_putchar('B', p) : 0;
		n == 12 ? ft_putchar('C', p) : 0;
		n == 13 ? ft_putchar('D', p) : 0;
		n == 14 ? ft_putchar('E', p) : 0;
		n == 15 ? ft_putchar('F', p) : 0;
	}
}

void	ft_putadr(unsigned long n, int *p)
{
	if (p == NULL)
		return ;
	else if (n > 15)
	{
		ft_putadr((n / 16), p);
		ft_putadr((n % 16), p);
	}
	else if (n < 10)
	{
		ft_putchar(n + '0', p);
	}
	else
	{
		n == 10 ? ft_putchar('a', p) : 0;
		n == 11 ? ft_putchar('b', p) : 0;
		n == 12 ? ft_putchar('c', p) : 0;
		n == 13 ? ft_putchar('d', p) : 0;
		n == 14 ? ft_putchar('e', p) : 0;
		n == 15 ? ft_putchar('f', p) : 0;
	}
}
