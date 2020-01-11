/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:57:58 by yarab             #+#    #+#             */
/*   Updated: 2020/01/11 15:49:12 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_point_parsing_s(va_list args, int *size, t_flags flags)
{
	char	*s;
	int		i;
	char	*t;

	t = va_arg(args, char*);
	s = (t == NULL) ? ft_strdup("(null)") : ft_strdup(t);
	i = 0;
	if (flags.precision == -1 && flags.is_prec == '0')
		;
	else if (flags.precision < 0 && flags.is_prec == '1')
	{
		ft_print_elem(flags.width > ft_strlen(s) ?
			flags.width : 0, ft_strlen(s), ' ', size);
		if (ft_strcmp(s, "(null)") == 0)
			ft_putstr("(null)", size);
		else
			while (s[i])
			{
				ft_putchar(s[i], size);
				i++;
			}
	}
	else
	{
		ft_print_elem(flags.width, flags.precision > ft_strlen(s) ?
				ft_strlen(s) : flags.precision, ' ', size);
		while (s[i] && i < flags.precision)
		{
			ft_putchar(s[i], size);
			i++;
		}
	}
	free(s);
}

void	ft_point_parsing(char *str, va_list args, int *size, t_flags flags)
{
	if (str[0] == 's')
		ft_point_parsing_s(args, size, flags);
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

void	ft_parse_point(char *str, va_list args, int *p, int *size)
{
	int			k;
	t_flags		flags;

	inti_struct(&flags);
	k = 0;
	flags.width = 0;
	k++;
	k += ft_fill_precision(args, &str[k], &flags);
	*p = *p + k;
	ft_point_parsing(str + k, args, size, flags);
}
