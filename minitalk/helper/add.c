/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:23:56 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/02 19:06:14 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	mini_printf(const char *msg, int pid)
{
	while (*msg)
		write(1, msg++, 1);
	if (pid != -1)
	{
		write(1, " [", 2);
		ft_putnbr(pid);
		write(1, "]", 1);
	}
	write(1, "\n", 1);
}

void	handle_error(char *str)
{
	free(str);
	error_input(1);
}

int	parse_number(char *str, int *i)
{
	int	num;
	int	count;

	num = 0;
	count = 0;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[(*i)++] == '-')
			handle_error(str);
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (++count > 11)
			error_input(1);
		num = num * 10 + (str[(*i)++] - '0');
	}
	if (str[*i])
		handle_error(str);
	return (num);
}

int	ft_atoi1(char *str)
{
	int	i;
	int	num;

	i = 0;
	str = ft_strtrim(str, " ");
	if (!str)
		error_input(1);
	num = parse_number(str, &i);
	free(str);
	return (num);
}
