#include "../includes/ft_printf.h"

void	ft_parse_stars(char *str, va_list args, int *p ,int *size)
{
	int		k;
	t_flags		flags;

	inti_struct(&flags);
	k = 0;
	k += ft_fill_width(args, &str[k], &flags);
	if (str[k] == '.')
		k+= ft_fill_precision(args, &str[k + 1], &flags) + 1;
	*p = *p + k;
	ft_digits_parsing(str + k , args, p, size, flags);
}
