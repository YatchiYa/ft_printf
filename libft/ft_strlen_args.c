#include "../includes/ft_printf.h"

int	ft_strlen_args(va_list args)
{
	char	*str;

	str = va_arg(args, char*);
	return (ft_strlen(str));
}
