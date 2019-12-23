#include "../includes/ft_printf.h"

void		ft_parse_str(va_list args, int *size)
{
	char	*str;

	str = va_arg(args, char*);
	ft_putstr(str, size);
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
		ft_print_elem(flags.width, ft_strlen(s), ' ', size);
		ft_putstr(s, size);
	}
}

void	ft_minus_parse_str(char *str, va_list args, int *p, int *size, t_flags flags)
{
	char	*s;
	int	i;
	int	n;

	n = ft_str_length_format(str[0], args);
	s = va_arg(args, char*);
	i = 0;
	if (flags.precision != -1)
	{
		while (s[i] && i < flags.precision)
		{
			ft_putchar(s[i], size);
			i++;
		}
		ft_print_elem(flags.width, flags.precision, ' ', size);
	}
	else
	{
		ft_putstr(s, size);
		ft_print_elem(flags.width, ft_strlen(s), ' ', size);
	}
}
