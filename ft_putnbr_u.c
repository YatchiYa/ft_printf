/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 10:23:52 by yarab             #+#    #+#             */
/*   Updated: 2019/12/30 10:30:11 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_putnbr_u(unsigned int nb, int *p)
{
	unsigned int	nbr;

	nbr = nb;
	if (nbr >= 10)
		ft_putnbr_u(nbr / 10, p);
	ft_putchar(nbr % 10 + 48, p);
}
