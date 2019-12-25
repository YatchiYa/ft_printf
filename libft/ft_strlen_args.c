#include "../includes/ft_printf.h"

int	ft_strlen_args(va_list argx)
{
	char	*str;
	va_list	args;

	va_copy(args, argx);
	str = va_arg(args, char*);
	if (str == NULL)
		return (6);
	else
		return (ft_strlen(str));
}
