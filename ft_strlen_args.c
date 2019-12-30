/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <yarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 10:25:22 by yarab             #+#    #+#             */
/*   Updated: 2019/12/30 10:30:39 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_strlen_args(va_list argx)
{
	char	*str;
	va_list	args;

	va_copy(args, argx);
	str = va_arg(args, char*);
	if (str == NULL)
		return (6);
	else
		return (ft_strlen(str));
}
