/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:02:12 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/23 18:00:24 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** mandelbrot's
** multibrot
*/

void	calc_f3(t_env *e)
{
	e->c_r = e->x / e->z + e->x1;
	e->c_i = e->y / e->z + e->y1;
	e->z_r = 0;
	e->z_i = 0;
	e->i = 0;
	while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && e->i < e->itmax)
	{
		e->tmp = pow((e->z_r * e->z_r + e->z_i * e->z_i), e->pow / 2) *
		cos(e->pow * atan2(e->z_r, e->z_i)) + e->c_r;
		e->z_r = pow((e->z_r * e->z_r + e->z_i * e->z_i), e->pow / 2) *
		sin(e->pow * atan2(e->z_r, e->z_i)) + e->c_i;
		e->z_i = e->tmp;
		e->i++;
	}
	if (e->i == e->itmax)
	{
		e->data[(int)e->x + ((int)e->y) * W_IMG] = RED;
	}
}

int		fractal3(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while (e->x < W_IMG)
	{
		while (e->y < H_IMG)
		{
			calc_f3(e);
			if (e->i != e->itmax)
				e->data[(int)e->x + ((int)e->y) * W_IMG] =
					e->i * GREEN / e->itmax;
			e->y++;
		}
		e->x++;
		e->y = 0;
	}
	return (0);
}

/*
** mandelbrot's
** fabs
*/

void	calc_f4(t_env *e)
{
	e->c_r = e->x / e->z + e->x1;
	e->c_i = e->y / e->z + e->y1;
	e->z_r = 0;
	e->z_i = 0;
	e->i = 0;
	while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && e->i < e->itmax)
	{
		e->tmp = e->z_r;
		e->z_r = fabs(e->z_r * e->z_r - e->z_i * e->z_i) + e->c_r / 1.5;
		e->z_i = 3 * e->z_i * e->tmp + e->c_i;
		e->i++;
	}
	if (e->i == e->itmax)
		e->data[(int)e->x + ((int)e->y) * W_IMG] = RED;
}

int		fractal4(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while (e->x < W_IMG)
	{
		while (e->y < H_IMG)
		{
			calc_f4(e);
			if (e->i != e->itmax)
			{
				e->data[(int)e->x + ((int)e->y) * W_IMG] =
				e->i * GREEN / e->itmax;
			}
			e->y++;
		}
		e->x++;
		e->y = 0;
	}
	return (0);
}
