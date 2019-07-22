/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:18:08 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/20 16:18:10 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p(t_flag flags, va_list list, t_string **result)
{
	t_string			*string;
	t_rash_can			my_trashcan;

	string = (t_string*)malloc(sizeof(t_string));
	new_trash_bag(&my_trashcan);
	mom(&my_trashcan, T_CHAR, string);
	string->str = ft_unsignedlltoa_base(va_arg(list, unsigned long long), 16);
	string->len = ft_strlen(string->str);
	mom(&my_trashcan, T_CHAR, string->str);
	p_min_width(&flags, &string, &my_trashcan);
	*result = t_string_join(**result, *string);
	garbage_day(&my_trashcan);
	return (0);
}

void	p_min_width(t_flag *flags, t_string **string, t_rash_can *my_trashcan)
{
	t_string	newstr;
	t_string	append;

	append.str = "0x";
	append.len = 2;
	newstr.len = flags->min_width - ((*string)->len + 2);
	if (newstr.len > 0)
	{
		newstr.str = ft_strnew(newstr.len);
		mom(my_trashcan, T_CHAR, newstr.str);
		ft_memset(newstr.str, 32, newstr.len);
		helper(flags, string, my_trashcan, &newstr);
	}
	else
	{
		*string = t_string_join(append, **string);
		mom(my_trashcan, T_CHAR, *string);
	}
}

void	helper(t_flag *flags, t_string **string,
		t_rash_can *my_trashcan, t_string *newstr)
{
	t_string	append;

	append.str = "0x";
	append.len = 2;
	if ((contains('-', flags->h_flag, NUM_H_FLAGS)) != -1)
	{
		*string = t_string_join(append, **string);
		mom(my_trashcan, T_CHAR, *string);
		*string = t_string_join(**string, *newstr);
		mom(my_trashcan, T_CHAR, *string);
	}
	else
	{
		if ((contains('0', flags->h_flag, NUM_H_FLAGS)) != -1)
		{
			ft_memset(newstr->str, 48, newstr->len);
			newstr->str = ft_strjoin(append.str, newstr->str);
		}
		else
			newstr->str = ft_strjoin(newstr->str, append.str);
		mom(my_trashcan, T_CHAR, newstr->str);
		newstr->len = ft_strlen(newstr->str);
		*string = t_string_join(*newstr, **string);
		mom(my_trashcan, T_CHAR, *string);
	}
}
