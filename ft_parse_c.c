/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:40:25 by yarab             #+#    #+#             */
/*   Updated: 2020/01/08 14:28:05 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_parse_char(va_list args, int *size)
{
	char	c;

	c = (char)va_arg(args, int);
	ft_putchar(c, size);
}

void		ft_digits_parsing_c(va_list args, int *size, t_flags flags)
{
	char	c;

	c = (char)va_arg(args, int);
	if (flags.width < 0)
		flags.width *= -1;
	if (flags.width != -1)
	{
		ft_print_elem(flags.width, 1, ' ', size);
		ft_putchar(c, size);
	}
	else
		ft_putchar(c, size);
}

void		ft_minus_parse_c(va_list args, int *size, t_flags flags)
{
	char	c;

	c = (char)(va_arg(args, int));
	if (flags.width < 0)
		flags.width *= -1;
	if (flags.width != -1)
	{
		ft_putchar(c, size);
		ft_print_elem(flags.width, 1, ' ', size);
	}
	else
		ft_putchar(c, size);
}

void		ft_zero_parsing_c(va_list args, int *size, t_flags flags)
{
	char	c;

	c = (char)va_arg(args, int);
	if (flags.width < 0)
		flags.width *= -1;
	if (flags.width != -1)
	{
		ft_print_elem(flags.width, 1, '0', size);
		ft_putchar(c, size);
	}
	else
		ft_putchar(c, size);
}
