#include "libft.h"

void print_flags(t_flag *flags)
{
	int i = -1;
	printf("flags->h-flag: ");
	while (++i < NUM_H_FLAGS)
		printf("%c ", flags->h_flag[i]);
	printf("\nflags->min_width: %d\n", flags->min_width);
	printf("flags-precision: %d\n", flags->precision);
	printf("flags->l_flag: %c %c\n", flags->l_flag[0], flags->l_flag[1]);
	printf("flags->arg_type: %c\n", flags->arg_type);
}

