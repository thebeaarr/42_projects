/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:46:23 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/01/25 21:13:28 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

static int	mandelbrot_iter(t_complex *c, t_complex *z)
{
	int	iters;

	iters = -1;
	z->real = 0;
	z->imagi = 0;
	while (++iters < MAX_ITER)
	{
		if (sq(z, c) > 4)
			break ;
	}
	return (iters);
}

void	draw_mandelbrot(t_data *d, t_fractal *f)
{
	int			iters;
	int			x;
	int			y;
	t_complex	c;
	t_complex	z;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			c = map(x, y, f);
			iters = mandelbrot_iter(&c, &z);
			if (iters == MAX_ITER)
				mmlxputpixel(d, x, y, 0x0);
			else
				mmlxputpixel(d, x, y, color_it(iters, f->color_shift));
		}
	}
}
