/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fors.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:45:27 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/11/16 17:51:43 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p(va_list ap)
{
	int		count;
	int		r;
	void	*ptr;

	ptr = va_arg(ap, void *);
	count = 0;
	r = 0;
	count += write(1, "0x", 2);
	if (count == -1)
		return (-1);
	if (!ptr)
		r += write(1, "0", 1);
	else
		r += ft_putnbr_base((unsigned long)ptr, 16, NULL);
	if (r == -1)
		return (-1);
	return (count + r);
}

int	for_i_d(va_list ap, char c)
{
	int		count;
	char	*num_str;

	count = 0;
	if (c == 'd' || c == 'i')
	{
		num_str = ft_itoa(va_arg(ap, int));
		if (!num_str)
			return (-1);
		count += ft_putstr(num_str);
		free(num_str);
	}
	return (count);
}

int	for_hex(va_list ap, char c)
{
	if (c == 'x')
		return (ft_putnbr_base(va_arg(ap, unsigned int), 16, NULL));
	return (ft_putnbr_base(va_arg(ap, unsigned int), 16, "0123456789ABCDEF"));
}

int	for_s_c(va_list ap, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == '%')
		count += write(1, "%%", 1);
	return (count);
}

int	for_u(va_list ap)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	return (ft_putnbr_base(num, 10, NULL));
}
