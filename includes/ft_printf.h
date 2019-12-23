#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <math.h>
# include <stdarg.h>
# include <stdint.h>
# include <inttypes.h>
# include "./libft.h"

# define HEXA_BASE "0123456789abcdef"
# define HEXA_BASE_M "0123456789ABCDEF"
# define OCTAL_BASE "01234567"
# define PARSE_LETTERS "diucspxX%"
# define PARSE_FLAGS "-O.*"

typedef struct	s_flags
{
	int	width;
	int	precision;
	int	blanks;
}		t_flags;

void		ft_parse_int(va_list args, int *i);
int				ft_parse_int_g(va_list args);
void	ft_digits_parsing_id(char *str, va_list args, int *p, int *size, t_flags flags);
void	ft_minus_parse_id(char *str, va_list args, int *p, int *size, t_flags flags);
void	ft_zero_parsing_id(char *str, va_list args, int *p, int *size, t_flags flags);

void		ft_parse_uint(va_list args, int *p);
void	ft_minus_parse_u(char *str, va_list args, int *p, int *size, t_flags flags);
void	ft_zero_parsing_u(char *str, va_list args, int *p, int *size, t_flags flags);
void	ft_digits_parsing_u(char *str, va_list args, int *p, int *size, t_flags flags);

void		ft_parse_char(va_list args, int *size);
void		ft_parse_char(va_list args, int *size);
void		ft_parse_str(va_list args, int *size);
void		ft_parse_ptr(va_list args, int *size);
void		ft_parse_hexa(va_list args, int *size);
void		ft_parse_hexa_m(va_list args, int *size);
void		ft_parse_zero(char *str, va_list args, int *p, int *size);
void		ft_parse_blanks(char *str, va_list args, int *p, int *size);
void		ft_parse_zero(char *str, va_list args, int *p, int *size);
void		ft_parse_format(char *str, va_list argsr, int *p, int *size);
int             ft_printf(const char *str, ...);
int				ft_str_length_format(char c, va_list args);
int				ft_is_flags(char c);
int				ft_is_type(char c);


void		ft_print_elem(int w, int p, char c, int *size);
void		ft_zero_parsing(char *str, va_list args, int *p, int *size, t_flags flags);
void		ft_digits_parsing(char *str, va_list args, int *p, int *size, t_flags flags);
void		ft_parse_digits(char *str, va_list args, int *p, int *size);
void	inti_struct(t_flags *flags);

void		ft_parse_minus(char *str, va_list args, int *p, int *size);
void		ft_minus_parsing(char *str, va_list args, int *p, int *size, t_flags flags);
void		clear_struct(t_flags *flags);
void		ft_parse_stars(char *str, va_list args, int *p, int *size);
void		ft_parse_point(char *str, va_list args, int *p, int *size);
int	ft_fill_width(va_list args, char *str, t_flags *flags);
int	ft_fill_precision(va_list args, char *str, t_flags *flags);

#endif
