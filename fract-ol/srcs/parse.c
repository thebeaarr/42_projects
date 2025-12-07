/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:46:17 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/01/30 02:07:02 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

double	parse_integer_part(char *str, int *i)
{
	double	result;

	result = 0.0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

double	parse_fractional_part(char *str, int *i, double result)
{
	double	fraction;

	fraction = 1.0;
	if (str[*i] == '.')
	{
		(*i)++;
		if (!(str[*i] >= '0' && str[*i] <= '9'))
			ft_atof_error();
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			result = result * 10 + (str[*i] - '0');
			fraction *= 10.0;
			(*i)++;
		}
	}
	return (result / fraction);
}

void	validate_end_of_string(char *str, int *i)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] != '\0')
		ft_atof_error();
}

double	ft_atof_part2(char *str, int i)
{
	double	result;

	result = parse_integer_part(str, &i);
	result = parse_fractional_part(str, &i, result);
	validate_end_of_string(str, &i);
	return (result);
}

double	ft_atof(char *str)
{
	double	result;
	int		sign;
	int		i;

	result = 0.0;
	sign = 1;
	i = 0;
	if (!str || str[i] == '\0')
		ft_atof_error();
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		ft_atof_error();
	result = ft_atof_part2(str, i) * sign;
	if (result > 2.0 || result < -2.0)
		ft_atof_error();
	return (result);
}
