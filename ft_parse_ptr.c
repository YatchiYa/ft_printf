/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:59:01 by yarab             #+#    #+#             */
/*   Updated: 2019/12/30 10:29:19 by yarab            ###   ########.fr       */
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
