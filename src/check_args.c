/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:13:48 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:10:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_args_num(char **params)
{
	int		i;
	int		j;
	int		k;

	k = -1;
	j = 0;
	i = 0;
	while (params[++k])
	{
		if (params[i][j] == '-' || params[i][j] == '+')
			j++;
		if (!params[i][j])
			handle_error(params);
		while (params[i][j] >= '0' && params[i][j] <= '9')
			j++;
		if (j != (int)ft_strlen(params[k]))
			handle_error(params);
		j = 0;
		i++;
	}
}

static int	len_int(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}

static void	check_args_size(char **params)
{
	int		i;
	int		nb;
	int		len;

	i = -1;
	while (params[++i])
	{
		nb = ft_atoi(params[i]);
		len = len_int(nb);
		if (params[i][0] == '+')
			len++;
		if (len != (int)ft_strlen(params[i]))
			handle_error(params);
	}
}

static void	check_double(char **params)
{
	int		i;
	int		j;

	i = -1;
	while (params[++i])
	{
		j = i;
		while (params[++j])
		{
			if (ft_atoi(params[i]) == ft_atoi(params[j]))
				handle_error(params);
		}
	}
}

void	check_args(char **params)
{
	check_args_num(params);
	check_args_size(params);
	check_double(params);
}
