/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 10:22:36 by yarab             #+#    #+#             */
/*   Updated: 2019/12/30 10:29:58 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putadr_l(unsigned long n)
{
	if (n < 15)
		return (1);
	else
		return (1 + ft_putadr_l(n / 16));
}

int	ft_putadr_len(va_list args)
{
	va_list			argx;
	unsigned long	n;
	void			*adr;
	int				len;

	va_copy(argx, args);
	adr = va_arg(argx, void*);
	n = (unsigned long)adr;
	len = ft_putadr_l(n);
	return (len + 2);
}
