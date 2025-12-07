/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:18:13 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/01/25 20:59:17 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

void	mmlxputpixel(t_data *d, int x, int y, int color)
{
	int	offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = y * d->line + x * (d->bpp / 8);
		*(unsigned int *)(d->addr + offset) = color;
	}
}

int	color_it(int iters, int color_shift)
{
	int	r;
	int	g;
	int	b;

	color_shift = color_shift % 256;
	r = ((iters * 9 + color_shift) % 256);
	g = ((iters * 7 + color_shift * 2) % 256);
	b = ((iters * 5 + color_shift * 3) % 256);
	return ((r << 16) | (g << 8) | 0x000000 | b);
}

double	sq(t_complex *z, t_complex *c)
{
	double	z_real_squared;
	double	z_imag_squared;

	z_real_squared = z->real * z->real - z->imagi * z->imagi + c->real;
	z_imag_squared = 2 * z->real * z->imagi + c->imagi;
	z->real = z_real_squared;
	z->imagi = z_imag_squared;
	return (z->real * z->real + z->imagi * z->imagi);
}

t_complex	map(int x, int y, t_fractal *f)
{
	t_complex	c;

	c.real = f->min_real + ((float)x / WIDTH) * (f->max_real - f->min_real);
	c.imagi = f->min_imag + ((float)y / HEIGHT) * (f->max_imag - f->min_imag);
	return (c);
}
