/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:35:19 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/02 18:48:59 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	mini_printf(const char *msg, int pid);
void	ft_putnbr(int n);
int		parse_number(char *str, int *i);
void	error_input(int e);
void	sent_signal(char c, int pid);
int		parse_input(int ac, char **av);
size_t	ft_strlen(const char *s);
int		in_set(int c, const char *set);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strtrim(const char *s1, const char *set);
int		ft_atoi1(char *str);
#endif