/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:04:00 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:10:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*strjoin(char *dst, char *src);
int		charset(char *str);

#endif