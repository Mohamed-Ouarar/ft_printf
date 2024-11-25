/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:57:16 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/25 18:05:19 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_atoi(const char *str, int *index)
{
	int			i;
	int			result;

	i = 0;
	result = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - 48;
		(*index)++;
		i++;
	}
	return (result);
}

int	ft_pading(int num)
{
	int	count;

	count = 0;
	while (num > 0)
	{
		count += ft_putchar(' ');
		num--;
	}
	return (count);
}
