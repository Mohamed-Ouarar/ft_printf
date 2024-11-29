/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:35:57 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/29 10:07:03 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	condition(const char *str, int *ft_hash, int *space, int *plus)
{
	if (*str == '+')
		*plus = 1;
	else if (*str == ' ')
		*space = 1;
	else if (*str == '#')
		*ft_hash = 1;
}

void	ft_vars(int *plus, int *space, int *hash)
{
	*plus = 0;
	*space = 0;
	*hash = 0;
}

int	ft_bon(va_list argement, int *i, const char *str)
{
	t_var	v;

	ft_vars(&v.plus, &v.space, &v.hash);
	while (str[*i] && (str[*i] == ' ' || str[*i] == '+' || str[*i] == '#'))
	{
		condition(str + *i, &v.hash, &v.space, &v.plus);
		(*i)++;
	}
	if (str[*i] == 'p')
		return (ft_adress(va_arg(argement, unsigned long), 1));
	else if (str[*i] && (str[*i] == 'x' || str[*i] == 'X'))
		return (ft_hash(argement, i, str, v.hash));
	if (str[*i] && str[*i] == 's')
		return (ft_putstr(va_arg(argement, char *)));
	v.number = va_arg(argement, int);
	if ((str[*i] == 'd' || str[*i] == 'i') && (v.number >= 0 && v.plus))
		return (ft_putchar('+') + ft_putnbr(v.number));
	else if ((str[*i] == 'd' || str[*i] == 'i') && (v.number >= 0 && v.space))
		return (ft_putchar(' ') + ft_putnbr(v.number));
	else if (str[*i] && (str[*i] == 'd' || str[*i] == 'i'))
		return (ft_putnbr(v.number));
	else if (str[*i])
		return (ft_putchar(str[*i]));
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
