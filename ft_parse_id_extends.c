/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_id_extends.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:55:02 by yarab             #+#    #+#             */
/*   Updated: 2020/01/12 14:32:16 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_digits_parsing_id_extends_2(t_flags flags, int *size)
{
	ft_print_elem(flags.width, flags.precision < 0 ?
		1 : flags.precision, ' ', size);
	ft_print_elem(flags.precision, 1, '0', size);
	flags.precision != 0 ? ft_putchar('0', size) : 0;
}

void	ft_digits_parsing_id_extends(t_flags flags, int number,
	int *size, int n)
{
	if (number < 0)
	{
		ft_print_elem(flags.width,
				flags.precision > n ? flags.precision + 1 : n + 1,
				' ', size);
		ft_putchar('-', size);
		number = number * -1;
		ft_print_elem(flags.precision, n, '0', size);
		number == INT_MIN ?
			ft_putnbr_u((unsigned int)number, size) : ft_putnbr(number, size);
	}
	else
	{
		ft_print_elem(flags.width, flags.precision > n ?
				flags.precision : n, ' ', size);
		ft_print_elem(flags.precision, n, '0', size);
		ft_putnbr(number, size);
	}
}

int		ft_minus_parse_id_extends(t_flags flags, int number, int *size, int n)
{
	if (number < 0)
	{
		ft_putchar('-', size);
		number = number * -1;
		ft_print_elem(flags.precision, n, '0', size);
		ft_putnbr(number, size);
		ft_print_elem(flags.width,
				flags.precision > n ? flags.precision + 1 : n + 1,
				' ', size);
	}
	else
	{
		ft_print_elem(flags.precision, n, '0', size);
		ft_putnbr(number, size);
		ft_print_elem(flags.width,
				flags.precision > n ? flags.precision : n, ' ', size);
	}
	return (number);
}
