/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:18:20 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/01/25 21:31:39 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

int	key_press(int keycode, t_mlx *m)
{
	if (keycode == EXIT_KEY)
	{
		ktb("Window is closed.\n");
		mlx_destroy_image(m->mlx, m->data.img);
		mlx_destroy_window(m->mlx, m->win);
		mlx_destroy_display(m->mlx);
		free(m->mlx);
		exit(0);
	}
	handle_arrow_keys(keycode, m);
	if (keycode == ZOOM_IN_KEY)
		zoom(&(m->fractal), 1, WIDTH / 2, HEIGHT / 2);
	else if (keycode == ZOOM_OUT_KEY)
		zoom(&(m->fractal), 0, WIDTH / 2, HEIGHT / 2);
	else if (keycode == 'q' || keycode == CHANGE_COLOR_Q_KEY)
		m->fractal.color_shift += 4;
	else if (keycode == 'e' || keycode == CHANGE_COLOR_E_KEY)
		m->fractal.color_shift -= 4;
	draw(m);
	mlx_put_image_to_window(m->mlx, m->win, m->data.img, 0, 0);
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_mlx *m)
{
	if (button == 4)
		zoom(&(m->fractal), 1, x, y);
	else if (button == 5)
		zoom(&(m->fractal), 0, x, y);
	draw(m);
	mlx_put_image_to_window(m->mlx, m->win, m->data.img, 0, 0);
	return (0);
}

int	close_it(t_mlx *m)
{
	ktb("Window is closed.\n");
	mlx_destroy_image(m->mlx, m->data.img);
	mlx_destroy_window(m->mlx, m->win);
	mlx_destroy_display(m->mlx);
	free(m->mlx);
	exit(0);
	return (0);
}
