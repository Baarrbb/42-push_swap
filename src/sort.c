/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:22:14 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:10:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_stack **a)
{
	t_stack	*tmp;
	int		count;

	tmp = *a;
	count = 1;
	if (*a == NULL)
		return (0);
	if ((*a)->next)
	{
		while (tmp->next && tmp->next->nb > tmp->nb)
		{
			count++;
			tmp = tmp->next;
		}
	}
	if (count == ft_lstsize(*a))
		return (1);
	else
		return (0);
}

void	sort_three(t_stack **a)
{
	t_stack	*tmp;

	if (is_sort(a))
		return ;
	tmp = *a;
	if (tmp->nb == val_max(a))
	{
		shift_up_a(a);
		if (!is_sort(a))
			swap_a(a);
	}
	else if (tmp->next->nb == val_max(a))
	{
		shift_down_a(a);
		if (!is_sort(a))
			swap_a(a);
	}
	else
		swap_a(a);
}

void	sort_a(t_stack **a)
{
	t_stack	*tmp;
	int		size;
	int		min;

	tmp = *a;
	size = ft_lstsize(*a);
	min = val_min(a);
	current_position(a);
	while (tmp)
	{
		if (tmp->nb == min)
		{
			while (tmp->curr_pos != 0)
			{
				if (tmp->curr_pos <= size / 2)
					shift_up_a(a);
				else
					shift_down_a(a);
				current_position(a);
			}
			break ;
		}
		tmp = tmp->next;
	}
}
