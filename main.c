#include "./includes/ft_printf.h"

int main()
{
	char s2[] = "salut ca va bien";
	char c = 'a';
	char	*s;


	printf(" 1 - %s and |%*s| and |%*s| \n",  s, 20,  s, -20, s);
	ft_printf(" 1 - %s and |%*s| and |%*s| \n", s, 20, s, -20, s);

	
	ft_printf("1 - |%0*.*s|\n",-20, -5, s2);
	printf("1 - |%0*.*s|\n",-20, -5, s2);

	ft_printf("1 - |%*.*d|\n", -20, -5, 50);
	printf("1 - |%*.*d|\n", -20, -5, 50);

	
	ft_printf("1 - |%20.*s|\n", -5, s2);
	printf("1 - |%20.*s|\n", -5, s2);

	ft_printf("1 - |%*.*s|\n", 20, -5, s2);
	printf("1 - |%*.*s|\n", 20, -5, s2);

	ft_printf("2 - |%*s|\n", -20, s2);
	printf("2 - |%*s|\n", -20, s2);

	ft_printf("3 - |%*.*s|\n", -20, -5, s2);
	printf("3 - |%*.*s|\n", -20, -5, s2);
	
	ft_printf("1 - |%*.*d|\n", 10, -5, 50);
	printf("1 - |%*.*d|\n", 10, -5, 50);

	ft_printf("1 - |%.*d|\n",  -5, 50);
	printf("1 - |%.*d|\n", -5, 50);

	ft_printf("1 - |%*d| and |%*d|\n",5, 50, -5, 50);
	printf("1 - [%*d| and |%*d|\n", 5 , 50, -5, 50);

	printf("\n\n----------NUMBERS----------\n\n");

	printf("ret = %d -> ", printf("1 - |%d|\n", 50));
	ft_printf("ret = %d -> ", ft_printf("1 - |%d|\n", 50));

	ft_printf("ret = %d -> ", ft_printf("2 - |%-.10d|\n", 50));
	printf("ret = %d -> ", printf("2 - |%-.10d|\n", 50));

	ft_printf("ret = %d -> ", ft_printf("3 - |%0.10d|\n", 50));
	printf("ret = %d -> ", printf("3 - |%0.10d|\n\n", 50));

	ft_printf("ret = %d -> ", ft_printf("4 - |%.010d|\n", 50));
	printf("ret = %d -> ", printf("4 - |%.010d|\n\n", 50));

	ft_printf("ret = %d -> ", ft_printf("5 - |%-*d|\n", 10, 50));
	printf("ret = %d -> ", printf("5 - |%-*d|\n\n", 10, 50));

	ft_printf("ret = %d -> ", ft_printf("6 - |%.*d|\n", 10, 50));
	printf("ret = %d -> ", printf("6 - |%.*d|\n\n", 10, 50));

	ft_printf("ret = %d -> ", ft_printf("7 - |%*.d|\n", 10, 50));
	printf("ret = %d -> ", printf("7 - |%*.d|\n\n", 10, 50));

	ft_printf("ret = %d -> ", ft_printf("8 - |%0*d|\n", 10, 50));
	printf("ret = %d -> ", printf("9 - |%0*d|\n\n", 10, 50));

	ft_printf("ret = %d -> ", ft_printf("10 - |%-.010d|\n", 50));
	printf("ret = %d -> ", printf("10 - |%-.010d|\n\n", 50));

	ft_printf("ret = %d -> ", ft_printf("11 - |%-.010d|\n", 50));
	printf("ret = %d -> ", printf("11 - |%-.010d|\n\n", 50));

	ft_printf("ret = %d -> ", ft_printf("12 - |%*.0d|\n", 10, 50));
	printf("ret = %d -> ", printf("12 - |%*.0d|\n\n", 10, 50));

	ft_printf("ret = %d -> ", ft_printf("13 - |%0*.d|\n", 10, 50));
	printf("ret = %d -> ", printf("13 - |%0*.d|\n\n", 10, 50));


	printf("ret = %d -> ", printf("\n\n----------STRINGS----------\n\n"));

	ft_printf("ret = %d -> ", ft_printf("1 - %.10s|\n", s2));
	printf("ret = %d -> ", printf("1 - %.10s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("2 - %020.5s|\n", s2));
	printf("ret = %d -> ", printf("2 - %020.5s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("2 - %-10s|\n", s2));
	printf("ret = %d -> ", printf("2 - %-10s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("3 - %-.5s|\n", s2));
	printf("ret = %d -> ", printf("3 - %-.5s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("4 - %.010s|\n", s2));
	printf("ret = %d -> ", printf("4 - %.010s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("5 - %.40s|\n", s2));
	printf("ret = %d -> ", printf("5 - %.40s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("6 - %-40s|\n", s2));
	printf("ret = %d -> ", printf("6 - %-40s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("7 - %-.40s|\n", s2));
	printf("ret = %d -> ", printf("7 - %-.40s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("8 - %.040s|\n", s2));
	printf("ret = %d -> ", printf("8 - %.040s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("9 - %.*s|\n", 10, s2));
	printf("ret = %d -> ", printf("9 - %.*s|\n\n", 10, s2));

	ft_printf("ret = %d -> ", ft_printf("10 - %-*s|\n", 10, s2));
	printf("ret = %d -> ", printf("10 - %-*s|\n\n", 10, s2));

	ft_printf("ret = %d -> ", ft_printf("11 - |%*.s|\n", 10, s2));
	printf("ret = %d -> ", printf("11 - |%*.s|\n\n", 10, s2));

	ft_printf("ret = %d -> ", ft_printf("12 - %.*s|\n", 10, s2));
	printf("ret = %d -> ", printf("12 - %.*s|\n\n", 10, s2));

	ft_printf("ret = %d -> ", ft_printf("13 - %.50s|\n", s2));
	printf("ret = %d -> ", printf("13 - %.50s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("14 - %-50s|\n", s2));
	printf("ret = %d -> ", printf("14 - %-50s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("15 - %-.50s|\n", s2));
	printf("ret = %d -> ", printf("15 - %-.50s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("16 - %.050s|\n", s2));
	printf("ret = %d -> ", printf("16 - %.050s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("17 - %.*s|\n", 50, s2));
	printf("ret = %d -> ", printf("17 - %.*s|\n\n", 50, s2));

	ft_printf("ret = %d -> ", ft_printf("18 - %-*s|\n", 50, s2));
	printf("ret = %d -> ", printf("18 - %-*s|\n\n", 50, s2));

	ft_printf("ret = %d -> ", ft_printf("19 - %*.s|\n", 50, s2));
	printf("ret = %d -> ", printf("19 - %*.s|\n\n", 50, s2));

	ft_printf("ret = %d -> ", ft_printf("19 - |%*.0s|\n", 50, s2));
	printf("ret = %d -> ", printf("19 - |%*.0s|\n\n", 50, s2));

	ft_printf("ret = %d -> ", ft_printf("19 - %*.2s|\n", 50, s2));
	printf("ret = %d -> ", printf("19 - %*.2s|\n\n", 50, s2));

	ft_printf("ret = %d -> ", ft_printf("20 - %.*s|\n", 10, s2));
	printf("ret = %d -> ", printf("20 - %.*s|\n\n", 10, s2));

	printf("ret = %d -> ", printf("\n\n----------CHARS----------\n\n"));

	
	ft_printf("ret = %d -> ", ft_printf("%*c|\n", 50, c));
	printf("ret = %d -> ", printf("%*c|\n\n", 50, c));

	ft_printf("ret = %d -> ", ft_printf("%-10c|\n", c));
	printf("ret = %d -> ", printf("%-10c|\n\n", c));

	ft_printf("ret = %d -> ", ft_printf("%*.c|\n", 50, c));
	printf("ret = %d -> ", printf("%*.c|\n\n", 50, c));


	printf("ret = %d -> ", printf("\n\n----------HEXA UNSIGNED INT----------\n\n"));
	
	ft_printf("ret = %d -> ", ft_printf("%x , %x, |%X|, |%X|\n", 31, -31, 31, -31));
	printf("ret = %d -> ", printf("%x , %x, %X, %X\n\n\n", 31, -31, 31, -31));
	
	ft_printf("ret = %d -> ", ft_printf(" 1 - %x\n", 5842));
	printf("ret = %d -> ", printf(" 1 - %x\n\n", 5842));

	ft_printf("ret = %d -> ", ft_printf("2 - |%.10x|\n", 5842));
	printf("ret = %d -> ", printf("2 - |%.10x|\n\n", 5842));

	ft_printf("ret = %d -> ", ft_printf("3 - |%-10x| Hi \n", 5842));
	printf("ret = %d -> ", printf("3 - |%-10x| Hi \n\n", 5842));

	ft_printf("ret = %d -> ", ft_printf("4 - |%*X|\n", 10, 5842));
	printf("ret = %d -> ", printf("4 - |%*X|\n\n", 10, 5842));

	ft_printf("ret = %d -> ", ft_printf("5 - |%-.10x| Hi \n", 5842));
	printf("ret = %d -> ", printf("5 - |%-.10x| Hi\n\n", 5842));

	ft_printf("ret = %d -> ", ft_printf("6 - |%0.x|\n", 5842));
	printf("ret = %d -> ", printf("6 - |%0.x|\n\n", 5842));

	ft_printf("ret = %d -> ", ft_printf("7 - |%.*x|\n", 10, 5842));
	printf("ret = %d -> ", printf("7 - |%.*x|\n\n", 10, 5842));

	ft_printf("ret = %d -> ", ft_printf("8 - |%X|\n", 9999999));
	printf("ret = %d -> ", printf("8 - |%X|\n\n", 9999999));


	
	printf("ret = %d -> ", printf("\n\n----------UNSIGNED INT----------\n\n"));

	ft_printf("ret = %d -> ", ft_printf("1 - %-.10u\n", 2000546511));
	printf("ret = %d -> ", printf("1 - %-.10u\n\n", 2000546511));

	ft_printf("ret = %d -> ", ft_printf("2 - %0.10u\n", 2000546511));
	printf("ret = %d -> ", printf("2 - %0.10u\n\n", 2000546511));

	ft_printf("ret = %d -> ", ft_printf("3 - %.030u\n", 2000546511));
	printf("ret = %d -> ", printf("3 - %.030u\n\n", 2000546511));

	ft_printf("ret = %d -> ", ft_printf("4 - %-*u\n", 30, 2000546511));
	printf("ret = %d -> ", printf("4 - %-*u\n\n", 30, 2000546511));


	printf("ret = %d -> ", printf(" \n \n  ----------- PTR  --------------- \n \n"));
	
	ft_printf("ret = %d -> ", ft_printf("1 - |%p|\n", &c));
	printf("ret = %d -> ", printf("1 - |%p|\n\n", &c));
	
	ft_printf("ret = %d -> ", ft_printf("2 - |%*p|\n",20, &c));
	printf("ret = %d -> ", printf("2 - |%*p|\n\n",20, &c));

	ft_printf("ret = %d -> ", ft_printf("2 - |%-20p|\n", &c));
	printf("ret = %d -> ", printf("2 - |%-20p|\n\n", &c));

	ft_printf("ret = %d -> ", ft_printf("2 - |%-20.5p|\n", &c));
	printf("ret = %d -> ", printf("2 - |%-20.5p|\n\n", &c));

	ft_printf("ret = %d -> ", ft_printf("1 - |%10d| and |%*d|\n", 55, 10, 55));
	printf("ret = %d -> ", printf("1 - |%10d| and |%*d|\n", 55, 10, 55));

	printf("ret = %d -> ", printf("\n \n ---------------------- m ---------------- \n \n"));
	
	ft_printf("ret = %d -> ", ft_printf("1 - %% \n"));
	printf("ret = %d -> ", printf("1 - %% \n"));

	ft_printf("ret = %d -> ", ft_printf("1 - %15% \n"));
	printf("ret = %d -> ", printf("1 - [%15%] \n"));

	ft_printf("ret = %d -> ", ft_printf("1 - %010% \n"));
	printf("ret = %d -> ", printf("1 - [%010%] \n"));

	ft_printf("ret = %d -> ", ft_printf("1 - %*% \n", 10));
	printf("ret = %d -> ", printf("1 - [%*%] \n", 10));




	printf("\n\n----------SECOND PART----------\n\n");

	printf("\n\n----------NUMBERS----------\n\n");

	printf("ret = %d -> ", printf("1 - |%d|\n", -50));
	ft_printf("ret = %d -> ", ft_printf("1 - |%d|\n", -50));

	ft_printf("ret = %d -> ", ft_printf("2 - |%-.10d|\n", -50));
	printf("ret = %d -> ", printf("2 - |%-.10d|\n", -50));

	ft_printf("ret = %d -> ", ft_printf("3 - |%0.10d|\n", -50));
	printf("ret = %d -> ", printf("3 - |%0.10d|\n\n", -50));

	ft_printf("ret = %d -> ", ft_printf("4 - |%.010d|\n", -50));
	printf("ret = %d -> ", printf("4 - |%.010d|\n\n", -50));

	ft_printf("ret = %d -> ", ft_printf("5 - |%-*d|\n", 10, -50));
	printf("ret = %d -> ", printf("5 - |%-*d|\n\n", 10, -50));

	ft_printf("ret = %d -> ", ft_printf("6 - |%.*d|\n", 10, -50));
	printf("ret = %d -> ", printf("6 - |%.*d|\n\n", 10, -50));

	ft_printf("ret = %d -> ", ft_printf("7 - |%*.d|\n", 10, -50));
	printf("ret = %d -> ", printf("7 - |%*.d|\n\n", 10, -50));

	ft_printf("ret = %d -> ", ft_printf("8 - |%0*d|\n", 10, -50));
	printf("ret = %d -> ", printf("8 - |%0*d|\n\n", 10, -50));

	ft_printf("ret = %d -> ", ft_printf("10 - |%-.010d|\n", -50));
	printf("ret = %d -> ", printf("10 - |%-.010d|\n\n", -50));

	ft_printf("ret = %d -> ", ft_printf("11 - |%-.010d|\n", -50));
	printf("ret = %d -> ", printf("11 - |%-.010d|\n\n", -50));

	ft_printf("ret = %d -> ", ft_printf("12 - |%*.0d|\n", 10, -50));
	printf("ret = %d -> ", printf("12 - |%*.0d|\n\n", 10, -50));

	ft_printf("ret = %d -> ", ft_printf("13 - |%0*.d|\n", 10, -50));
	printf("ret = %d -> ", printf("13 - |%0*.d|\n\n", 10, -50));


	printf("ret = %d -> ", printf("\n\n----------STRINGS----------\n\n"));

	ft_printf("ret = %d -> ", ft_printf("1 - %.10s|\n", s2));
	printf("ret = %d -> ", printf("1 - %.10s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("2 - %020.5s|\n", s2));
	printf("ret = %d -> ", printf("2 - %020.5s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("2 - %-10s|\n", s2));
	printf("ret = %d -> ", printf("2 - %-10s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("3 - %-.5s|\n", s2));
	printf("ret = %d -> ", printf("3 - %-.5s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("4 - %.010s|\n", s2));
	printf("ret = %d -> ", printf("4 - %.010s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("5 - %.40s|\n", s2));
	printf("ret = %d -> ", printf("5 - %.40s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("6 - %-40s|\n", s2));
	printf("ret = %d -> ", printf("6 - %-40s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("7 - %-.40s|\n", s2));
	printf("ret = %d -> ", printf("7 - %-.40s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("8 - %.040s|\n", s2));
	printf("ret = %d -> ", printf("8 - %.040s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("9 - %.*s|\n", 10, s2));
	printf("ret = %d -> ", printf("9 - %.*s|\n\n", 10, s2));

	ft_printf("ret = %d -> ", ft_printf("10 - %-*s|\n", 10, s2));
	printf("ret = %d -> ", printf("10 - %-*s|\n\n", 10, s2));

	ft_printf("ret = %d -> ", ft_printf("11 - |%*.s|\n", 10, s2));
	printf("ret = %d -> ", printf("11 - |%*.s|\n\n", 10, s2));

	ft_printf("ret = %d -> ", ft_printf("12 - %.*s|\n", 10, s2));
	printf("ret = %d -> ", printf("12 - %.*s|\n\n", 10, s2));

	ft_printf("ret = %d -> ", ft_printf("13 - %.50s|\n", s2));
	printf("ret = %d -> ", printf("13 - %.50s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("14 - %-50s|\n", s2));
	printf("ret = %d -> ", printf("14 - %-50s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("15 - %-.50s|\n", s2));
	printf("ret = %d -> ", printf("15 - %-.50s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("16 - %.050s|\n", s2));
	printf("ret = %d -> ", printf("16 - %.050s|\n\n", s2));

	ft_printf("ret = %d -> ", ft_printf("17 - %.*s|\n", 50, s2));
	printf("ret = %d -> ", printf("17 - %.*s|\n\n", 50, s2));

	ft_printf("ret = %d -> ", ft_printf("18 - %-*s|\n", 50, s2));
	printf("ret = %d -> ", printf("18 - %-*s|\n\n", 50, s2));

	ft_printf("ret = %d -> ", ft_printf("19 - %*.s|\n", 50, s2));
	printf("ret = %d -> ", printf("19 - %*.s|\n\n", 50, s2));

	ft_printf("ret = %d -> ", ft_printf("19 - |%*.0s|\n", 50, s2));
	printf("ret = %d -> ", printf("19 - |%*.0s|\n\n", 50, s2));

	ft_printf("ret = %d -> ", ft_printf("19 - %*.2s|\n", 50, s2));
	printf("ret = %d -> ", printf("19 - %*.2s|\n\n", 50, s2));

	ft_printf("ret = %d -> ", ft_printf("20 - %.*s|\n", 10, s2));
	printf("ret = %d -> ", printf("20 - %.*s|\n\n", 10, s2));

	printf("ret = %d -> ", printf("\n\n----------CHARS----------\n\n"));

	
	ft_printf("ret = %d -> ", ft_printf("%*c|\n", 50, c));
	printf("ret = %d -> ", printf("%*c|\n\n", 50, c));

	ft_printf("ret = %d -> ", ft_printf("%-10c|\n", c));
	printf("ret = %d -> ", printf("%-10c|\n\n", c));

	ft_printf("ret = %d -> ", ft_printf("%*.c|\n", 50, c));
	printf("ret = %d -> ", printf("%*.c|\n\n", 50, c));


	printf("ret = %d -> ", printf("\n\n----------HEXA UNSIGNED INT----------\n\n"));
	
	ft_printf("ret = %d -> ", ft_printf("%x , %x, |%X|, |%X|\n", 31, -31, 31, -31));
	printf("ret = %d -> ", printf("%x , %x, %X, %X\n\n\n", 31, -31, 31, -31));
	
	ft_printf("ret = %d -> ", ft_printf(" 1 - %x\n", -315));
	printf("ret = %d -> ", printf(" 1 - %x\n\n", -315));

	ft_printf("ret = %d -> ", ft_printf("2 - |%.10x|\n", -315));
	printf("ret = %d -> ", printf("2 - |%.10x|\n\n", -315));

	ft_printf("ret = %d -> ", ft_printf("3 - |%-10x| Hi \n", -315));
	printf("ret = %d -> ", printf("3 - |%-10x| Hi \n\n", -315));

	ft_printf("ret = %d -> ", ft_printf("4 - |%*X|\n", 10, -315));
	printf("ret = %d -> ", printf("4 - |%*X|\n\n", 10, -315));

	ft_printf("ret = %d -> ", ft_printf("5 - |%-.10x| Hi \n", -315));
	printf("ret = %d -> ", printf("5 - |%-.10x| Hi\n\n", -315));

	ft_printf("ret = %d -> ", ft_printf("6 - |%0.x|\n", -315));
	printf("ret = %d -> ", printf("6 - |%0.x|\n\n", -315));

	ft_printf("ret = %d -> ", ft_printf("7 - |%.*x|\n", 10, -315));
	printf("ret = %d -> ", printf("7 - |%.*x|\n\n", 10, -315));

	ft_printf("ret = %d -> ", ft_printf("8 - |%X|\n", 9999999));
	printf("ret = %d -> ", printf("8 - |%X|\n\n", 9999999));


	
	printf("ret = %d -> ", printf("\n\n----------UNSIGNED INT----------\n\n"));

	ft_printf("ret = %d -> ", ft_printf("1 - %-.10u\n", 2000546511));
	printf("ret = %d -> ", printf("1 - %-.10u\n\n", 2000546511));

	ft_printf("ret = %d -> ", ft_printf("2 - %0.10u\n", 2000546511));
	printf("ret = %d -> ", printf("2 - %0.10u\n\n", 2000546511));

	ft_printf("ret = %d -> ", ft_printf("3 - %.030u\n", 2000546511));
	printf("ret = %d -> ", printf("3 - %.030u\n\n", 2000546511));

	ft_printf("ret = %d -> ", ft_printf("4 - %-*u\n", 30, 2000546511));
	printf("ret = %d -> ", printf("4 - %-*u\n\n", 30, 2000546511));


	printf("ret = %d -> ", printf(" \n \n  ----------- PTR  --------------- \n \n"));
	
	ft_printf("ret = %d -> ", ft_printf("1 - |%p|\n", &c));
	printf("ret = %d -> ", printf("1 - |%p|\n\n", &c));
	
	ft_printf("ret = %d -> ", ft_printf("2 - |%*p|\n",20, &c));
	printf("ret = %d -> ", printf("2 - |%*p|\n\n",20, &c));

	ft_printf("ret = %d -> ", ft_printf("2 - |%-20p|\n", &c));
	printf("ret = %d -> ", printf("2 - |%-20p|\n\n", &c));

	ft_printf("ret = %d -> ", ft_printf("2 - |%-20.5p|\n", &c));
	printf("ret = %d -> ", printf("2 - |%-20.5p|\n\n", &c));

	ft_printf("ret = %d -> ", ft_printf("1 - |%10d| and |%*d|\n", 55, 10, 55));
	printf("ret = %d -> ", printf("1 - |%10d| and |%*d|\n", 55, 10, 55));

	printf("ret = %d -> ", printf("\n \n ---------------------- m ---------------- \n \n"));
	
	ft_printf("ret = %d -> ", ft_printf("1 - %% \n"));
	printf("ret = %d -> ", printf("1 - %% \n"));

	ft_printf("ret = %d -> ", ft_printf("1 - %15% \n"));
	printf("ret = %d -> ", printf("1 - [%15%] \n"));

	ft_printf("ret = %d -> ", ft_printf("1 - %010% \n"));
	printf("ret = %d -> ", printf("1 - [%010%] \n"));

	ft_printf("ret = %d -> ", ft_printf("1 - %*% \n", 10));
	printf("ret = %d -> ", printf("1 - [%*%] \n", 10));

	return (0);
}
