#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		list;
	t_string	*result;
	t_rash_can	my_trashcan;

	new_trash_bag(&my_trashcan);
	result = (t_string*)malloc(sizeof(t_string));
	mom(&my_trashcan, T_CHAR, result);
	result->str = "\0";
	result->len = 0;
	INIT_TABLE(dispatch);
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
			format = parse_key(format, &result, dispatch, list);
		else
			format = parse_no_key(format, &result);
	}
	print_t_string(result);
	return (result->len);
}

const char		*parse_no_key(const char *format, t_string **result)
{
	t_string	newstr;
	char		*temp;

	temp = (*result)->str;
	newstr.len = ft_strclen(format, '%');
	if (newstr.len)
	{
		newstr.str = ft_strsub(format, 0, newstr.len);
		*result = t_string_join(**result, newstr);
		if (*temp)
			free(temp);
		free(newstr.str);
	}
	return (format + newstr.len);
}

const char		*parse_key(const char *format, t_string **result,
		t_dispatch_table dispatch, va_list list)
{
	t_flag			flags;
	int				code;

	code = -1;
	init_t_flag(&flags);
	format = set_h_flags(format, &flags);
	format = set_min_width(format, &flags);
	format = set_precision(format, &flags);
	format = set_l_flags(format, &flags);
	format = set_arg_type(format, &flags, &code, dispatch);
	if (code != -1)
		dispatch.table[code].func(flags, list, result);
	return (format);
}

void			init_t_flag(t_flag *flags)
{
	ft_bzero(flags->h_flag, NUM_H_FLAGS);
	flags->min_width = 0;
	flags->precision = 9999;
	ft_bzero(flags->l_flag, 3);
	flags->arg_type = 0;
}
