/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:50:16 by mrio              #+#    #+#             */
/*   Updated: 2025/05/19 16:14:22 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchr(char c)
{
	int	ret;

	ret = write(1, &c, 1);
	if (ret == -1)
		return (-1);
	return (ret);
}

size_t	ft_putstr(char *str)
{
	size_t	len;
	int		ret;

	len = 0;
	if (str == NULL)
	{
		ret = write(1, "(null)", 6);
		if (ret == -1)
			return (-1);
		return (ret);
	}
	while (*str)
	{
		len += ft_putchr(*str);
		str++;
	}
	return (len);
}

size_t	ft_putnbr(int c)
{
	size_t	len;
	long	num;

	num = c;
	len = 0;
	if (num < 0)
	{
		len += ft_putchr('-');
		num = -num;
	}
	if (num >= 10)
		len += ft_putnbr(num / 10);
	len += ft_putchr((num % 10) + '0');
	return (len);
}

size_t	ft_putnbr_u(unsigned int c)
{
	size_t	len;
	long	num;

	len = 0;
	num = c;
	if (num >= 10)
		len += ft_putnbr_u(num / 10);
	len += ft_putchr((num % 10) + '0');
	return (len);
}
