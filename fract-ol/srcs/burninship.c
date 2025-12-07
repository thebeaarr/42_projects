/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burninship.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:46:21 by medlkhdr          #+#    #+#             */
/*   Updated: 2025/01/25 20:55:31 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

static double	vabs(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static int	burning_ship_iter(t_complex *c, t_complex *z)
{
	int	iters;

	iters = -1;
	z->real = 0;
	z->imagi = 0;
	while (++iters < MAX_ITER)
	{
		z->real = vabs(z->real);
		z->imagi = vabs(z->imagi);
		if (sq(z, c) > 4)
			break ;
	}
	return (iters);
}

void	draw_burning_ship(t_data *d, t_fractal *f)
{
	t_complex	c;
	t_complex	z;
	int			iters;
	int			x;
	int			y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			c = map(x, y, f);
			iters = burning_ship_iter(&c, &z);
			if (iters == MAX_ITER)
				mmlxputpixel(d, x, y, 0x0);
			else
				mmlxputpixel(d, x, y, color_it(iters, f->color_shift));
		}
	}
}
