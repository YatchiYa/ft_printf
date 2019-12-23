#include "../includes/ft_printf.h"

void	ft_parse_point(char *str, va_list args, int *p ,int *size)
{
	int		k;
	t_flags		flags;

	inti_struct(&flags);
	k = 0;
	flags.width = 0;
	k++;
	k += ft_fill_precision(args, &str[k], &flags);
	*p = *p + k;
	ft_digits_parsing(str + k, args, p, size, flags);
}
