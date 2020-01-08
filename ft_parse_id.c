/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 10:10:27 by yarab             #+#    #+#             */
/*   Updated: 2020/01/08 15:39:06 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_parse_int(va_list args, int *p)
{
	int	number;

	number = va_arg(args, int);
	ft_putnbr(number, p);
}

void	ft_digits_parsing_id(char *str, va_list args, int *size, t_flags flags)
{
	int	number;
	int	n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, int);
	if (number == 0 && flags.precision != -1)
		ft_digits_parsing_id_extends_2(flags, size);
	else
	{
		if (flags.blanks == 1 && flags.precision != 0)
			number = ft_digits_parsing_id_extends(flags, number, size, n);
		else
		{
			if (number < 0)
			{
				ft_print_elem(flags.width, n + 1, ' ', size);
				ft_putchar('-', size);
				number = number * -1;
			}
			else
				ft_print_elem(flags.width, n, ' ', size);
		}
		ft_putnbr(number, size);
	}
}