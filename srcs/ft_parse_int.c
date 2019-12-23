#include "../includes/ft_printf.h"

void	ft_parse_hexa(va_list args, int *p)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	ft_putnbr_base(number, HEXA_BASE, p);
}

void	ft_parse_hexa_m(va_list args, int *p)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	ft_putnbr_base(number, HEXA_BASE_M, p);
}

void	ft_parse_ptr(va_list args, int *p)
{
	void		*adr;
	unsigned long	num_hex;

	adr = va_arg(args, void*);
	num_hex = (unsigned long)(adr);
	ft_putstr("0x", p);
	ft_putadr(num_hex, p);
}
