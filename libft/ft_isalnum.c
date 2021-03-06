/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:24:02 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/08 17:07:59 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int x)
{
	if ((x >= '0' && x <= '9') || (x >= 'A' && x <= 'Z') ||
		(x >= 'a' && x <= 'z'))
		return (1);
	else
		return (0);
}
