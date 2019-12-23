#include "../includes/ft_printf.h"

void	ft_print_elem(int w, int p, char c, int *size)
{
	while (w > p)
	{
		ft_putchar(c, size);
		p++;
	}
}

void	ft_init_tab(char *tab)
{
	int	i;

	tab[255] == '\0';
	while (i < 255)
	{
		tab[i] = -1;
		i++;
	}
}
void	free_tab(char *tab)
{
	free(tab);
}
