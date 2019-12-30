/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_prc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:58:38 by yarab             #+#    #+#             */
/*   Updated: 2019/12/30 10:50:14 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_digits_parsing_prc(int *size, t_flags flags)
{
	char	c;

	c = '%';
	if (flags.width != -1)
	{
		ft_print_elem(flags.width, 1, ' ', size);
		ft_putchar(c, size);
	}
	else
		ft_putchar(c, size);
}

void	ft_minus_parse_prc(int *size, t_flags flags)
{
	char	c;

	c = '%';
	if (flags.width != -1)
	{
		ft_putchar(c, size);
		ft_print_elem(flags.width, 1, ' ', size);
	}
	else
		ft_putchar(c, size);
}

void	ft_zero_parsing_prc(int *size, t_flags flags)
{
	char	c;

	c = '%';
	if (flags.width != -1)
	{
		ft_print_elem(flags.width, 1, '0', size);
		ft_putchar(c, size);
	}
	else
		ft_putchar(c, size);
}
