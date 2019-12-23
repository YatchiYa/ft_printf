#include "../includes/ft_printf.h"

int		ft_str_length_format(char c, va_list argx)
{
	int	length;
	va_list		args;
	
	length = 0;
	va_copy(args, argx);
	(c == 'd') || (c == 'i') ? length = ft_numlen(args) : 0;
	(c == 'x') || (c = 'X') ? length = ft_hexalen(args) : 0;
	(c == 'u') ? length = ft_numlen_u(args) : 0;
	(c == 'p') ? length = (ft_putadr_len(args) + 2) : 0;
	(c == 'c') ? length = 1 : 0;
	(c == 's') ? length = ft_strlen_args(args) : 0;
	return (length);
}

void		ft_parse_format(char *str, va_list args, int *p, int *size)
{
	int	i;

	i = 0;
	*p = *p + 1;
	str[i] == 'd' ? ft_parse_int(args, size) : 0;
	str[i] == 'i' ? ft_parse_int(args, size) : 0;
	str[i] == 'u' ? ft_parse_uint(args, size) : 0;
	str[i] == 'p' ? ft_parse_ptr(args, size) : 0;
	str[i] == 'c' ? ft_parse_char(args, size) : 0;
	str[i] == 's' ? ft_parse_str(args, size) : 0;
	str[i] == '%' ? ft_putchar('%', size) : 0;
	str[i] == 'x' ? ft_parse_hexa(args, size) : 0;
	str[i] == 'X' ? ft_parse_hexa_m(args, size) : 0;
	str[i] == '0' ? ft_parse_zero(&str[i + 1], args, p, size) : 0;
	str[i] > '0' && str[i] <= '9' ? ft_parse_digits(&str[i], args, p, size) : 0;
	str[i] == '-' ? ft_parse_minus(&str[i + 1], args, p, size) : 0;
	str[i] == '*' ? ft_parse_stars(&str[i], args, p, size) : 0;
	str[i] == '.' ? ft_parse_point(&str[i], args, p, size) : 0;
}
