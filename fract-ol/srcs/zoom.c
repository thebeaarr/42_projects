/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:18:29 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/01/25 21:27:56 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

void	zoom(t_fractal *f, int zoom_in, int mouse_x, int mouse_y)
{
	double	mouse_re;
	double	mouse_im;
	double	new_width;
	double	new_height;
	double	zoom_factor;

	mouse_re = f->min_real + ((double)mouse_x / WIDTH) * (f->max_real
			- f->min_real);
	mouse_im = f->min_imag + ((double)mouse_y / HEIGHT) * (f->max_imag
			- f->min_imag);
	if (zoom_in)
		zoom_factor = 1 / ZOOM_FACTOR;
	else
		zoom_factor = ZOOM_FACTOR;
	new_width = (f->max_real - f->min_real) * zoom_factor;
	new_height = (f->max_imag - f->min_imag) * zoom_factor;
	f->min_real = mouse_re - (mouse_re - f->min_real) * zoom_factor;
	f->max_real = f->min_real + new_width;
	f->min_imag = mouse_im - (mouse_im - f->min_imag) * zoom_factor;
	f->max_imag = f->min_imag + new_height;
}

void	adjust_real_axis(int keycode, t_mlx *m)
{
	float	shift;

	shift = (m->fractal.max_real - m->fractal.min_real) * 0.1;
	if (keycode == SHIFT_LEFT_KEY)
	{
		m->fractal.min_real -= shift;
		m->fractal.max_real -= shift;
	}
	else if (keycode == SHIFT_RIGHT_KEY)
	{
		m->fractal.min_real += shift;
		m->fractal.max_real += shift;
	}
}

void	adjust_imag_axis(int keycode, t_mlx *m)
{
	float	shift;

	shift = (m->fractal.max_imag - m->fractal.min_imag) * 0.1;
	if (keycode == SHIFT_UP_KEY)
	{
		m->fractal.min_imag -= shift;
		m->fractal.max_imag -= shift;
	}
	else if (keycode == SHIFT_DOWN_KEY)
	{
		m->fractal.min_imag += shift;
		m->fractal.max_imag += shift;
	}
}

void	handle_arrow_keys(int keycode, t_mlx *m)
{
	if (keycode == SHIFT_LEFT_KEY || keycode == SHIFT_RIGHT_KEY)
		adjust_real_axis(keycode, m);
	else if (keycode == SHIFT_UP_KEY || keycode == SHIFT_DOWN_KEY)
		adjust_imag_axis(keycode, m);
}
