/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 10:07:26 by yarab             #+#    #+#             */
/*   Updated: 2019/12/30 10:29:46 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int		i;
	int		size;
	va_list	args;

	i = 0;
	size = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			ft_parse_format((char *)&str[i], args, &i, &size);
		}
		else
		{
			ft_putchar(str[i], &size);
			i++;
		}
	}
	va_end(args);
	return (size);
}
