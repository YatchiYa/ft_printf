#include "../includes/ft_printf.h"

int	ft_fill_width(va_list args, char *str, t_flags *flags)
{
	int		i;
	char	*tab;

	tab = (char *)malloc(sizeof(char) * 266);
	i = 0;
	while (ft_is_type(str[i]) != 1 && str[i] != '.')
	{
		if (str[i] == '*')
		{
			flags->width = ft_parse_int_g(args);
			i++;
		}
		else
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				tab[i] = str[i];
				i++;
			}
			flags->width = ft_atoi(tab);
		}
	}
	free(tab);
	return (i);
}

int	ft_fill_precision(va_list args, char *str, t_flags *flags)
{
	int	i;
	char	*tab;

	tab = (char *)malloc(sizeof(char) * 266);
	i = 0;
	while (ft_is_type(str[i]) != 1 )
	{
		if (str[i] == '*')
		{
			flags->precision = ft_parse_int_g(args);
			flags->blanks = 1;
			i++;
		}
		else
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				tab[i] = str[i];
				i++;
				
			}
			flags->precision = ft_atoi(tab);
			flags->blanks = 1;
		}
	}
	free(tab);
	return (i);
}
