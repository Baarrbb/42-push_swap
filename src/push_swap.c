/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:10 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:10:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_target(t_stack **a, t_stack **b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	int		min_a;
	int		max_a;

	tmpb = *b;
	min_a = val_min(a);
	max_a = val_max(a);
	while (tmpb)
	{
		tmpa = *a;
		tmpb->target = max_a;
		while (tmpa)
		{
			if (tmpb->nb > max_a)
				tmpb->target = min_a;
			else if (tmpa->nb > tmpb->nb && tmpb->target >= tmpa->nb)
				tmpb->target = tmpa->nb;
			tmpa = tmpa->next;
		}
		tmpb = tmpb->next;
	}
}

static void	algo(t_stack **a, t_stack **b, int size, int mediane)
{
	push_b(a, b);
	push_b(a, b);
	while (size > 3)
	{
		if ((*a)->end_pos > mediane && size > mediane)
			shift_up_a(a);
		else
		{
			push_b(a, b);
			size--;
		}
		current_position(a);
		current_position(b);
	}
	sort_three(a);
	while (*b != NULL)
	{
		current_position(a);
		current_position(b);
		find_target(a, b);
		get_cost(a, b);
		put_up_node(a, b);
		push_a(a, b);
	}
	sort_a(a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**params;
	int		size;

	params = set_params(av + 1);
	if (!params)
		return (0);
	check_args(params);
	stack_b = NULL;
	stack_a = set_stack(params, ac);
	if (!stack_a)
		return (0);
	size = ft_lstsize(stack_a);
	if (is_sort(&stack_a))
		free_stack(&stack_a, params, 1);
	if (size == 2)
		swap_a(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	else
		algo(&stack_a, &stack_b, size - 2, size / 2);
	free_stack(&stack_a, params, 1);
	return (0);
}
