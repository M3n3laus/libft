#include "ft_printf.h"

int u(t_flag flags, va_list list, t_string **result)
{
	t_package package;
	ft_bzero(&package, sizeof(package));
	package.flag = flags;
	new_trash_bag(&(package.trash));
	package.string = (t_string*)malloc(sizeof(t_string));
	package.string->str = ft_unsignedlltoa_base(va_arg(list, unsigned long long), 10);
	mom(&(package.trash), T_CHAR, package.string);
	mom(&(package.trash), T_CHAR, package.string->str);
	package.string->len = ft_strlen(package.string->str);
	d_formatter(&package);
	*result = t_string_join(**result, *(package.string));
	garbage_day(&(package.trash));
	return(0);
}
