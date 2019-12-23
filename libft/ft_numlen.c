#include "../includes/ft_printf.h"

int	ft_numlen(va_list args)
{
	int	number;
	int	i;
	va_list	tmp;

	va_copy(tmp, args);
	number = va_arg(tmp, int);
	i = 0;
	while (number != 0)
	{
		i++;
		number = number / 10;
	}
	return (i);
}

int	ft_numlen_u(va_list args)
{
	unsigned int	number;
	int	i;
	va_list	tmp;

	va_copy(tmp, args);
	number = va_arg(tmp, unsigned int);
	i = 0;
	while (number != 0)
	{
		i++;
		number = number / 10;
	}
	return (i);
}

