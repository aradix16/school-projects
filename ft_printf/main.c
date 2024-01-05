#include "ft_printf.h"

#include <limits.h>
#include <stddef.h>
#include <stdint.h>


size_t	ft_strlen(const char *s)
{
	const char	*start = s;

	while (*s)
		s++;
	return (s - start);
}

int	ft_nbrlen(intmax_t nb, short base)
{
	int	len;

	len = 0;
	if (nb < base)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(intmax_t nb, short base, int max)
{
	static char	s[100];
	int			len;

	len = ft_nbrlen(nb, base);
	s[len] = '\0';
	while (len--)
	{
		if (nb % base < 10)
			s[len] = nb % base + '0';
		else
			s[len] = nb % base + max - 10; // usefile with base > 10 like hex
		nb /= base;
	}
	return (s);
}




int	main(void)
{
	/* -- %c -- */ 
	ft_printf("%c", 'a');
	ft_printf("\n");
	ft_printf(">%c", 'b');
	ft_printf("\n");
	ft_printf("%c<", 'c');
	ft_printf("\n");
	ft_printf(">%c<", 'd');
	ft_printf("\n");
	ft_printf(",%c,%c%c%c", 'a', 'b', 'c', 'd');
	ft_printf("\n");
	ft_printf("-%c-", 0);
	ft_printf("\n");
	printf("-----\n");
	printf("%c", 'a');
	printf("\n");
	printf(">%c", 'b');
	printf("\n");
	printf("%c<", 'c');
	printf("\n");
	printf(">%c<", 'd');
	printf("\n");
	printf(",%c,%c%c%c", 'a', 'b', 'c', 'd');
	printf("\n");
	printf("-%c-", 0);
	printf("\n");



	printf("\n\n\n\n");



	/* -- %s -- */
	char *s;
	s = NULL;
	ft_printf("Hello");
	ft_printf("\n");
	ft_printf("a");
	ft_printf("%s", "\n");
	ft_printf(NULL);
	ft_printf("\n");
	ft_printf("AB%sEF\n", "CD");
	ft_printf("%s\n", s);
	ft_printf("%s\n", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeefffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggghhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkllllllllllllllllllllllllllllllllmmmmmmmmmmmmmmmmmmmmmmmmmnnnnnnnnnnnnnnnnnnooooooooooooooooooooooooooooooooooopppppppppppppppqqqqrssssssssssssssssssssssssttttttttttttttttuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxxxxxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyz012345679");
	printf("-----\n");
	printf("Hello");
	printf("\n");
	printf("a");
	printf("%s", "\n");
	printf(NULL);
	printf("\n");
	printf("AB%sEF\n", "CD");
	printf("%s\n", s);
	printf("%s\n", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeefffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggghhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkllllllllllllllllllllllllllllllllmmmmmmmmmmmmmmmmmmmmmmmmmnnnnnnnnnnnnnnnnnnooooooooooooooooooooooooooooooooooopppppppppppppppqqqqrssssssssssssssssssssssssttttttttttttttttuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxxxxxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyz012345679");


	printf("\n\n\n\n");


	/* -- %p -- */ 
	int a = 10;
	int *n = &a;
	ft_printf("%p", n);
	printf("\n-----\n");
	printf("%p", n);
	printf("\n\n\n");

	int x = 10;
	n = &x;
	ft_printf("%p", n);
	printf("\n-----\n");
	printf("%p", n);




	printf("\n\n\n\n");

	/* -- %d -- */ 
	int z = -2147483648;
	ft_printf("%d\n", 0);
	ft_printf("%d\n", 42);
	ft_printf("%d\n", -1);
	ft_printf("%d\n", -420);
	ft_printf("%d\n", 2147483647);
	ft_printf("%d\n", z);
	ft_printf("%d%d%d%d%d\n", 1,2,3,4,5);
	printf("-----\n");
	printf("%d\n", 0);
	printf("%d\n", 42);
	printf("%d\n", -1);
	printf("%d\n", -420);
	printf("%d\n", 2147483647);
	printf("%d\n", z);
	printf("%d%d%d%d%d\n", 1,2,3,4,5);



	printf("\n\n\n\n");

	/* -- %u -- */ 
	unsigned int u = 4294967295;
	ft_printf("%u\n", -1);
	ft_printf("%u\n", -10000);
	ft_printf("%u\n", u);
	ft_printf("%u\n", 1294967295);
	ft_printf("%u\n", -42);
	printf("-----\n");
	printf("%u\n", -1);
	printf("%u\n", -10000);
	printf("%u\n", u);
	printf("%u\n", 1294967295);
	printf("%u\n", -42);





	/* ft_printf("SIZE_MAX = %d\n", 9223372036854775807); */
	/* ft_printf("SIZE_MAX = %b\n", 9223372036854775807); */
	/* ft_printf("%d\n", a); */


	return (0);
}
