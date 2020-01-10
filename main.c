#include "ft_printf.h"

int	main()
{

	printf(" ---------------- unsigned -------------- \n \n");

	printf("[%-.0u] \n", 0);
	ft_printf("[%-.0u] \n", 0);


	printf("[%0*.0u]\n", -1, 0);
	ft_printf("[%0*.0u]\n", -1, 0);


	printf("[%-*.0u] \n", -1, 0);
	ft_printf("[%-*.0u] \n", -1, 0);

	printf("[%020.*u] \n", -10, -2147483647);
	ft_printf("[%020.*u] \n", -10, -2147483647);
	printf("[%.0u] \n", 0);
	ft_printf("[%.0u] \n", 0);
	printf("[%07.0u | njK%-14uO%*uY54H7GcA] \n", 0, 0, 1, 2147483647);
	ft_printf("[%07.0u | njK%-14uO%*uY54H7GcA] \n", 0, 0, 1, 2147483647);
	printf(" [%*.1u] \n", 2, 0);
	ft_printf(" [%*.1u] \n", 2, 0);
	printf("[%0.0u] \n", 0);
	ft_printf("[%0.0u] \n", 0);
	printf("[%07.3u] \n", 0);
	ft_printf("[%07.3u] \n", 0);
	printf("[%.0u%0uNpQlqO%-u%08u] \n", 0, 0, -2147483647, 0);
	printf("[%.0u%0uNpQlqO%-u%08u] \n", 0, 0, -2147483647, 0);
	printf("[%018.1u%-19.4u] \n",  724061404, 5);
	ft_printf("[%018.1u%-19.4u] \n",  724061404, 5);
	printf("[%.5u]\n", 0);
	ft_printf("[%.5u]\n", 0);
	printf("[%15u] \n", -2147483647);
	ft_printf("[%15u] \n", -2147483647);
	printf("[%16.0u] \n", 0);
	ft_printf("[%16.0u] \n", 0);
	printf("[%16.u] \n", 0);
	ft_printf("[%16.u] \n", 0);
	printf("[%16.*u] \n", -5, 0);
	ft_printf("[%16.*u] \n", -5, 0);
	printf("[%-12u] \n", 0);
	ft_printf("[%-12u] \n", 0);
	printf("{%016u} \n", 252764855);
	ft_printf("{%016u} \n", 252764855);
	printf("[%*.*u | %019.*u]\n", 20, -5, 0, -10, 0);
	ft_printf("[%*.*u | %019.*u]\n", 20, -5, 0, -10, 0);
	printf("[%20.*u | %019.*u]\n",  -5, 0, -10, 0);
	ft_printf("[%20.*u | %019.*u]\n",  -5, 0, -10, 0);









	// printf("[%*.*d] \n", -6, -7, 0);
	// ft_printf("[%*.*d] \n", -6, -7, 0);

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
