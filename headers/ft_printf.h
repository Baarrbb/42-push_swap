/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:10:37 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:10:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		single_char(unsigned int c);
int		putstr(const char *str);
int		print_percent(void);
int		ft_itoa(long n, char const *base, int base_len);
int		ft_itoa_adr(unsigned long ptr);

#endif