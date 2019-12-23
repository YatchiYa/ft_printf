#include "../includes/ft_printf.h"

void	ft_minus_parse_int(char *str, va_list args, int *p, int *size, t_flags flags)
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

void	ft_minus_parsing(char *str, va_list args, int *p, int *size, t_flags flags)
{
	if (str[0] == 'd' || str[0] == 'i')
		ft_minus_parse_int(str, args, p, size, flags);

	clear_struct(&flags);
}

void	ft_parse_minus(char *str, va_list args, int *p ,int *size)
{
	int		k;
	t_flags		flags;

	inti_struct(&flags);
	k = 0;
	if (str[k] != '.')
		k += ft_fill_width(args, &str[k], &flags);
	if (str[k] == '.')
		k += ft_fill_precision(args, &str[k + 1], &flags) + 1;
	*p = *p + k + 1;
	ft_minus_parsing(str + k, args, p, size, flags);	
}
