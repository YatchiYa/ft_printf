#include "../includes/ft_printf.h"

void	ft_putchar(char c, int *p)
{
	*p = *p + 1;
	write(1, &c, 1);
}
