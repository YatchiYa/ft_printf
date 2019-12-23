
#include "../includes/ft_printf.h"

void	inti_struct(t_flags *flags)
{
	flags->width = -1;
	flags->precision = -1;
	flags->blanks = 0;
}

void	clear_struct(t_flags *flags)
{
	inti_struct(flags);
}
