#include "../includes/ft_printf.h"

void	ft_minus_parsing(char *str, va_list args, int *p, int *size, t_flags flags)
{
	if (str[0] == 'd' || str[0] == 'i')
		ft_minus_parse_id(str, args, p, size, flags);
	if (str[0] == 'u')
		ft_minus_parsing_u(str, args, p, size, flags);

	clear_struct(&flags);
}

void	ft_parse_minus(char *str, va_list args, int *p ,int *size)
{
	int		k;
	t_flags		flags;

	inti_struct(&flags);
	k = 0;
	if (str[k] != '.')
		k += ft_fill_width(args, &str[k], &flags);
	if (str[k] == '.')
		k += ft_fill_precision(args, &str[k + 1], &flags) + 1;
	*p = *p + k + 1;
	ft_minus_parsing(str + k, args, p, size, flags);	
}
