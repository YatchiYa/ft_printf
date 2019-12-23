#include "../includes/ft_printf.h"

void	addelem_tab(char *str, char c, int *i)
{
	str[*i] = c;
	*i = *i + 1; 
}

int	ft_hexalen_l(unsigned long n)
{
	if (n < 16)
		return (1);
	else
		return (1 + ft_hexalen_l(n / 16));
}

int	ft_hexalen(va_list args)
{
	va_list 	argx;
	unsigned long	n;
	void		*adr;
	int		len;

	len = 0;
	va_copy(argx, args);
	adr = va_arg(argx, void*);
	n = (unsigned long)adr;
	len = ft_hexalen_l(n);
	//printf(" - debug len = %d \n", len);
	return (len);
}
