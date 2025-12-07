/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:02:49 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/11/16 17:36:02 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_itoa_string(long a, size_t len, int n)
{
	char	*s;

	s = malloc(len + 1);
	if (!s)
		return (NULL);
	if (n < 0)
		s[0] = '-';
	s[len] = '\0';
	while (len > (n < 0))
	{
		s[--len] = (a % 10) + '0';
		a /= 10;
	}
	return (s);
}

size_t	cg(long c)
{
	size_t	i;

	if (c == 0)
		i = 1;
	else
		i = 0;
	while (c > 0)
	{
		i++;
		c /= 10;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
	{
		ptr++;
	}
	return ((size_t)(ptr - s));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
	{
		return (j);
	}
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;

	i = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s1, (i + 1));
	return (p);
}
