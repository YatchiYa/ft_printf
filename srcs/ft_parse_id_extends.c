#include "../includes/ft_printf.h"

void	ft_digits_parsing_id_extends(t_flags flags, int number, int *size)
{
		if (number < 0)
		{
			ft_print_elem(flags.width, 
                    flags.precision > n ? 
                    flags.precision + 1 : n + 1, 
                    ' ', size);
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

void	ft_minus_parse_id_extends(t_flags flags, int number, int *size)
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