#include "../includes/ft_printf.h"

void	ft_digits_parsing(char *str, va_list args, int *p, int *size, t_flags flags)
{
	char	t[550];
	int	number;
	int	n;

	if (str[0] == 's')
		ft_digits_parsing_s(str, args, p, size, flags);
	else if (str[0] == 'c')
		ft_digits_parsing_c(str, args, p, size, flags);
	else if (str[0] == 'u')
		ft_digits_parsing_u(str, args, p, size, flags);
	else if (str[0] == 'd' || str[0] == 'i')
		ft_digits_parsing_id(str, args, p, size, flags);
	else if (str[0] == 'x')
		ft_digits_parsing_hexa(str, args, p, size, flags);
	else if (str[0] == 'X')
		ft_digits_parsing_hexa_m(str, args, p, size, flags);
	clear_struct(&flags);
}

void	ft_parse_digits(char *str, va_list args, int *p ,int *size)
{
	int		i;
	int		j;
	char		s[3][500];
	int		k;
	t_flags		flags;

	inti_struct(&flags);
	i = 0;
	j = 0;
	k = 0;
	while (ft_is_type(str[i]) != 1)
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			s[0][j] = str[i];
			i++;
			j++;
			k++;
		}
		flags.width = ft_atoi(s[0]);
		j = 0;
		if (str[i] == '.')
		{
			i++;
			k++;
			while (str[i] >= '0' && str[i] <= '9')
			{
				s[1][j] = str[i];
				i++;
				j++;
				k++;
			}
			flags.precision = ft_atoi(s[1]);
			flags.blanks = 1;
		}
		if (str[i] == '*')
		{
			flags.precision = ft_parse_int_g(args);
			flags.blanks = 1;
			i++;
			k++;
		}
		else
			i++;
	}
	*p = *p + k;
	ft_digits_parsing(str + k, args, p, size, flags);
}
