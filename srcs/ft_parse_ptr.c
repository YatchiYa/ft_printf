#include "../includes/ft_printf.h"

void	ft_parse_ptr(va_list args, int *p)
{
	void		*adr;
	unsigned long	num_hex;

	adr = va_arg(args, void*);
	num_hex = (unsigned long)(adr);
	ft_putstr("0x", p);
	ft_putadr(num_hex, p);
}
