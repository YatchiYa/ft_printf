#include "../includes/ft_printf.h"

int	ft_putadr_l(unsigned long n)
{
	int		i;
	char	s[3400];

	i = 0;
	if (n > 15)
	{
		ft_putadr_l((n / 16));
		ft_putadr_l((n % 16));
	}
	else if (n < 10)
	{
		i++;	
	}
	else
	{
		n == 10 ? i++ : 0;									n == 11 ? i++ : 0;							n == 12 ? i++ : 0;n == 13 ? i++ : 0;										n == 14 ? i++ : 0;										n == 15 ? i++ : 0;			
	}
	return (i);
}

int	ft_putadr_len(va_list args)
{
	va_list 	argx;
	unsigned long	n;
	void		*adr;
	int		len;

	va_copy(argx, args);
	adr = va_arg(argx, void*);
	n = (unsigned long)adr;
	len = ft_putadr_l(n);
	printf(" - debug from len adr %lu, %d -", n, len);
	return (len);
}
