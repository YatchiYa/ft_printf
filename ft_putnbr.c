/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 10:23:31 by yarab             #+#    #+#             */
/*   Updated: 2019/12/30 10:30:16 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_putnbr(int nb, int *p)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-', p);
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 10)
		ft_putnbr(nbr / 10, p);
	ft_putchar(nbr % 10 + 48, p);
}
