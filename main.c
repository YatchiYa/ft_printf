#include "./includes/ft_printf.h"

int main()
{
	char s2[] = "salut ca va bien";
	char c = 'a';
/*
	printf("\n\n----------NUMBERS----------\n\n");

	printf("1 - |%d|\n", 50);
	ft_printf("1 - |%d|\n", 50);

	ft_printf("2 - |%-.10d|\n", 50);
	printf("2 - |%-.10d|\n", 50);

	ft_printf("3 - |%0.10d|\n", 50);
	printf("3 - |%0.10d|\n\n", 50);

	ft_printf("4 - |%.010d|\n", 50);
	printf("4 - |%.010d|\n\n", 50);

	ft_printf("5 - |%-*d|\n", 10, 50);
	printf("5 - |%-*d|\n\n", 10, 50);

	ft_printf("6 - |%.*d|\n", 10, 50);
	printf("6 - |%.*d|\n\n", 10, 50);

	ft_printf("7 - |%*.d|\n", 10, -50);
	printf("7 - |%*.d|\n\n", 10, -50);

	ft_printf("8 - |%0*d|\n", 10, 50);
	printf("9 - |%0*d|\n\n", 10, 50);

	ft_printf("10 - |%-.010d|\n", 50);
	printf("10 - |%-.010d|\n\n", 50);

	ft_printf("11 - |%-.010d|\n", 50);
	printf("11 - |%-.010d|\n\n", 50);

	ft_printf("12 - |%*.0d|\n", 10, 50);
	printf("12 - |%*.0d|\n\n", 10, 50);

	ft_printf("13 - |%0*.d|\n", 10, 50);
	printf("13 - |%0*.d|\n\n", 10, 50);


	printf("\n\n----------STRINGS----------\n\n");

	ft_printf("%.10s|\n", s2);
	printf("%.10s|\n\n", s2);

 	ft_printf("%-10s|\n", s2);
	printf("%-10s|\n\n", s2);

	ft_printf("%-.10s|\n", s2);
	printf("%-.10s|\n\n", s2);

	ft_printf("%.010s|\n", s2);
	printf("%.010s|\n\n", s2);

	ft_printf("%.40s|\n", s2);
	printf("%.40s|\n\n", s2);

	ft_printf("%-40s|\n", s2);
	printf("%-40s|\n\n", s2);

	ft_printf("%-.40s|\n", s2);
	printf("%-.40s|\n\n", s2);

	ft_printf("%.040s|\n", s2);
	printf("%.040s|\n\n", s2);

	ft_printf("%.*s|\n", 10, s2);
	printf("%.*s|\n\n", 10, s2);

	ft_printf("%-*s|\n", 10, s2);
	printf("%-*s|\n\n", 10, s2);

	ft_printf("%*.s|\n", 10, s2);
	printf("%*.s|\n\n", 10, s2);

	ft_printf("%.*s|\n", 10, s2);
	printf("%.*s|\n\n", 10, s2);

	ft_printf("%.50s|\n", s2);
	printf("%.50s|\n\n", s2);

 	ft_printf("%-50s|\n", s2);
	printf("%-50s|\n\n", s2);

	ft_printf("%-.50s|\n", s2);
	printf("%-.50s|\n\n", s2);

	ft_printf("%.050s|\n", s2);
	printf("%.050s|\n\n", s2);

	ft_printf("%.*s|\n", 50, s2);
	printf("%.*s|\n\n", 50, s2);

	ft_printf("%-*s|\n", 50, s2);
	printf("%-*s|\n\n", 50, s2);

	ft_printf("%*.s|\n", 50, s2);
	printf("%*.s|\n\n", 50, s2);

	ft_printf("%.*s|\n", 10, s2);
	printf("%.*s|\n\n", 10, s2);

	printf("\n\n----------CHARS----------\n\n");

	ft_printf("%*c|\n", 50, c);
	printf("%*c|\n\n", 50, c);

	ft_printf("%-10c|\n", c);
	printf("%-10c|\n\n", c);

	ft_printf("%*.c|\n", 50, c);
	printf("%*.c|\n\n", 50, c);

*/
	printf("\n\n----------HEXA UNSIGNED INT----------\n\n");
	
	//ft_printf("%x , %x, |%X|, |%X|\n", 31, -31, 31, -31);
	//printf("%x , %x, %X, %X\n\n\n", 31, -31, 31, -31);
	
	//ft_printf(" 1 - %x\n", 5842);
	//printf(" 1 - %x\n\n", 5842);

//	ft_printf("2 - |%.10x|\n", 5842);
//	printf("2 - |%.10x|\n\n", 5842);

//	ft_printf("3 - |%-10x| Hi \n", 5842);
//	printf("3 - |%-10x| Hi \n\n", 5842);

	ft_printf("4 - |%*X|\n", 10, 5842);
	printf("4 - |%*X|\n\n", 10, 5842);

//	ft_printf("5 - |%-.10x| Hi \n", 5842);
//	printf("5 - |%-.10x| Hi\n\n", 5842);

	ft_printf("6 - |%0.x|\n", 5842);
	printf("6 - |%0.x|\n\n", 5842);

//	ft_printf("7 - |%.*x|\n", 10, 5842);
//	printf("7 - |%.*x|\n\n", 10, 5842);

	//ft_printf("8 - |%X|\n", 9999999);
	//printf("8 - |%X|\n\n", 9999999);


	/*
	printf("\n\n----------UNSIGNED INT----------\n\n");

	ft_printf("1 - %-.10u\n", 2000546511);
	printf("1 - %-.10u\n\n", 2000546511);

	ft_printf("2 - %0.10u\n", 2000546511);
	printf("2 - %0.10u\n\n", 2000546511);

	ft_printf("3 - %.030u\n", 2000546511);
	printf("3 - %.030u\n\n", 2000546511);

	ft_printf("4 - %-*u\n", 30, 2000546511);
	printf("4 - %-*u\n\n", 30, 2000546511);
*/

	return (0);
}
