/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 10:03:26 by yarab             #+#    #+#             */
/*   Updated: 2020/01/11 15:48:22 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_parse_str(va_list args, int *size)
{
	char	*str;
	char	*tmp;

	tmp = va_arg(args, char*);
	str = (tmp == NULL) ? ft_strdup("(null)") : ft_strdup(tmp);
	ft_putstr(str, size);
	free(str);
}

void	ft_zero_parsing_s(va_list args, int *size, t_flags flags)
{
	char	*s;
	int		i;
	char	*t;

	t = va_arg(args, char*);
	s = (t == NULL) ? ft_strdup("(null)") : ft_strdup(t);
	i = 0;
	if (flags.precision != -1)
	{
		ft_print_elem(flags.width, flags.precision - 1, '0', size);
		while (s[i] && i < flags.precision)
		{
			ft_putchar(s[i], size);
			i++;
		}
	}
	else
	{
		ft_print_elem(flags.width, ft_strlen(s), '0', size);
		ft_putstr(s, size);
	}
	free(s);
}

void	ft_digits_parsing_s(va_list args, int *size, t_flags flags)
{
	char	*s;
	int		i;
	char	*t;

	t = va_arg(args, char*);
	s = (t == NULL) ? ft_strdup("(null)") : ft_strdup(t);
	i = 0;
	if (flags.is_prec == '1')
	{
		if (flags.precision < 0)
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
	}
	else
	{
		ft_print_elem(flags.width, ft_strlen(s), ' ', size);
		ft_putstr(s, size);
	}
	free(s);
}

void	ft_minus_parse_str(va_list args, int *size, t_flags flags)
{
	char	*s;
	int		i;
	char	*t;

	t = va_arg(args, char*);
	s = (t == NULL) ? ft_strdup("(null)") : ft_strdup(t);
	i = 0;
	if (flags.width < 0 && flags.is_width == '1')
		flags.width *= -1;
	if (flags.is_prec == '1')
	{
		if (flags.precision == 0 || ft_strcmp(s, "") == 0)
			ft_print_elem(flags.width, 0, ' ', size);
		else
		{
			if (ft_strcmp(s, "(null)") == 0 && flags.precision < 0)
			{
				ft_putstr("(null)", size);
				flags.precision = 6;
			}
			else
			{
				if (flags.precision < 0)
					ft_putstr(s, size);
				else
					while (s[i] && i < flags.precision)
					{
						ft_putchar(s[i], size);
						i++;
					}
				if (flags.precision > 0)
					flags.precision = flags.precision > ft_strlen(s) ?
						ft_strlen((s)) : flags.precision;
				else
					flags.precision = ft_strlen(s);
			}
			ft_print_elem(flags.width, flags.precision, ' ', size);
		}
	}
	else
	{
		ft_putstr(s, size);
		if (flags.is_prec == '0')
		{
			if (ft_strcmp(s, "") == 0)
				ft_print_elem(flags.width, 0, ' ', size);
			else
				ft_print_elem(flags.width, ft_strlen(s), ' ', size);
		}
		else
			ft_print_elem(flags.width, ft_strlen(s), ' ', size);
	}
	free(s);
}
