#include "../includes/ft_printf.h"

void	ft_zero_parsing(char *str, va_list args, int *p, int *size, t_flags flags)
{
	if (str[0] == 'i' || str[0] == 'd')
		ft_zero_parsing_id(str, args, p, size, flags);
	if (str[0] == 'u')
		ft_zero_parsing_u(str, args, p, size, flags);
	if (str[0] == 'x')
		ft_zero_parsing_hexa(str, args, p, size, flags);
	if (str[0] == 'X')
		ft_zero_parsing_hexa_m(str, args, p, size, flags);
	if (str[0] == 'c')
		ft_zero_parsing_c(str, args, p, size, flags);
}


void	ft_parse_zero(char *str, va_list args, int *p ,int *size)
{
	int		k;
	t_flags		flags;

	inti_struct(&flags);
	k = 0;
	if (str[k] != '.')
		k += ft_fill_width(args, &str[k], &flags);
	if (str[k] == '.')
	{
		flags.precision = 0;
		k += ft_fill_precision(args, &str[k + 1], &flags) + 1;
	}
	*p = *p + k + 1;
	ft_zero_parsing(str + k, args, p, size, flags);
}
