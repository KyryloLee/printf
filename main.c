#include <stdio.h>
// #include <locale.h>
#include "ft_printf.h"
// #include "libftprintf.a"

int main(void)
{

	ft_printf("mine=\t[%lu]\n", -42);
	printf("orig=\t[%lu]\n", -42);
  // while (1);
  return (0);
}

// int	main(void)
// {
// 	ft_printf("\n");
//   ft_printf("%%\n");
//   ft_printf("%d\n", 42);
//   ft_printf("%d%d\n", 42, 41);
//   ft_printf("%d%d%d\n", 42, 43, 44);
//   ft_printf("%ld\n", 2147483647);
//   ft_printf("%lld\n", 9223372036854775807);
//   ft_printf("%x\n", 505);
//   ft_printf("%X\n", 505);
//   ft_printf("%p\n", &ft_printf);
//   ft_printf("%20.15d\n", 54321);
//   ft_printf("%-10d\n", 3);
//   ft_printf("% d\n", 3);
//   ft_printf("%+d\n", 3);
//   ft_printf("%010d\n", 1);
//   ft_printf("%hhd\n", 0);
//   ft_printf("%jd\n", 9223372036854775807);
//   ft_printf("%zd\n", 4294967295);
//   ft_printf("%\n");
//   ft_printf("%U\n", 4294967295);
//   ft_printf("%u\n", 4294967295);
//   ft_printf("%o\n", 40);
//   ft_printf("%%#08x\n", 42);
//   ft_printf("%x\n", 1000);
//   ft_printf("%#X\n", 1000);
//   ft_printf("%s\n", NULL);
//   ft_printf("%S\n", L"ݗݜशব");
//   ft_printf("%s%s\n", "test", "test");
//   ft_printf("%s%s%s\n", "test", "test", "test");
//   ft_printf("%C\n", 15000);
//   while (1);
//   return(0);
// }

// int main(void)
// {
// 	int	i;

// 	i = 0;
// 	ft_printf("%");
// 	printf("\t-%d\n", i++);                               // ""
// 	ft_printf("% ");                              // ""
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("% h");                             // ""
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%Z");                              // "Z"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("% hZ");                            // "Z"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%05%");                            // "0000%"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%-05%");                           // "%    "
// 	printf("\t-%d\n", i++);                               // ""
//    ft_printf("% hZ%");                           // "Z"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("% Z", "test");                     // "Z"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("% Z ", "test");                    // "Z "
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("% Z%s", "test");                   // "Ztest"
// 	printf("\t-%d\n", i++);                               // ""
// 							    ft_printf("%000   %", "test");                // "%"
// 								printf("\t-%d\n", i++);                               // ""
//         ft_printf("%%%", "test");                     // "%"
// 	printf("\t-%d\n", i++);                               // ""
//         ft_printf("%%   %", "test");                  // "%   "
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%ll#x", 9223372036854775807);      // "0x7fffffffffffffff"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%010s is a string", "this");       // "000000this is a string"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%-010s is a string", "this");      // "this       is a string"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%05c", 42);                        // "0000*"
// 	printf("\t-%d\n", i++);                               // ""
//   ft_printf("% Z", 42);                         // "Z"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%0 d", 42);                        // " 42"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%0 d", -42);                       // "-42"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("% 0d", 42);                        // " 42"
// 	printf("\t-%d\n", i++);                               // ""
//         ft_printf("% 0d", -42);                       // "-42"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%5+d", 42);                        // "  +42"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%5+d", -42);                       // "  -42"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%-5+d", 42);                       // "+42  "
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%-0+5d", 42);                      // "+42  "
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%-5+d", -42);                      // "-42  "
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%-0+5d", -42);                     // "-42  "
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%zhd", 4294967296);                // "4294967296"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%jzd", 9223372036854775807);       // "9223372036854775807"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%jhd", 9223372036854775807);       // "9223372036854775807"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%lhl", 9223372036854775807);       // ""
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%lhlz", 9223372036854775807);      // ""
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%zj", 9223372036854775807);        // ""
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%lhh", 2147483647);                // ""
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("%hhld", 128);                      // "128"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("@main_ftprintf: %####0000 33..1..#00d\n", 256); // "@main_ftprintf:                               256$\n"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("@main_ftprintf: %####0000 33..1d", 256); // "@main_ftprintf:                               256"
// 	printf("\t-%d\n", i++);                               // ""
//     ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256); // "@main_ftprintf: +256                             "
// 	printf("\t-%d\n", i++);                               // ""
//     return (0);
// }