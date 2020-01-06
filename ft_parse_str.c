/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 10:03:26 by yarab             #+#    #+#             */
/*   Updated: 2020/01/06 12:05:32 by yarab            ###   ########.fr       */
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
	if (flags.precision != -1)
	{
		ft_print_elem(flags.width, flags.precision > ft_strlen(s) ?
				ft_strlen(s) : flags.precision, ' ', size);
		while (s[i] && i < flags.precision)
		{
			ft_putchar(s[i], size);
			i++;
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
	if (flags.precision != -1)
	{
		while (s[i] && i < flags.precision)
		{
			ft_putchar(s[i], size);
			i++;
		}
		ft_print_elem(flags.width, flags.precision > ft_strlen(s) ?
			ft_strlen(s) : flags.precision, ' ', size);
	}
	else
	{
		ft_putstr(s, size);
		ft_print_elem(flags.width, ft_strlen(s), ' ', size);
	}
	free(s);
}
