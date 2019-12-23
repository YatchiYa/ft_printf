#include "../includes/ft_printf.h"

void	ft_digits_parsing_c(char *strx, va_list args, int *p, int *size, t_flags flags)
{
	char	c;

	c = (char)va_arg(args, int);
	if (flags.width != -1)
	{
		ft_print_elem(flags.width, 1, ' ', size);
		ft_putchar(c, size);
	}
	else
		ft_putchar(c, size);
}

void	ft_digits_parsing_s(char *strx, va_list args, int *p, int *size, t_flags flags)
{
	char	*s;
	int	i;

	int n = ft_str_length_format(strx[0], args);
	s = va_arg(args, char*);
	i = 0;
	if (flags.precision != -1)
	{
		ft_print_elem(flags.width, flags.precision, ' ', size);
		while (s[i] && i < flags.precision)
		{
			ft_putchar(s[i], size);
			i++;
		}
	}
	else
	{
		ft_print_elem(flags.width, n, ' ', size);
		ft_putstr(s, size);
	}
}

void	ft_digits_parsing_u(char *str, va_list args, int *p, int *size, t_flags flags)
{
	int		n;
	
	*p = *p - 1;
	n = ft_str_length_format(str[0], args);
	if (str[0] == 'p')
		printf(" -DEBUG- %d -", n);
	if (flags.blanks == 1 && flags.precision != -1)
	{
		ft_print_elem(flags.width,
				flags.precision > n ? flags.precision : n,
				' ', size);
		ft_print_elem(flags.precision, n, '0', size);
	}
	else
		ft_print_elem(flags.width, n, ' ', size);
	ft_parse_format(str, args, p, size);
}

void	ft_digits_parsing(char *str, va_list args, int *p, int *size, t_flags flags)
{
	char	t[550];
	int	number;
	int	n;

	if (str[0] == 's')
		ft_digits_parsing_s(str, args, p, size, flags);
	else if (str[0] == 'c')
		ft_digits_parsing_c(str, args, p, size, flags);
	else if (str[0] == 'u' || str[0] == 'p' || str[0] == 'x' 
			||str[0] == 'X')
		ft_digits_parsing_u(str, args, p, size, flags);
	else if (str[0] == 'd' || str[0] == 'i')
		ft_digits_parsing_id(str, args, p, size, flags);
	clear_struct(&flags);
}

void	ft_parse_digits(char *str, va_list args, int *p ,int *size)
{
	int		i;
	int		j;
	char		s[3][500];
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
	*p = *p + k;
	ft_digits_parsing(str + k, args, p, size, flags);
}
