/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:01:24 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/25 18:03:19 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	get_symbel(const char *str, va_list argement)
{
	int	count;

	count = 0;
	if (*str == 'd' || *str == 'i')
		count += ft_putnbr(va_arg(argement, int));
	else if (*str == 'u')
		count += ft_putnbr_u(va_arg(argement, int));
	else if (*str == 'c')
		count += ft_putchar(va_arg(argement, int));
	else if (*str == 's')
		count += ft_putstr(va_arg(argement, char *));
	else if (*str == 'x')
		count += ft_hex(va_arg(argement, unsigned int), 0, 1);
	else if (*str == 'X')
		count += ft_hex(va_arg(argement, int), 1, 0);
	else if (*str == 'p')
		count += ft_adress(va_arg(argement, unsigned long), 1);
	else if (*str == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count_print;
	int		i;
	va_list	argement;

	i = -1;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(argement, str);
	count_print = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			count_print += get_symbel(str + i, argement);
		}
		else
			count_print += ft_putchar(str[i]);
	}
	va_end(argement);
	return (count_print);
}
