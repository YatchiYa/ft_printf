#include "../includes/ft_printf.h"

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

void	ft_minus_parsing(char *str, va_list args, int *p, int *size, t_flags flags)
{
	if (str[0] == 'd' || str[0] == 'i')
		ft_minus_parse_id(str, args, p, size, flags);
	if (str[0] == 'u')
		ft_minus_parse_u(str, args, p, size, flags);
	if (str[0] == 'x')
		ft_minus_parse_hexa(str, args, p, size, flags);
	if (str[0] == 'X')
		ft_minus_parse_hexa_m(str, args, p, size, flags);
	if (str[0] == 'c')
		ft_minus_parse_c(str, args, p, size, flags);
	if (str[0] == 's')
		ft_minus_parse_str(str, args, p, size, flags);
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
