#include "../includes/ft_printf.h"

void	ft_parse_hexa_m(va_list args, int *p)
{
	unsigned long	number;

	number = va_arg(args, unsigned long);
	ft_putadr_maj(number, p);
}
