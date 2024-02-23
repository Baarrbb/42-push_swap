/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_val_misc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:12:55 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:10:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	val_max(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = tmp->nb;
	while (tmp)
	{
		if (tmp->nb > max)
			max = tmp->nb;
		tmp = tmp->next;
	}
	return (max);
}

int	val_min(t_stack **stack)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack;
	min = tmp->nb;
	while (tmp)
	{
		if (tmp->nb < min)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}

void	current_position(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->curr_pos = i;
		i++;
		tmp = tmp->next;
	}
}

int	target_pos(t_stack **stack, int target)
{
	t_stack	*tmp;
	int		pos;

	tmp = *stack;
	pos = 0;
	while (tmp)
	{
		if (tmp->nb == target)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int	min_cost(t_stack **stack)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack;
	min = tmp->cout;
	while (tmp)
	{
		if (tmp->cout < min)
			min = tmp->cout;
		tmp = tmp->next;
	}
	return (min);
}
