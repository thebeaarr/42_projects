/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:03:07 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/11/16 17:35:34 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;
	int	result;

	result = 0;
	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		result = 0;
		result = write(1, str++, 1);
		if (result == -1)
			return (-1);
		count += result;
	}
	return (count);
}
