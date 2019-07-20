#include "ft_printf.h"

int		contains(char c, char *str, int len)
{
	int i;

	i = -1;
	while (++i < len)
	{
		if (c == str[i])
			return (i);
	}
	return (-1);
}

int		str_num_len(const char *format)
{
	int len;

	len = 0;
	while (format[len] && ft_isdigit(format[len]))
		len++;
	return (len);
}
