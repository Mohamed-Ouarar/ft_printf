/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:30:32 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/25 18:03:44 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_printf.h"

int	condition(const char *str, int *i, int *space, int *plus)
{
	if (str[*i] == '+')
		*plus = 1;
	else if (str[*i] == ' ')
		*space = 1;
	else if (str[*i] == '#')
	{
		(*i)++;
		return (1);
	}
	(*i)++;
	return (0);
}

void	ft_vars(int *condition, int *plus, int *space, int *hash)
{
	*condition = 0;
	*plus = 0;
	*space = 0;
	*hash = 0;
}

int	ft_bon(va_list argement, int *i, const char *str)
{
	t_var	hello;

	ft_vars(&hello.condition, &hello.plus, &hello.space, &hello.hash);
	while (str[*i] && (str[*i] == ' ' || str[*i] == '+' || str[*i] == '#'))
	{
		hello.hash = condition(str, i, &hello.space, &hello.plus);
		if (hello.hash == 1)
			hello.condition = 1;
	}
	if (str[*i] == '%')
		return (ft_putchar('%'));
	else if (str[*i] && (str[*i] == 'x' || str[*i] == 'X'))
		return (ft_hash(argement, i, str, hello.condition));
	if (str[*i] && str[*i] == 's')
		return (ft_putstr(va_arg(argement, char *)));
	hello.num = va_arg(argement, int);
	if (str[*i] && (hello.num >= 0 && !hello.plus && hello.space))
		return (ft_putchar(' ') + ft_putnbr(hello.num));
	else if (str[*i] && (hello.num >= 0 && hello.plus))
		return (ft_putchar('+') + ft_putnbr(hello.num));
	else if (str[*i] && (str[*i] == 'd' || str[*i] == 'i'))
		return (ft_putnbr(hello.num));
	return (0);
}

int	ft_hash(va_list argement, int *i, const char *str, int hash_condition)
{
	int	num;

	num = va_arg(argement, int);
	if (!hash_condition)
	{
		if (num != 0 && str[*i] == 'x')
			return (ft_hex(num, 0, 1));
		else if (num != 0 && str[*i] == 'X')
			return (ft_hex(num, 1, 0));
	}
	if (num != 0 && str[*i] == 'x')
		return (ft_putstr("0x") + ft_hex(num, 0, 1));
	else if (num != 0 && str[*i] == 'X')
		return (ft_putstr("0X") + ft_hex(num, 1, 0));
	else
		return (ft_putnbr(num));
	return (0);
}
