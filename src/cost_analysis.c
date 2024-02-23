/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:51:49 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:10:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cost_analysis(t_stack **a, t_stack *node, int size_a, int size_b)
{
	int	pos_a;
	int	pos_b;

	pos_a = target_pos(a, node->target);
	pos_b = node->curr_pos;
	if (pos_a > size_a / 2 && pos_b > size_b / 2)
	{
		if ((size_a - pos_a) > (size_b - pos_b))
			node->cout = (size_a - pos_a) + 1;
		else
			node->cout = (size_b - pos_b) + 1;
	}
	else if (pos_a > size_a / 2 && pos_b <= size_b / 2)
		node->cout = (size_a - pos_a) + pos_b + 1;
	else if (pos_a <= size_a / 2 && pos_b > size_b / 2)
		node->cout = (size_b - pos_b) + pos_a + 1;
	else
	{
		if (pos_a > pos_b)
			node->cout = pos_a;
		else
			node->cout = pos_b;
	}
}

void	get_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		size_a;
	int		size_b;

	tmp = *b;
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	while (tmp)
	{
		cost_analysis(a, tmp, size_a, size_b);
		tmp = tmp->next;
	}
}
