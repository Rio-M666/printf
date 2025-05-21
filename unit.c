/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:48:21 by mrio              #+#    #+#             */
/*   Updated: 2025/05/21 13:33:24 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long i, const char str)
{
	char	*hex;
	int		len;
	int		result;

	len = 0;
	if (str == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (i >= 16)
		len += ft_puthex(i / 16, str);
	result = ft_putchr(hex[i % 16]);
	if (result == -1)
		return (-1);
	len += result;
	return (len);
}

int	ft_pointer(void *ptr)
{
	int			len;
	uintptr_t	num;
	int			result;

	len = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	num = (uintptr_t)ptr;
	result = write(1, "0x", 2);
	if (result == -1)
		return (-1);
	len += result;
	len += ft_puthex(num, 'x');
	return (len);
}
