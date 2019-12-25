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
	if (flags.precision < 0)
	{
		if (str[k] == 's')
		{
			flags.precision = -1;
			ft_minus_parsing(str + k, args, p, size, flags);
		
		}
		else
		{
			flags.precision = 0;
			ft_digits_parsing(str + k, args, p, size, flags);
		}	
	}
	else
		ft_digits_parsing(str + k, args, p, size, flags);
}
