#include "ft_printf.h"

int x(t_flag flags, va_list list, t_string **result)
{
	t_package package;

	ft_bzero(&package, sizeof(t_package));
	package.flag = flags;
	package.string = (t_string*)malloc(sizeof(t_string));
	package.string->str = ft_unsignedlltoa_base(va_arg(list, unsigned long long), 16);
	new_trash_bag(&(package.trash));
	mom(&(package.trash), T_CHAR, package.string);
	mom(&(package.trash), T_CHAR, package.string->str);
	package.string->len = ft_strlen(package.string->str);
	x_formatter(&package);
	*result = t_string_join(**result, *(package.string));
	garbage_day(&(package.trash));
	return(0);
}

void x_formatter(t_package *package)
{
	hex_prefix(package);
	d_adjust_precision(package);
	d_min_width(package);
	if(package->mws)
	{
		package->mws->len -= package->sign.len;
		if (package->mws->len < 0)
			package->mws->len = 0;
	}
	dhelper(package);
}

void hex_prefix(t_package *package)
{
	t_string temp;

	ft_bzero(&temp, sizeof(t_string));
	if ((contains('#', package->flag.h_flag, NUM_H_FLAGS) != -1)
			&& package->string->str[0] != '0')
	{
		temp.str = "0x";
		temp.len = 2;
	}
	package->sign = temp;
}
