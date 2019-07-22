/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:17:04 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/20 16:17:09 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c(t_flag flags, va_list list, t_string **result)
{
	t_string		*str;
	t_rash_can		my_trashcan;

	str = (t_string*)malloc(sizeof(t_string));
	new_trash_bag(&my_trashcan);
	str->len = 1;
	str->str = ft_strnew(1);
	mom(&my_trashcan, T_CHAR, str->str);
	str->str[0] = va_arg(list, int);
	c_min_width(flags, &str, &my_trashcan);
	*result = t_string_join(**result, *str);
	garbage_day(&my_trashcan);
	return (0);
}

void	c_min_width(t_flag flags,
		t_string **string, t_rash_can *my_trashcan)
{
	t_string	temp;

	temp.len = flags.min_width - 1;
	if (temp.len > 0)
	{
		temp.str = ft_strnew(temp.len);
		mom(my_trashcan, T_CHAR, temp.str);
		if ((contains('-', flags.h_flag, NUM_H_FLAGS)) != -1)
		{
			ft_memset(temp.str, 32, temp.len);
			*string = t_string_join(**string, temp);
			mom(my_trashcan, T_CHAR, *string);
			mom(my_trashcan, T_CHAR, (*string)->str);
		}
		else
		{
			if ((contains('0', flags.h_flag, NUM_H_FLAGS)) != -1)
				ft_memset(temp.str, 48, temp.len);
			else
				ft_memset(temp.str, 32, temp.len);
			*string = t_string_join(temp, **string);
			mom(my_trashcan, T_CHAR, *string);
			mom(my_trashcan, T_CHAR, (*string)->str);
		}
	}
}
