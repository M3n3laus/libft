/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:32:15 by smaddox           #+#    #+#             */
/*   Updated: 2019/04/30 15:32:30 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_chrswap(char *c, char *c2)
{
	char temp;

	temp = *c;
	*c = *c2;
	*c2 = temp;
}
