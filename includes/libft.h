#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>

void	ft_putchar(char c, int *p);
void	ft_putnbr(int nb, int *p);
void	ft_putnbr_u(unsigned int nb, int *p);
void	ft_putstr(char *str, int *size);
int	ft_strlen(char *str);
void	ft_putnbr_base(int nb, char *str, int *p);
int	ft_strchr(char c);
int	ft_atoi(char *str);
int		ft_strlen_args(va_list args);

int	ft_numlen(va_list args);
int	ft_numlen_u(va_list args);

int	ft_isnum(char c);
void	ft_init_tab(char *tab);
void	free_tab(char *tab);
void	ft_putadr(unsigned long n, int *p);
void	ft_putadr_maj(unsigned long n, int *p);
int		ft_putadr_len(va_list args);
int	ft_hexalen(va_list args);

#endif
