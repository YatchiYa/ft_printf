#include "../includes/ft_printf.h"

int	ft_is_type(char c)
{
	int	i;

	i = 0;
	while (PARSE_LETTERS[i])
	{
		if (c == PARSE_LETTERS[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_flags(char c)
{
	int	i;

	i = 0;
	while (PARSE_FLAGS[i] != '\0')
	{
		if (c == PARSE_FLAGS[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_parse_int_tmp(va_list args)
{
	va_list		argx;

	int		number;

	va_copy(argx, args);
	number = va_arg(args, int);
	return (number);
}

int	ft_parse_int_g(va_list args)
{
	int	number;

	number = va_arg(args, int);
	return (number);
}

void	ft_print_elem(int w, int p, char c, int *size)
{
	while (w > p)
	{
		ft_putchar(c, size);
		p++;
	}
}
