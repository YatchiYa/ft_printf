
#include "../includes/ft_printf.h"
void	ft_putnbr_u(unsigned int nb, int *p)
{
	unsigned int	nbr;
	
	nbr = nb;
	if (nbr >= 10)
		ft_putnbr_u(nbr / 10, p);
	ft_putchar(nbr % 10 + 48, p);
}
