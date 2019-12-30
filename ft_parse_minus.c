/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:57:02 by yarab             #+#    #+#             */
/*   Updated: 2019/12/30 10:49:53 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_minus_parsing(char *str, va_list args, int *size, t_flags flags)
{
	if (str[0] == 'd' || str[0] == 'i')
		ft_minus_parse_id(str, args, size, flags);
	if (str[0] == 'u')
		ft_minus_parse_u(str, args, size, flags);
	if (str[0] == 'x')
		ft_minus_parse_hexa(str, args, size, flags);
	if (str[0] == 'X')
		ft_minus_parse_hexa_m(str, args, size, flags);
	if (str[0] == 'c')
		ft_minus_parse_c(args, size, flags);
	if (str[0] == 's')
		ft_minus_parse_str(args, size, flags);
	if (str[0] == 'p')
		ft_minus_parse_adr(str, args, size, flags);
	if (str[0] == '%')
		ft_minus_parse_prc(size, flags);
	clear_struct(&flags);
}

void	ft_parse_minus(char *str, va_list args, int *p, int *size)
{
	int			k;
	t_flags		flags;

	inti_struct(&flags);
	k = 0;
	if (str[k] != '.')
		k += ft_fill_width(args, &str[k], &flags);
	if (str[k] == '.')
		k += ft_fill_precision(args, &str[k + 1], &flags) + 1;
	*p = *p + k + 1;
	ft_minus_parsing(str + k, args, size, flags);
}
