#include "../includes/ft_printf.h"

void	ft_parse_int(va_list args, int *p)
{
	int	number;

	number = va_arg(args, int);
	ft_putnbr(number, p);
}

void	ft_digits_parsing_id(char *str, va_list args, int *p, int *size, t_flags flags)
{
	int	number;
	int	n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, int);
	if (flags.blanks == 1 && flags.precision != -1)
	{
		if (number < 0)
		{
			ft_print_elem(flags.width, flags.precision > n ? 
					flags.precision + 1 : n + 1, ' ', size);
			ft_putchar('-', size);
			number = number * -1;
			ft_print_elem(flags.precision, n, '0', size);
		}
		else
		{
			ft_print_elem(flags.width, flags.precision > n ? 
					flags.precision : n, ' ', size);
			ft_print_elem(flags.precision, n, '0', size);
		}
	}
	else
	{
		if (number < 0)
		{
			ft_print_elem(flags.width, n + 1, ' ', size);
			ft_putchar('-', size);
			number = number * -1;
		}
		else
			ft_print_elem(flags.width, n, ' ', size);
	}
	ft_putnbr(number, size);
}

void	ft_minus_parse_id(char *str, va_list args, int *p, int *size, t_flags flags)
{
	int	number;
	int	n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, int);
	if (flags.blanks == 1 && flags.precision != -1)
	{
		if (number < 0)
		{
			ft_putchar('-', size);
			number = number * -1;
			ft_print_elem(flags.precision, n, '0', size);
			ft_putnbr(number, size);
			ft_print_elem(flags.width, 
					flags.precision > n ? flags.precision + 1: n + 1,
					' ', size);
		}
		else
		{
			ft_print_elem(flags.precision, n, '0', size);
			ft_putnbr(number, size);
			ft_print_elem(flags.width, 
					flags.precision > n ? flags.precision : n, ' ', size);
		}
	}
	else
	{
		if (number < 0)
		{
			ft_putchar('-', size);
			number = number * -1;
			ft_putnbr(number, size);
			ft_print_elem(flags.width, n + 1, ' ', size);
		}
		else
		{
			ft_putnbr(number, size);
			ft_print_elem(flags.width, n, ' ', size);
		}
	}
}

void	ft_zero_parsing_id(char *str, va_list args, int *p, int *size, t_flags flags)
{
	int	number;
	int	n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, int);
	if (flags.precision != -1)
	{
		if (number < 0)
		{
			ft_print_elem(flags.width, 
				flags.precision > n ? flags.precision + 1 : n + 1,
				' ', size);
			ft_putchar('-', size);
			number = number * -1;
			ft_print_elem(flags.precision, n, '0', size);
		}
		else
		{	
			ft_print_elem(flags.width, 
				flags.precision > n ? flags.precision : n, ' ', size);
			ft_print_elem(flags.precision, n, '0', size);
		}
	}
	else if (flags.precision == -1 && flags.blanks == 0)
	{
		if (number < 0)
		{
			ft_putchar('-', size);
			number = number * -1;
		}
		ft_print_elem(flags.width, n, '0', size);
	}
	ft_putnbr(number, size);
}
