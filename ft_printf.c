/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:35:40 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/29 10:06:22 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	get_symbel(const char *str, va_list argement)
{
	if (*str && (*str == 'd' || *str == 'i'))
		return (ft_putnbr(va_arg(argement, int)));
	else if (*str && *str == 'u')
		return (ft_putnbr_u(va_arg(argement, int)));
	else if (*str && *str == 'c')
		return (ft_putchar(va_arg(argement, int)));
	else if (*str && *str == 's')
		return (ft_putstr(va_arg(argement, char *)));
	else if (*str && *str == 'x')
		return (ft_hex(va_arg(argement, unsigned int), 0, 1));
	else if (*str && *str == 'X')
		return (ft_hex(va_arg(argement, int), 1, 0));
	else if (*str && *str == 'p')
		return (ft_adress(va_arg(argement, unsigned long), 1));
	else if (*str && *str == '\n')
		return (ft_putchar('\n'));
	else if (*str && *str == '%')
		return (ft_putchar('%'));
	else if (*str)
		return (ft_putchar(*str));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	argement;
	t_var	var;

	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(argement, str);
	var.count = 0;
	var.i = 0;
	while (str[var.i])
	{
		if (str[var.i] == '%')
		{
			var.i++;
			if (str[var.i] == '#' || str[var.i] == '+' || str[var.i] == ' ')
				var.count += ft_bon(argement, &var.i, str);
			else
				var.count += get_symbel(&str[var.i], argement);
		}
		else
			var.count += ft_putchar(str[var.i]);
		if (str[var.i])
			var.i++;
	}
	va_end(argement);
	return (var.count);
}
