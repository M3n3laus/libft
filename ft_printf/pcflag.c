#include "ft_printf.h"

int		percent(t_flag flags, va_list list, t_string **result)
{
	t_string	*str;
	t_rash_can	my_trashcan;

	if (list)
	{
		;
	}
	str = (t_string*)malloc(sizeof(t_string));
	new_trash_bag(&my_trashcan);
	str->len = 1;
	str->str = ft_strnew(1);
	mom(&my_trashcan, T_CHAR, str->str);
	str->str[0] = '%';
	c_min_width(flags, &str, &my_trashcan);
	*result = t_string_join(**result, *str);
	garbage_day(&my_trashcan);
	return (0);
}
