#include "../includes/ft_printf.h"

void		ft_parse_char(va_list args, int *size)
{
	char	c;

	c = (char)va_arg(args, int);
	ft_putchar(c, size);
}

void		ft_parse_str(va_list args, int *size)
{
	char	*str;

	str = va_arg(args, char*);
	ft_putstr(str, size);
}
