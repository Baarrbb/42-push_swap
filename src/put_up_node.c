/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_up_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:40:59 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:10:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	both_sup_med(t_stack **a, t_stack **b, t_stack *node)
{
	int	pos_a;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	pos_a = target_pos(a, node->target);
	while (pos_a < size_a && node->curr_pos < size_b)
	{
		shift_down_ab(a, b);
		pos_a++;
		node->curr_pos++;
	}
	if (node->curr_pos == size_b)
	{
		while (pos_a++ < size_a)
			shift_down_a(a);
	}
	else
	{
		while (node->curr_pos++ < size_b)
			shift_down_b(b);
	}
}

static void	both_inf_med(t_stack **a, t_stack **b, t_stack *node)
{
	int	pos_a;
	int	pos_b;

	pos_a = target_pos(a, node->target);
	pos_b = node->curr_pos;
	while (pos_a != 0 && pos_b != 0)
	{
		shift_up_ab(a, b);
		pos_a--;
		pos_b--;
	}
	if (pos_b == 0)
	{
		while (pos_a-- != 0)
			shift_up_a(a);
	}
	else
	{
		while (pos_b-- != 0)
			shift_up_b(b);
	}
}

static void	b_sup_med(t_stack **a, t_stack **b, t_stack *node, int size_b)
{
	int	pos_a;
	int	pos_b;

	pos_a = target_pos(a, node->target);
	pos_b = node->curr_pos;
	while (pos_a != 0)
	{
		shift_up_a(a);
		pos_a--;
	}
	while (pos_b < size_b)
	{
		shift_down_b(b);
		pos_b++;
	}
}

static void	b_inf_med(t_stack **a, t_stack **b, t_stack *node, int size_a)
{
	int	pos_a;
	int	pos_b;

	pos_a = target_pos(a, node->target);
	pos_b = node->curr_pos;
	while (pos_b != 0)
	{
		shift_up_b(b);
		pos_b--;
	}
	while (pos_a < size_a)
	{
		shift_down_a(a);
		pos_a++;
	}
}

void	put_up_node(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		pos_a;
	int		size_a;
	int		size_b;

	tmp = *b;
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	while (tmp)
	{
		if (tmp->cout == 1 || tmp->cout == min_cost(b))
		{
			pos_a = target_pos(a, tmp->target);
			if (pos_a > size_a / 2 && tmp->curr_pos > size_b / 2)
				both_sup_med(a, b, tmp);
			else if (pos_a <= size_a / 2 && tmp->curr_pos <= size_b / 2)
				both_inf_med(a, b, tmp);
			else if (pos_a <= size_a && tmp->curr_pos > size_b / 2)
				b_sup_med(a, b, tmp, size_b);
			else
				b_inf_med(a, b, tmp, size_a);
			break ;
		}
		tmp = tmp->next;
	}
}
