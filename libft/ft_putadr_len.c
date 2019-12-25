#include "../includes/ft_printf.h"

int	ft_putadr_l(unsigned long n)
{
	if (n < 15)
		return (1);
	else
		return (1 + ft_putadr_l(n / 16));
}

int	ft_putadr_len(va_list args)
{
	va_list 	argx;
	unsigned long	n;
	void		*adr;
	int		len;

	va_copy(argx, args);
	adr = va_arg(argx, void*);
	if (adr == NULL)
		return (5);
	else
	{
		n = (unsigned long)adr;
		len = ft_putadr_l(n);
		return (len + 2);
	}
}
