/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trashcan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:24:56 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/18 21:10:24 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trashcan.h"

void new_trash_bag(t_rash_can *my_trashcan)
{
	my_trashcan->top = -1;
}

void mom(t_rash_can *my_trashcan, t_my_type tp, ...)
{
	va_list list;
	if (!trash_overflow(my_trashcan))
	{
		va_start(list, tp);
		(my_trashcan->top)++;
		my_trashcan->can[my_trashcan->top].type = tp;
		
		if (my_trashcan->can[my_trashcan->top].type == T_CHAR)
			my_trashcan->can[my_trashcan->top].u_piece.cp = va_arg(list, char*);
		else if (my_trashcan->can[my_trashcan->top].type == T_INT)
			my_trashcan->can[my_trashcan->top].u_piece.ip = va_arg(list, int*);
		else if (my_trashcan->can[my_trashcan->top].type == T_FLOAT)
			my_trashcan->can[my_trashcan->top].u_piece.fp = va_arg(list, float*);
		va_end(list);
	}
}

int trash_overflow(t_rash_can *my_trashcan)
{
	if(my_trashcan->top == DEFAULT_TRASH_SIZE - 1)
		return(1);
	else
		return(0);
}

int trashcan_empty(t_rash_can *my_trashcan)
{
	if (my_trashcan->top == -1)
		return(1);
	else
		return(0);
}

void garbage_day(t_rash_can *my_trashcan)
{
	while(!trashcan_empty(my_trashcan))
	{
		if (my_trashcan->can[my_trashcan->top].type == T_CHAR)
			free(my_trashcan->can[my_trashcan->top].u_piece.cp);
		else if (my_trashcan->can[my_trashcan->top].type == T_INT)
			free(my_trashcan->can[my_trashcan->top].u_piece.ip);
		else if (my_trashcan->can[my_trashcan->top].type == T_FLOAT)
			free(my_trashcan->can[my_trashcan->top].u_piece.fp);		
		(my_trashcan->top)--;
	}
}
