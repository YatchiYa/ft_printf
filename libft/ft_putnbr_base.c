
#include "../includes/ft_printf.h"

void	ft_putnbr_base(int nb, char *str, int *p)
{
	unsigned int	nbr;
	int		length;

	if (nb < 0)
	{
		ft_putchar('-', p);
		nbr = nb * -1;
	}
	else
		nbr = nb;
	length = ft_strlen(str);
	if (nbr >= length)
		ft_putnbr_base(nbr / length, str, p);
	ft_putchar(str[nbr % length], p);
}
