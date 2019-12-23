#include "../includes/ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int		i;
	int		size;
	va_list	args;

	i = 0;
	size = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1 ] != '\0')
		{
			i++;
			ft_parse_format((char *)&str[i], args, &i, &size);		
		}
		else
		{
			ft_putchar(str[i], &size);
			i++;
		}
	}
	va_end(args);
	return (size);
}
