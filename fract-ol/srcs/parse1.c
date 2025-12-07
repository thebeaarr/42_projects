/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 02:06:30 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/01/30 02:07:46 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

void	ft_atof_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	init_fractal_type(t_mlx *m, int ac, char **av)
{
	if (ac == 2)
	{
		m->fractal.c.real = -0.70176;
		m->fractal.c.imagi = -0.3842;
	}
	if (ac == 4)
	{
		m->fractal.c.real = ft_atof(av[2]);
		m->fractal.c.imagi = ft_atof(av[3]);
	}
	m->fractal_type = "julia";
	init_mlx(m, WIDTH, HEIGHT, "Julia");
}

void	parse_input(t_mlx *m, int ac, char **av)
{
	if (ac == 2 && compare(av[1], "mandelbrot") == 0)
	{
		ktb("Initializing Mandelbrot fractal...\n");
		m->fractal_type = "mandelbrot";
		init_mlx(m, WIDTH, HEIGHT, "Mandelbrot");
	}
	else if ((ac == 2 || ac == 4) && compare(av[1], "julia") == 0)
	{
		m->fractal_type = "julia";
		init_fractal_type(m, ac, av);
		ktb("Initializing Julia fractal...\n");
	}
	else if (ac == 2 && compare(av[1], FRACTAL_BURNING_SHIP) == 0)
	{
		ktb("Initializing Burning Ship fractal...\n");
		m->fractal_type = FRACTAL_BURNING_SHIP;
		init_mlx(m, WIDTH, HEIGHT, "Burning Ship");
	}
	else
	{
		ktb("Error: Invalid arguments.\n");
		display_menu();
		exit(1);
	}
}
