/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trashcan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:24:56 by smaddox           #+#    #+#             */
/*   Updated: 2019/08/08 12:25:24 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "trashcan.h"

t_rash_can g_can = {.top = -1};

void	mom(void *pointer)
{
	if (!trash_overflow())
	{
		g_can.top++;
		g_can.can[g_can.top] = pointer;
	}
	/*
	else if (trash_overflow())
    {
        garbage_day();
        mom(pointer);
    } */
}

int		trash_overflow(void)
{
	if (g_can.top == DEFAULT_SIZE - 1)
        return(1);
	return (0);
}

int		trashcan_empty(void)
{
	if (g_can.top == -1)
		return (1);
	return (0);
}

void	garbage_day(void)
{
    //debug info
    //printf("\nemptying %d elements\n", g_can.top);
	while (!trashcan_empty())
	{
		free(g_can.can[g_can.top]);
		g_can.top--;
	}
}
