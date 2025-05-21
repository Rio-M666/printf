/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:50:16 by mrio              #+#    #+#             */
/*   Updated: 2025/05/21 13:36:24 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char c)
{
	int	result;

	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	return (result);
}

int	ft_putstr(char *str)
{
	int	len;
	int	ret;

	len = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (*str)
	{
		ret = ft_putchr(*str);
		if (ret == -1)
			return (-1);
		len += ret;
		str++;
	}
	return (len);
}

int	ft_putnbr(int c)
{
	int		len;
	long	num;
	int		result;

	num = c;
	len = 0;
	if (num < 0)
	{
		result = ft_putchr('-');
		if (result == -1)
			return (-1);
		len += result;
		num = -num;
	}
	if (num >= 10)
		len += ft_putnbr(num / 10);
	result = ft_putchr((num % 10) + '0');
	if (result == -1)
		return (-1);
	len += result;
	return (len);
}

int	ft_putnbr_u(unsigned int c)
{
	int		len;
	long	num;
	int		result;

	len = 0;
	num = c;
	if (num >= 10)
		len += ft_putnbr_u(num / 10);
	result = ft_putchr((num % 10) + '0');
	if (result == -1)
		return (-1);
	len += result;
	return (len);
}
