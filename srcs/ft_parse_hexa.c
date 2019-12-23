#include "../includes/ft_printf.h"

void	ft_parse_hexa(va_list args, int *p)
{
	unsigned long	number;

	number = va_arg(args, unsigned long);
	ft_putadr(number, p);
}

void	ft_digits_parsing_hexa(char *str, va_list args, int *p, int *size, t_flags flags)
{
	unsigned long	number;
	int	n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, unsigned long);
	if (flags.blanks == 1 && flags.precision != -1)
	{
			ft_print_elem(flags.width, flags.precision > n ? 
					flags.precision : n, ' ', size);
			ft_print_elem(flags.precision, n, '0', size);
	}
	else
			ft_print_elem(flags.width, n, ' ', size);
	ft_putadr(number, size);
}

void	ft_minus_parse_hexa(char *str, va_list args, int *p, int *size, t_flags flags)
{
	unsigned long	number;
	int	n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, unsigned long);
	if (flags.blanks == 1 && flags.precision != -1)
	{
			ft_print_elem(flags.precision, n, '0', size);
			ft_putadr(number, size);
			ft_print_elem(flags.width, 
					flags.precision > n ? flags.precision : n, ' ', size);
	}
	else
	{
			ft_putadr(number, size);
			ft_print_elem(flags.width, n, ' ', size);
	}
}

void	ft_zero_parsing_hexa(char *str, va_list args, int *p, int *size, t_flags flags)
{
	unsigned long	number;
	int	n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, unsigned long);
	if (flags.precision != -1)
	{
			ft_print_elem(flags.width, 
				flags.precision > n ? flags.precision : n, ' ', size);
			ft_print_elem(flags.precision, n, '0', size);
	}
	else if (flags.precision == -1 && flags.blanks == 0)
		ft_print_elem(flags.width, n, '0', size);
	ft_putadr(number, size);
}
