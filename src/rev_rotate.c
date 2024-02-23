/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:18:40 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:10:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_down(t_stack **stack)
{
	t_stack	*last;
	t_stack	*new_last;
	t_stack	*curr;

	if (ft_lstsize(*stack) < 2)
		return ;
	last = ft_lstlast(*stack);
	new_last = NULL;
	curr = *stack;
	while (curr->next != NULL)
	{
		new_last = curr;
		curr = curr->next;
	}
	new_last->next = NULL;
	ft_lstadd_front(stack, last);
}

void	shift_down_a(t_stack **stack)
{
	shift_down(stack);
	ft_printf("rra\n");
}

void	shift_down_b(t_stack **stack)
{
	shift_down(stack);
	ft_printf("rrb\n");
}

void	shift_down_ab(t_stack **a, t_stack **b)
{
	shift_down(a);
	shift_down(b);
	ft_printf("rrr\n");
}
