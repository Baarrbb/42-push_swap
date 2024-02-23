/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:07:38 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:10:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack)
{
	t_stack	*ptr_up;
	t_stack	*ptr_down;

	if (ft_lstsize(*stack) < 2)
		return ;
	ptr_up = *stack;
	ptr_down = (*stack)->next;
	ptr_up->next = (*stack)->next->next;
	ptr_down->next = ptr_up;
	*stack = ptr_down;
}

void	swap_a(t_stack **a)
{
	swap_stack(a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **b)
{
	swap_stack(b);
	ft_printf("sb\n");
}

void	swap_s(t_stack **a, t_stack **b)
{
	swap_a(a);
	swap_b(b);
	ft_printf("ss\n");
}
