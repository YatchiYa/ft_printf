#include "../includes/ft_printf.h"

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

void	ft_zero_parsing(char *str, va_list args, int *p, int *size, t_flags flags)
{
	if (str[0] == 'i' || str[0] == 'd')
		ft_zero_parsing_id(str, args, p, size, flags);
}


void	ft_parse_zero(char *str, va_list args, int *p ,int *size)
{
	int		k;
	t_flags		flags;

	inti_struct(&flags);
	k = 0;
	if (str[k] != '.')
		k += ft_fill_width(args, &str[k], &flags);
	if (str[k] == '.')
	{
		flags.precision = 0;
		k += ft_fill_precision(args, &str[k + 1], &flags) + 1;
	}
	*p = *p + k + 1;
	ft_zero_parsing(str + k, args, p, size, flags);

	/*
	int		i;
	int		j;
	char		s[2][255];
	int		k;
	t_flags		flags;

	inti_struct(&flags);
	i = 0;
	j = 0;
	k = 0;
	while (ft_is_type(str[i]) != 1)
	{

		while (str[i] >= '0' && str[i] <= '9')
		{
			s[0][j] = str[i];
			i++;
			j++;
			k++;
		}
		flags.width = ft_atoi(s[0]);
		if (str[i] == '*')
		{
			flags.precision = ft_parse_int_g(args);
			flags.blanks = 1;
			i++;
			k++;
		}
		j = 0;
		if (str[i] == '.')
		{
			i++;
			k++;
			while (str[i] >= '0' && str[i] <= '9')
			{
				s[1][j] = str[i];
				i++;
				j++;
				k++;
			}
			flags.precision = ft_atoi(s[1]);
			flags.blanks = 1;
		}
		if (str[i] == '*')
		{
			flags.precision = ft_parse_int_g(args);
			flags.blanks = 1;
			i++;
			k++;
		}
		else
			i++;
	}
	*p = *p + k + 1;
	ft_zero_parsing(str + k, args, p, size, flags);
	*/
}
