/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nichan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:17:05 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/01/25 21:18:16 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

void	ktb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	compare(char *s1, char *s2)
{
	while (*s1 == 32)
		s1++;
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (-1);
		s1++;
		s2++;
	}
	if (*s1 != '\0' || *s2 != '\0')
		return (-1);
	return (0);
}

void	display_menu(void)
{
	ktb("Available Fractals:\n");
	ktb("  - Mandelbrot: 'mandelbrot'\n");
	ktb("  - Julia: 'julia [real] [imaginary]'\n");
	ktb("  - Burning ship : 'burning_ship'\n");
	ktb("\nUsage: ./fractol [fractal_name] [params]\n");
	ktb("Available Commands (once a fractal is chosen):\n");
	ktb("  - Zoom In: [+]\n");
	ktb("  - Zoom Out: [-]\n");
	ktb("  - Change Colors: [Q], [R]\n");
	ktb("  - Shift: Arrow keys (↑, ↓, ←, →)\n");
	ktb("  - Exit: [ESC]\n");
}
