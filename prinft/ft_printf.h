/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:03:02 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/11/16 17:50:17 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	cg(long c);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_base(unsigned long nb, unsigned int base, char *key);
char	*create_itoa_string(long a, size_t len, int n);
int		ft_parse(va_list ap, char c);
int		ft_printf(const char *format, ...);
int		for_u(va_list ap);
int		for_s_c(va_list ap, char c);
int		for_hex(va_list ap, char c);
int		for_i_d(va_list ap, char c);
int		p(va_list ap);

#endif
