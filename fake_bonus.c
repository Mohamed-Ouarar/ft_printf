/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:54:16 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/25 17:52:52 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	fake_ft_hex(unsigned int num, int up, int low)
{
	char	*base_up;
	char	*base_low;
	int		count;

	base_low = "0123456789abcdef";
	base_up = "0123456789ABCDEF";
	count = 0;
	if (num < 16 && low)
		count += 1;
	else if (num < 16 && up)
		count += 1;
	else
	{
		count += fake_ft_hex(num / 16, up, low);
		count += fake_ft_hex(num % 16, up, low);
	}
	return (count);
}

int	fake_ft_adress(unsigned long num, int ox)
{
	char	*base_low;
	int		count;

	base_low = "0123456789abcdef";
	count = 0;
	if (ox)
	{
		count += fake_ft_putstr("0x");
		ox = 0;
	}
	if (num < 16)
		count += 1;
	else
	{
		count += fake_ft_adress(num / 16, ox);
		count += fake_ft_adress(num % 16, ox);
	}
	return (count);
}

int	fake_ft_putnbr(int nb)
{
	char	x;
	int		count;

	count = 0;
	if (nb == -2147483648)
	{
		count += fake_ft_putstr("-2147483648");
		return (count);
	}
	if (nb < 0)
	{
		count += 1;
		nb = nb * -1;
	}
	if (nb > 9)
	{
		count += fake_ft_putnbr(nb / 10);
		count += fake_ft_putnbr(nb % 10);
	}
	else
	{
		x = nb + 48;
		count += 1;
	}
	return (count);
}

int	fake_ft_putnbr_u(unsigned int nb)
{
	char	x;
	int		count;

	count = 0;
	if (nb > 9)
	{
		count += fake_ft_putnbr(nb / 10);
		count += fake_ft_putnbr(nb % 10);
	}
	else
	{
		x = nb + 48;
		count += 1;
	}
	return (count);
}

int	fake_ft_putstr(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
	{
		count += fake_ft_putstr("(null)");
		return (count);
	}
	while (str[i])
	{
		count += 1;
		i++;
	}
	return (count);
}
