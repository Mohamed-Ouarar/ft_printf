/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:06:35 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/29 10:06:36 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putnbr(int nb);
int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_hex(unsigned int num, int up, int low);
int		ft_adress(unsigned long num, int ox);
int		ft_putnbr_u(unsigned int nb);
int		ft_bon(va_list argement, int *i, const char *str);
int		ft_hash(va_list argement, int *i, const char *str, int hash_condition);
void	condition(const char *str, int *ft_hash, int *space, int *plus);

typedef struct ft_printf
{
	int	number;
	int	space;
	int	plus;
	int	hash;
	int	i;
	int	count;
}	t_var;

#endif