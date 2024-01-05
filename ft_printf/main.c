#include "ft_printf.h"

/* void	ft_print_bits(unsigned int num, int size) */
/* { */
/* 	for (int bit = 0; bit < (size * 8); bit++) */
/* 	{ */
/* 		printf("%i ", num & 0x01); */
/* 		num = num >> 1; */
/* 	} */
/* } */

size_t	ft_strlen(const char *s)
{
	const char	*start = s;

	while (*s)
		s++;
	return (s - start);
}

/* int	ft_strchr(const char *s, const char c) */
/* { */
/* 	size_t	i; */
/**/
/* 	i = 0; */
/* 	while (s[i]) */
/* 	{ */
/* 		if (s[i] == c) */
/* 			return (i); */
/* 		i++; */
/* 	} */
/* 	return (-1); */
/* } */
/**/
/* int	ft_isdigit(int c) */
/* { */
/* 	return ((c > 47) && (c < 58)); */
/* } */
/**/
/* int	ft_atoi(const char *nptr) */
/* { */
/* 	long	n; */
/* 	short	sign; */
/**/
/* 	sign = 1; */
/* 	n = 0; */
/* 	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32)) */
/* 		nptr++; */
/* 	if (*nptr == '-') */
/* 		sign = -1; */
/* 	if (*nptr == '+' || *nptr == '-') */
/* 		nptr++; */
/* 	while (*nptr >= '0' && *nptr <= '9') */
/* 		n = ((n * 10) + (*nptr++ - '0')); */
/* 	return (sign * n); */
/* } */



int	main(void)
{
	/* -- %d -- */ 
	ft_printf("%d\n", 0);
	ft_printf("%d\n", 42);
	ft_printf("%d\n", -1);
	ft_printf("%d\n", 2147483647);
	ft_printf("%d\n", -2147483648);
	ft_printf("%d%d%d%d%d\n", 1,2,3,4,5);
	printf("-----\n");
	printf("%d\n", 0);
	printf("%d\n", 42);
	printf("%d\n", -1);
	printf("%d\n", 2147483647);
	int n = -2147483648;
	printf("%d\n", n);
	printf("%d%d%d%d%d\n", 1,2,3,4,5);
	/* ft_printf("%d\n", a); */
	/* ft_printf("%d%d%d%d%d\n", 1,2,3,4,5); */


	/* -- %s -- */
	/* ft_printf("Hello"); */
	/* ft_printf("\n"); */
	/* ft_printf("a"); */
	/* ft_printf("%s", "\n"); */
	/* ft_printf(NULL); */
	/* ft_printf("\n"); */
	/* ft_printf("AB%sEF\n", "CD"); */
	/* ft_printf("%s\n", NULL); */
	/* ft_printf("%s\n", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeefffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggghhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkllllllllllllllllllllllllllllllllmmmmmmmmmmmmmmmmmmmmmmmmmnnnnnnnnnnnnnnnnnnooooooooooooooooooooooooooooooooooopppppppppppppppqqqqrssssssssssssssssssssssssttttttttttttttttuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxxxxxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyz012345679"); */
	/* printf("-----\n"); */
	/* printf("Hello"); */
	/* printf("\n"); */
	/* printf("a"); */
	/* printf("%s", "\n"); */
	/* printf(NULL); */
	/* printf("\n"); */
	/* printf("AB%sEF\n", "CD"); */
	/* printf("%s\n", NULL); */
	/* printf("%s\n", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeefffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggghhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkllllllllllllllllllllllllllllllllmmmmmmmmmmmmmmmmmmmmmmmmmnnnnnnnnnnnnnnnnnnooooooooooooooooooooooooooooooooooopppppppppppppppqqqqrssssssssssssssssssssssssttttttttttttttttuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxxxxxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyz012345679"); */
	return (0);
}
