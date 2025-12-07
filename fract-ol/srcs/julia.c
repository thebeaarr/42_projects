/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:45:39 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/01/25 21:15:26 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

static int	julia_iter(t_complex *z, t_fractal *f)
{
	int	iters;

	iters = -1;
	while (++iters < MAX_ITER)
	{
		if (sq(z, &(f->c)) > 4)
			break ;
	}
	return (iters);
}

void	draw_julia(t_data *d, t_fractal *f)
{
	int			iters;
	int			x;
	int			y;
	t_complex	z;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			z.real = f->min_real + ((float)x / WIDTH) * (f->max_real
					- f->min_real);
			z.imagi = f->min_imag + ((float)y / HEIGHT) * (f->max_imag
					- f->min_imag);
			iters = julia_iter(&z, f);
			if (iters == MAX_ITER)
				mmlxputpixel(d, x, y, 0x0);
			else
				mmlxputpixel(d, x, y, color_it(iters, f->color_shift));
		}
	}
}
