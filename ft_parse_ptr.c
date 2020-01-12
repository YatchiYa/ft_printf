/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:59:01 by yarab             #+#    #+#             */
/*   Updated: 2020/01/12 15:00:02 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_parse_ptr(va_list args, int *p)
{
	void			*adr;
	unsigned long	num_hex;

	adr = va_arg(args, void*);
	num_hex = (unsigned long)(adr);
	ft_putstr("0x", p);
	ft_putadr(num_hex, p);
}

void	ft_parse_hexa(va_list args, int *p)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	ft_putadr(number, p);
}

void	ft_parse_hexa_m(va_list args, int *p)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	ft_putadr_maj(number, p);
}

void	ft_parse_str(va_list args, int *size)
{
	char	*str;
	char	*tmp;

	tmp = va_arg(args, char*);
	str = (tmp == NULL) ? ft_strdup("(null)") : ft_strdup(tmp);
	ft_putstr(str, size);
	free(str);
}

void	ft_parse_uint(va_list args, int *p)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	ft_putnbr_u(number, p);
}
