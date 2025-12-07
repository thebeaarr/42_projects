/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:18:06 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/01/25 21:17:03 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

int	main(int ac, char **av)
{
	t_mlx	m;

	parse_input(&m, ac, av);
	init_fractal(&(m.fractal));
	draw(&m);
	mlx_put_image_to_window(m.mlx, m.win, m.data.img, 0, 0);
	mlx_hook(m.win, 17, 0, (int (*)())close_it, &m);
	mlx_key_hook(m.win, key_press, &m);
	mlx_mouse_hook(m.win, mouse_scroll, &m);
	mlx_loop(m.mlx);
	return (0);
}
