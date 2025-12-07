/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:02:59 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/11/16 17:42:41 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(va_list ap, char c)
{
	int	result;

	result = ft_parse(ap, c);
	if (result == -1)
		return (-1);
	return (result);
}

static int	write_char(char c)
{
	int	result;

	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		result;

	count = 0;
	va_start(ap, format);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[++i])
			result = handle_format(ap, format[i]);
		else
			result = write_char(format[i]);
		if (result == -1)
			return (-1);
		count += result;
	}
	va_end(ap);
	return (count);
}
