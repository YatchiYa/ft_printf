#include "../includes/ft_printf.h"

void	ft_digits_parsing_adr(char *str, va_list args, int *p, int *size, t_flags flags)
{
	void		*adr;
	unsigned long	number;
	int		n;

	n = ft_str_length_format(str[0], args);
	adr = va_arg(args, void*);
	number = (unsigned long)(adr);
	if (flags.blanks == 1 && flags.precision != -1)
	{
			ft_print_elem(flags.width, flags.precision > n ? 
					flags.precision : n, ' ', size);
			ft_print_elem(flags.precision, n, '0', size);
	}
	else
			ft_print_elem(flags.width, n, ' ', size);
	adr == NULL ? ft_putstr("(nil)", size) : ft_putstr("0x", p);
	adr != NULL ? *p = *p - 2 : 0;
	adr != NULL ? ft_putadr(number, size) : 0;
}

void	ft_minus_parse_adr(char *str, va_list args, int *p, int *size, t_flags flags)
{
	void		*adr;
	unsigned long	number;
	int	n;

	n = ft_str_length_format(str[0], args);
	adr = va_arg(args, void*);
	number = (unsigned long)(adr);
	if (flags.blanks == 1 && flags.precision != -1)
	{
			ft_print_elem(flags.precision, n, '0', size);
			adr == NULL ? ft_putstr("(nil)", size) : ft_putstr("0x", p);
			adr != NULL ? *p = *p - 2 : 0;
			adr != NULL ? ft_putadr(number, size) : 0;
			//ft_putstr("0x", size);
			//ft_putadr(number, size);
			ft_print_elem(flags.width, 
					flags.precision > n ? flags.precision : n, ' ', size);
	}
	else
	{
			adr == NULL ? ft_putstr("(nil)", size) : ft_putstr("0x", p);
			adr != NULL ? *p = *p - 2 : 0;
			adr != NULL ? ft_putadr(number, size) : 0;
			//ft_putstr("0x", size);
			//ft_putadr(number, size);
			ft_print_elem(flags.width, n, ' ', size);
	}
}

void	ft_zero_parsing_adr(char *str, va_list args, int *p, int *size, t_flags flags)
{
	void		*adr;
	unsigned long	number;
	int	n;

	n = ft_str_length_format(str[0], args);
	adr = va_arg(args, void*);
	number = (unsigned long)(adr);
	if (flags.precision != -1)
	{
			ft_print_elem(flags.width, 
				flags.precision > n ? flags.precision : n, ' ', size);
			ft_print_elem(flags.precision, n, '0', size);
	}
	else if (flags.precision == -1 && flags.blanks == 0)
		adr != NULL ? ft_print_elem(flags.width, n, '0', size) : 
			ft_print_elem(flags.width, n, ' ', size);
	//ft_putstr("0x", size);
	//ft_putadr(number, size);
	adr == NULL ? ft_putstr("(nil)", size) : ft_putstr("0x", p);
	adr != NULL ? *p = *p - 2 : 0;
	adr != NULL ? ft_putadr(number, size) : 0;
}
