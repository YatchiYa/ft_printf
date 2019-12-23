#include "../includes/ft_printf.h"

void	ft_putstr(char *str, int *size)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], size);
		i++;
	}
}
