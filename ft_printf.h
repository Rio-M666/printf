/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:51:46 by mrio              #+#    #+#             */
/*   Updated: 2025/05/21 13:31:09 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchr(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int c);
int	ft_putnbr_u(unsigned int c);
int	ft_pointer(void *ptr);
int	ft_puthex(unsigned long i, const char str);
int	ft_check(va_list ap, char str);

#endif