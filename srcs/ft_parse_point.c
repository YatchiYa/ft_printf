#include "../includes/ft_printf.h"

void	ft_point_parsing(char *str, va_list args, int *p, int *size, t_flags flags)
{
	char	t[550];
	int	number;
	int	i = 0;

	int n = ft_str_length_format(str[0], args);
	number = va_arg(args, int);
	if (number < 0)
	{
		ft_putchar('-', size);
		number = number * -1;
	}
	if (flags.blanks == 1 && flags.precision != -1)
	{	
		ft_print_elem(flags.width, flags.precision, ' ', size);
		ft_print_elem(flags.precision, n, '0', size);
	}
	else if (flags.precision == -1 && flags.blanks == 0)
		ft_print_elem(flags.width, n, ' ', size);
	ft_putnbr(number, size);
}

void	ft_parse_point(char *str, va_list args, int *p ,int *size)
{
	int		k;
	t_flags		flags;

	inti_struct(&flags);
	k = 0;
	flags.width = 0;
	k++;
	k += ft_fill_precision(args, &str[k], &flags);
	*p = *p + k;
	ft_digits_parsing(str + k, args, p, size, flags);
}
