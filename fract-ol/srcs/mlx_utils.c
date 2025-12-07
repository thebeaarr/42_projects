/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:18:26 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/01/25 21:25:38 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

void	init_mlx(t_mlx *m, int width, int height, char *title)
{
	m->mlx = mlx_init();
	if (!m->mlx)
		exit(EXIT_FAILURE);
	m->win = mlx_new_window(m->mlx, width, height, title);
	if (!m->win)
		exit(EXIT_FAILURE);
	m->data.img = mlx_new_image(m->mlx, width, height);
	if (!m->data.img)
		exit(EXIT_FAILURE);
	m->data.addr = mlx_get_data_addr(m->data.img, &m->data.bpp, &m->data.line,
			&m->data.endian);
	if (!m->data.addr)
		exit(EXIT_FAILURE);
}

void	init_fractal(t_fractal *f)
{
	f->min_real = -2.0;
	f->max_real = 1.0;
	f->min_imag = -1.5;
	f->max_imag = 1.5;
	f->color_shift = 15;
}

void	draw(t_mlx *m)
{
	if (compare(m->fractal_type, FRACTAL_MANDELBROT) == 0)
		draw_mandelbrot(&(m->data), &(m->fractal));
	else if (compare(m->fractal_type, FRACTAL_JULIA) == 0)
		draw_julia(&(m->data), &(m->fractal));
	else if (compare(m->fractal_type, FRACTAL_BURNING_SHIP) == 0)
		draw_burning_ship(&(m->data), &(m->fractal));
}
