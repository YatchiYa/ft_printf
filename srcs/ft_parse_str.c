#include "../includes/ft_printf.h"

void		ft_parse_str(va_list args, int *size)
{
	char	*str;

	str = va_arg(args, char*);
	ft_putstr(str, size);
}
