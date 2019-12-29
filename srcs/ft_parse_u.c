#include "../includes/ft_printf.h"

void	ft_parse_uint(va_list args, int *p)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	ft_putnbr_u(number, p);
}

void	ft_minus_parse_u(char *str, va_list args, int *p, int *size, t_flags flags)
{
	unsigned int    number;
	int	            n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, unsigned int);
	if (flags.blanks == 1 && flags.precision != -1)
	{
			ft_print_elem(flags.precision, n, '0', size);
			ft_putnbr(number, size);
			ft_print_elem(flags.width, 
					flags.precision > n ? flags.precision : n, ' ', size);
	}
	else
	{
			ft_putnbr(number, size);
			ft_print_elem(flags.width, n, ' ', size);
	}
}


void	ft_zero_parsing_u(char *str, va_list args, int *p, int *size, t_flags flags)
{
	unsigned int	number;
	int	n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, unsigned int);
	if (flags.precision != -1)
	{	
			ft_print_elem(flags.width, 
				flags.precision > n ? flags.precision : n, ' ', size);
			ft_print_elem(flags.precision, n, '0', size);
	}
	else if (flags.precision == -1 && flags.blanks == 0)
		ft_print_elem(flags.width, n, '0', size);
	ft_putnbr(number, size);
}


void	ft_digits_parsing_u(char *str, va_list args, int *p, int *size, t_flags flags)
{
	unsigned int	number;
	int	n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, unsigned int);
	if (flags.blanks == 1 && flags.precision != -1)
	{
			ft_print_elem(flags.width, flags.precision > n ? 
					flags.precision : n, ' ', size);
			ft_print_elem(flags.precision, n, '0', size);
	}
	else
			ft_print_elem(flags.width, n, ' ', size);
	ft_putnbr(number, size);
}
