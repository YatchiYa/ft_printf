/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 10:18:55 by yarab             #+#    #+#             */
/*   Updated: 2019/12/30 10:28:05 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_hexalen_l(unsigned long n)
{
	if (n < 16)
		return (1);
	else
		return (1 + ft_hexalen_l(n / 16));
}

int	ft_hexalen(va_list args)
{
	va_list			argx;
	unsigned long	n;
	void			*adr;
	int				len;

	len = 0;
	va_copy(argx, args);
	adr = va_arg(argx, void*);
	n = (unsigned long)adr;
	len = ft_hexalen_l(n);
	return (len);
}
