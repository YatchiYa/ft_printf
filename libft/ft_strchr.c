#include "../includes/ft_printf.h"

int	ft_strchr(char c)
{
	int	i;

	i = 0;
	while (PARSE_LETTERS[i] != '\0')
	{
		if (PARSE_LETTERS[i] == c)
			return (1);
		i++;
	}
	return (0);
}
