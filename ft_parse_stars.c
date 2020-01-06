/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_stars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:59:27 by yarab             #+#    #+#             */
/*   Updated: 2020/01/06 11:38:45 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_parse_stars(char *str, va_list args, int *p, int *size)
{
	int			k;
	t_flags		flags;

	inti_struct(&flags);
	k = 0;
	k += ft_fill_width(args, &str[k], &flags);
	if (str[k] == '.')
	{
		flags.precision = 0;
		k += ft_fill_precision(args, &str[k + 1], &flags) + 1;
	}
	*p = *p + k;
	if (flags.precision < 0)
		flags.precision = str[k] == 's' ? -1 : 0;
	if (flags.width < 0)
	{
		flags.width = flags.width * -1;
		ft_minus_parsing(str + k, args, size, flags);
	}
	else
		ft_digits_parsing(str + k, args, size, flags);
}
