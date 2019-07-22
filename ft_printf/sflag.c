/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:18:13 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/20 16:18:15 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s(t_flag flags, va_list list, t_string **result)
{
	t_string	*temp;
	t_rash_can	my_trashcan;

	temp = (t_string*)malloc(sizeof(t_string));
	new_trash_bag(&my_trashcan);
	temp->str = va_arg(list, char*);
	if (!temp->str)
		temp->str = "(null)";
	temp->len = ft_strlen(temp->str);
	str_precision(&flags, &temp, &my_trashcan);
	str_min_width(&flags, &temp, &my_trashcan);
	*result = t_string_join(**result, *temp);
	garbage_day(&my_trashcan);
	return (0);
}

void	str_precision(t_flag *flags, t_string
		**string, t_rash_can *my_trashcan)
{
	char *temp;

	if ((*string)->len > flags->precision)
	{
		(*string)->len = flags->precision;
		temp = ft_strnew(flags->precision);
		mom(my_trashcan, T_CHAR, temp);
		temp = ft_strncpy(temp, (*string)->str, flags->precision);
		(*string)->str = temp;
	}
}

void	str_min_width(t_flag *flags,
		t_string **string, t_rash_can *my_trashcan)
{
	t_string	newstr;

	newstr.len = flags->min_width - (*string)->len;
	if (newstr.len > 0)
	{
		newstr.str = ft_strnew(newstr.len);
		mom(my_trashcan, T_CHAR, newstr.str);
		if ((contains('-', flags->h_flag, NUM_H_FLAGS)) != -1)
		{
			ft_memset(newstr.str, 32, newstr.len);
			*string = t_string_join(**string, newstr);
			mom(my_trashcan, T_CHAR, *string);
			mom(my_trashcan, T_CHAR, (*string)->str);
		}
		else
		{
			if ((contains('0', flags->h_flag, NUM_H_FLAGS)) != -1)
				ft_memset(newstr.str, 48, newstr.len);
			else
				ft_memset(newstr.str, 32, newstr.len);
			*string = t_string_join(newstr, **string);
			mom(my_trashcan, T_CHAR, *string);
			mom(my_trashcan, T_CHAR, (*string)->str);
		}
	}
}
