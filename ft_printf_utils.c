/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:35:52 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/29 10:07:08 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int num, int up, int low)
{
	char	*base_up;
	char	*base_low;
	int		count;

	base_low = "0123456789abcdef";
	base_up = "0123456789ABCDEF";
	count = 0;
	if (num < 16 && low)
		count += ft_putchar(base_low[num]);
	else if (num < 16 && up)
		count += ft_putchar(base_up[num]);
	else
	{
		count += ft_hex(num / 16, up, low);
		count += ft_hex(num % 16, up, low);
	}
	return (count);
}

int	ft_adress(unsigned long num, int ox)
{
	char	*base_low;
	int		count;

	base_low = "0123456789abcdef";
	count = 0;
	if (ox)
	{
		count += ft_putstr("0x");
		ox = 0;
	}
	if (num < 16)
		count += ft_putchar(base_low[num]);
	else
	{
		count += ft_adress(num / 16, ox);
		count += ft_adress(num % 16, ox);
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	char	x;
	int		count;

	count = 0;
	if (nb == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
	{
		x = nb + 48;
		count += ft_putchar(x);
	}
	return (count);
}

int	ft_putnbr_u(unsigned int nb)
{
	char	x;
	int		count;

	count = 0;
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
	{
		x = nb + 48;
		count += ft_putchar(x);
	}
	return (count);
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
	{
		count += ft_putstr("(null)");
		return (count);
	}
	while (str[i])
	{
		count += write(1, &str[i], 1);
		i++;
	}
	return (count);
}
