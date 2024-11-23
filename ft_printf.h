/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:02:01 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/23 11:17:20 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putnbr(int nb);
int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_hex(unsigned int num, int up, int low);
int	ft_adress(unsigned long long num, int ox);
int	ft_putnbr_u(unsigned int nb);

#endif