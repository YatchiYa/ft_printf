/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 10:08:24 by yarab             #+#    #+#             */
/*   Updated: 2019/12/30 10:30:56 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	inti_struct(t_flags *flags)
{
	flags->width = -1;
	flags->precision = -1;
	flags->blanks = 0;
}

void	clear_struct(t_flags *flags)
{
	inti_struct(flags);
}
