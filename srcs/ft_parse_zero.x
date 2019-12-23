#include "../includes/ft_printf.h"

void	ft_zero_parsing(char *str, va_list args, int *p, int *size, t_flags flags)
{
	char	t[550];
	int	number;
	int	n;

	n = ft_str_length_format(str[0], args);
	number = va_arg(args, int);
	if (flags.blanks == 1 && flags.precision != -1)
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

void	ft_width_fill(char *str, va_list args, t_flags *flags, int *i, int *k)
{
	char	s[500];
	int	j;

	j = 0;
	if (str[*i] == '*')
	{
		flags->width = ft_parse_int_g(args);
		*i = *i + 1;
		*k = *k + 1;
	}
	else
	{
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			s[j] = str[*i];
			*i = *i + 1;
			j++;
			*k = *k + 1;
		}	
		flags->width = ft_atoi(s);
	}
}

void	ft_precision_fill(char *str, va_list args, t_flags *flags, int *i, int *k)
{
	char	s[500];
	int	j;

	j = 0;
	if (str[*i] == '*')
	{
		flags->precision = ft_parse_int_g(args);
		flags->blanks = 1;
		*i = *i + 1;
		*k = *k + 1;
	}
	else 
	{
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			s[j] = str[*i];
			*i = *i + 1;
			j++;
			*k = *k + 1;
		}
		flags->precision = ft_atoi(s);
		flags->blanks = 1;
	}
}

void	ft_parse_zero(char *str, va_list args, int *p ,int *size)
{
	int		i;
	int		k;
	t_flags		flags;

	inti_struct(&flags);
	i = 0;
	k = 0;
	while (ft_is_type(str[i]) != 1)
	{
		ft_width_fill(&str[i], args, &flags, &i, &k);
		if (str[i] == '.')
			ft_precision_fill(&str[i + 1], args, &flags, &i, &k);
		else
			i++;
	}
	*p = *p + k + 1;
	ft_zero_parsing(str + k, args, p, size, flags);
}
