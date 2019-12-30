/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:57:58 by yarab             #+#    #+#             */
/*   Updated: 2019/12/30 10:29:11 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

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
	if (flags.precision < 0)
	{
		if (str[k] == 's')
		{
			flags.precision = -1;
			ft_minus_parsing(str + k, args, size, flags);
		}
		else
		{
			flags.precision = 0;
			ft_digits_parsing(str + k, args, size, flags);
		}
	}
	else
		ft_digits_parsing(str + k, args, size, flags);
}
