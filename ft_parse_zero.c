/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 10:06:10 by yarab             #+#    #+#             */
/*   Updated: 2020/01/06 12:17:15 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_zero_parsing(char *str, va_list args, int *size, t_flags flags)
{
	if (str[0] == 'i' || str[0] == 'd')
		ft_zero_parsing_id(str, args, size, flags);
	if (str[0] == 'u')
		ft_zero_parsing_u(str, args, size, flags);
	if (str[0] == 'x')
		ft_zero_parsing_hexa(str, args, size, flags);
	if (str[0] == 'X')
		ft_zero_parsing_hexa_m(str, args, size, flags);
	if (str[0] == 'c')
		ft_zero_parsing_c(args, size, flags);
	if (str[0] == 's')
		ft_zero_parsing_s(args, size, flags);
	if (str[0] == '%')
		ft_zero_parsing_prc(size, flags);
	if (str[0] == 'p')
		ft_zero_parsing_adr(str, args, size, flags);
}

void	ft_parse_zero(char *str, va_list args, int *p, int *size)
{
	int			k;
	t_flags		flags;

	inti_struct(&flags);
	k = 0;
	if (str[k] != '.')
		k += ft_fill_width(args, &str[k], &flags);
	if (str[k] == '.')
	{
		flags.precision = 0;
		k += ft_fill_precision(args, &str[k + 1], &flags) + 1;
	}
	*p = *p + k + 1;
	if (flags.precision < 0)
		if (str[k] == 's')
			flags.precision = -1;
	if (flags.width < 0)
	{
		flags.width *= -1;
		ft_minus_parsing(str + k, args, size, flags);
	}
	else
		ft_zero_parsing(str + k, args, size, flags);
}
