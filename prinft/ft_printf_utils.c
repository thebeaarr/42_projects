/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:02:36 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/11/16 17:50:48 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nb, unsigned int base, char *key)
{
	int	count;
	int	result;

	result = 0;
	count = 0;
	if (!key)
		key = "0123456789abcdef";
	if (nb >= base)
		count += ft_putnbr_base(nb / base, base, key);
	result = write(1, &key[nb % base], 1);
	if (result == -1)
		return (-1);
	return (count + result);
}

int	ft_parse(va_list ap, char c)
{
	int	count;

	count = 0;
	if (c == 'i' || c == 'd')
		count += for_i_d(ap, c);
	else if (c == 'p')
		count = p(ap);
	else if (c == 'X' || c == 'x')
		count += for_hex(ap, c);
	else if (c == 'c' || c == 's' || c == '%')
		count += for_s_c(ap, c);
	else if (c == 'u')
		count += for_u(ap);
	if (count < 0)
		return (-1);
	return (count);
}
