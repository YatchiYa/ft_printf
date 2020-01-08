#include "ft_printf.h"

int	main()
{

	printf("[%*.*d] \n", -6, -7, 0);
	ft_printf("[%*.*d] \n", -6, -7, 0);

	// printf("[%0.0d]\n", 0);
	// ft_printf("[%0.0d]\n", 0);

	// printf("[%020.4d]\n", 0);
	// ft_printf("[%020.4d]\n", 0);

	// printf("[%.*d] \n", -3, 0);
	// ft_printf("[%.*d] \n", -3, 0);

	// printf("[%.*d] \n", 3, 0);
	// ft_printf("[%.*d] \n", 3, 0);

	// printf("[%-*.0d]\n", 12, 0);
	// ft_printf("[%-*.0d]\n", 12, 0);
	// printf("[%-12.*d]\n", 10, 0);
	// ft_printf("[%-12.*d]\n", 10, 0);
	// printf("[%-12.*d]\n", -10, 0);
	// ft_printf("[%-12.*d]\n", -10, 0);

	// printf("[%*d]\n", 10, 0);
	// ft_printf("[%*d]\n", 10, 0);


	// printf("[%*.d]\n", 10, 0);
	// ft_printf("[%*.d]\n", 10, 0);

	// printf("[%*.3d]\n", 10, 0);
	// ft_printf("[%*.3d]\n", 10, 0);

	// printf("[%10d]\n", 0);
	// ft_printf("[%10d]\n", 0);


	// printf("[%-12d]\n", 0);
	// ft_printf("[%-12d]\n", 0);


	// printf("[%-*d]\n", 12, 0);
	// ft_printf("[%-*d]\n", 12, 0);


	// printf("[%-12.*d]\n", -9, 0);
	// ft_printf("[%-12.*d]\n", -9, 0);


	// printf("[%-.3d] \n", 0);
	// ft_printf("[%-.3d] \n", 0);


	// printf("[%017.*d] \n", -10, 5);
	// ft_printf("[%017.*d] \n", -10, 5);

	// printf("[%014.3d] \n", 2147483647);
	// ft_printf("[%014.3d] \n", 2147483647);

	// printf("[l0d%013.4d]\n", 2147483647);
	// ft_printf("[l0d%013.4d]\n", 2147483647);


}
