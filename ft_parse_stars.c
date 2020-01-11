/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_stars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:59:27 by yarab             #+#    #+#             */
/*   Updated: 2020/01/11 15:06:25 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_stars_parsing(char *str, va_list args, int *size, t_flags flags)
{
	if (str[0] == 's')
		ft_digits_parsing_s(args, size, flags);
	else if (str[0] == 'c')
		ft_digits_parsing_c(args, size, flags);
	else if (str[0] == 'u')
		ft_digits_parsing_u(str, args, size, flags);
	else if (str[0] == 'd' || str[0] == 'i')
		ft_digits_parsing_id(str, args, size, flags);
	else if (str[0] == 'x')
		ft_digits_parsing_hexa(str, args, size, flags);
	else if (str[0] == 'X')
		ft_digits_parsing_hexa_m(str, args, size, flags);
	else if (str[0] == 'p')
		ft_digits_parsing_adr(str, args, size, flags);
	else if (str[0] == '%')
		ft_digits_parsing_prc(size, flags);
	clear_struct(&flags);
}

void	ft_parse_stars(char *str, va_list args, int *p, int *size)
{
	int			k;
	t_flags		flags;

	inti_struct(&flags);
	k = 0;
	k += ft_fill_width(args, &str[k], &flags);
	flags.is_width = '1';
	if (str[k] == '.')
	{
		flags.precision = 0;
		k += ft_fill_precision(args, &str[k + 1], &flags) + 1;
		flags.is_prec = '1';
	}
	*p = *p + k;
	if (flags.precision < 0 && flags.precision != -1)
		if (str[k] == 's')
			flags.precision = -1;
	if (flags.width < 0 && flags.is_width == '1')
	{
		flags.width = flags.width * -1;
		ft_minus_parsing(str + k, args, size, flags);
	}
	else
		ft_stars_parsing(str + k, args, size, flags);
}
