/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:18:45 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/01/30 02:08:45 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_H
# define F_H

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 640
# define MAX_ITER 100
# define ZOOM_FACTOR 1.1
# define FRACTAL_BURNING_SHIP "burning_ship"
# define FRACTAL_MANDELBROT "mandelbrot"
# define FRACTAL_JULIA "julia"
# define ZOOM_IN_KEY 61
# define ZOOM_OUT_KEY 45
# define CHANGE_COLOR_Q_KEY 'Q'
# define CHANGE_COLOR_E_KEY 'E'
# define SHIFT_UP_KEY 65362
# define SHIFT_DOWN_KEY 65364
# define SHIFT_LEFT_KEY 65361
# define SHIFT_RIGHT_KEY 65363
# define EXIT_KEY 65307

typedef struct s_complex
{
	double		real;
	double		imagi;
}				t_complex;

typedef struct s_fractal
{
	float		min_real;
	float		max_real;
	float		min_imag;
	float		max_imag;
	int			color_shift;
	t_complex	c;
}				t_fractal;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line;
	int			endian;
}				t_data;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_data		data;
	t_fractal	fractal;
	char		*fractal_type;
}				t_mlx;
void			ktb(char *str);
void			mmlxputpixel(t_data *d, int x, int y, int color);
void			handle_arrow_keys(int keycode, t_mlx *m);
int				color_it(int iters, int color_shift);
double			sq(t_complex *z, t_complex *c);
void			ft_atof_error(void);
t_complex		map(int x, int y, t_fractal *f);
void			draw_mandelbrot(t_data *d, t_fractal *f);
void			draw_julia(t_data *d, t_fractal *f);
void			zoom(t_fractal *f, int zoom_in, int mouse_x, int mouse_y);
int				key_press(int keycode, t_mlx *m);
int				mouse_scroll(int button, int x, int y, t_mlx *m);
void			draw(t_mlx *m);
int				close_it(t_mlx *m);
void			init_fractal(t_fractal *f);
void			init_mlx(t_mlx *m, int width, int height, char *title);
void			display_menu(void);
void			parse_input(t_mlx *m, int ac, char **av);
int				compare(char *s1, char *s2);
double			ft_atof(char *str);
double			ft_atof_part2(char *str, int i);
void			draw_burning_ship(t_data *d, t_fractal *f);
#endif
