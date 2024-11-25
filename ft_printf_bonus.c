/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:48:51 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/25 18:03:30 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_printf.h"

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
		count += ft_hex(va_arg(argement, int), 0, 1);
	else if (*str == 'X')
		count += ft_hex(va_arg(argement, int), 1, 0);
	else if (*str == 'p')
		count += ft_adress(va_arg(argement, unsigned long), 1);
	else if (*str == '%')
		count += write(1, "%", 1);
	return (count);
}

int	fake_get_symbel(const char *str, va_list argement)
{
	int		count;
	va_list	fake_argement;

	count = 0;
	va_copy(fake_argement, argement);
	if (*str == 'd' || *str == 'i')
		count += fake_ft_putnbr(va_arg(fake_argement, int));
	else if (*str == 'u')
		count += fake_ft_putnbr_u(va_arg(fake_argement, int));
	else if (*str == 'c')
		count += 1;
	else if (*str == 's')
		count += fake_ft_putstr(va_arg(fake_argement, char *));
	else if (*str == 'x')
		count += fake_ft_hex(va_arg(fake_argement, int), 0, 1);
	else if (*str == 'X')
		count += fake_ft_hex(va_arg(fake_argement, int), 1, 0);
	else if (*str == 'p')
		count += fake_ft_adress(va_arg(fake_argement, unsigned long), 1);
	else if (*str == '%')
		count += 1;
	va_end(fake_argement);
	return (count);
}

void	check(const char *str, int *i, va_list argement, int *count_print)
{
	t_var	var;

	var.con = 0;
	(*i)++;
	if (str[*i] == '-' )
	{
		(*i)++;
		var.con = 1;
		var.num_1 = ft_atoi(&str[*i], i);
	}
	if (str[*i] >= '0' && str[*i] <= '9' && !var.con)
	{
		var.num_1 = ft_atoi(&str[*i], i);
		var.num_1 -= fake_get_symbel(&str[*i], argement);
		*count_print += ft_pading(var.num_1);
	}
	if (str[*i] == '#' || str[*i] == '+' || str[*i] == ' ')
		*count_print += ft_bon(argement, i, str);
	else
	{
		var.hhh = get_symbel(&str[*i], argement);
		if (var.con)
			*count_print += ft_pading(var.num_1 - var.hhh);
		*count_print += var.hhh;
	}
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
			check(str, &i, argement, &count_print);
		else
			count_print += ft_putchar(str[i]);
	}
	va_end(argement);
	return (count_print);
}
