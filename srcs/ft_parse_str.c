#include "../includes/ft_printf.h"

void		ft_parse_str(va_list args, int *size)
{
	char	*str;
	char	*tmp;

	tmp = va_arg(args, char*);
	str = (tmp == NULL) ? ft_strdup("(null)") : ft_strdup(tmp);
	ft_putstr(str, size);
	free(str);
}

void	ft_digits_parsing_s(va_list args, int *size, t_flags flags)
{
	char	*s;
	int		i;
	char	*t;

	t = va_arg(args, char*);
	s = (t == NULL) ? ft_strdup("(null)") : ft_strdup(t);
	i = 0;
	if (flags.precision != -1)
	{
		ft_print_elem(flags.width, flags.precision, ' ', size);
		while (s[i] && i < flags.precision)
		{
			ft_putchar(s[i], size);
			i++;
		}
	}
	else
	{
		ft_print_elem(flags.width, ft_strlen(s), ' ', size);
		ft_putstr(s, size);
	}
	free(s);
}

void	ft_minus_parse_str(va_list args, int *size, t_flags flags)
{
	char	*s;
	int		i;
	char	*t;

	t = va_arg(args, char*);
	s = (t == NULL) ? ft_strdup("(null)") : ft_strdup(t);
	i = 0;
	if (flags.precision != -1)
	{
		while (s[i] && i < flags.precision)
		{
			ft_putchar(s[i], size);
			i++;
		}
		ft_print_elem(flags.width, flags.precision, ' ', size);
	}
	else
	{
		ft_putstr(s, size);
		ft_print_elem(flags.width, ft_strlen(s), ' ', size);
	}
	free(s);
}
