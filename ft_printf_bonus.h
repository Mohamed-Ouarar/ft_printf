/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:27:51 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/25 18:06:11 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		condition(const char *str, int *i, int *space_condition,
			int *plus_condition);
int		ft_bon(va_list argement, int *i, const char *str);
int		ft_hash(va_list argement, int *i, const char *str, int hash_condition);
int		ft_atoi(const char *str, int *index);
int		ft_pading(int num);

int		fake_ft_hex(unsigned int num, int up, int low);
int		fake_ft_adress(unsigned long num, int ox);
int		fake_ft_putnbr(int nb);
int		fake_ft_putnbr_u(unsigned int nb);
int		fake_ft_putstr(char *str);
void	check(const char *str, int *i, va_list argement, int *count_print);

typedef struct ft_printf
{
	int	num;
	int	space;
	int	plus;
	int	hash;
	int	condition;
	int	con;
	int	num_1;
	int	hhh;
}	t_var;

#endif