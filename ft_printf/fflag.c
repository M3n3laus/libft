#include "ft_printf.h"

int	f(t_flag flags, va_list list, t_string **result)
{
	if (flags.precision > 0 || list || result)
		return (0);
	else
		return (0);
}
