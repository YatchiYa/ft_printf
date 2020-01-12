/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_width_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:17:29 by yarab             #+#    #+#             */
/*   Updated: 2020/01/12 13:53:28 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_fill_width(va_list args, char *str, t_flags *flags)
{
	int		i;
	char	*tab;

	tab = (char *)malloc(sizeof(char) * 266);
	i = 0;
	while (ft_is_type(str[i]) != 1 && str[i] != '.')
	{
		if (str[i] == '*')
		{
			flags->width = ft_parse_int_g(args);
			i++;
		}
		else
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				tab[i] = str[i];
				i++;
			}
			flags->width = ft_atoi(tab);
		}
		flags->is_width = '1';
	}
	free(tab);
	return (i);
}

int	ft_fill_precision(va_list args, char *str, t_flags *flags)
{
	int		i;
	char	*tab;

	tab = (char *)malloc(sizeof(char) * 266);
	i = 0;
	while (ft_is_type(str[i]) != 1)
	{
		if (str[i] == '*')
		{
			flags->precision = ft_parse_int_g(args);
			i++;
		}
		else
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				tab[i] = str[i];
				i++;
			}
			flags->precision = ft_atoi(tab);
		}
		flags->is_prec = '1';
	}
	free(tab);
	return (i);
}
