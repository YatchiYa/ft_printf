/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 10:24:36 by yarab             #+#    #+#             */
/*   Updated: 2019/12/30 10:30:21 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_putstr(char *str, int *size)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], size);
		i++;
	}
}
