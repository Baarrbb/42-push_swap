/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:00:29 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:10:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_up(t_stack **stack)
{
	t_stack	*ptr_up;

	if (ft_lstsize(*stack) < 2)
		return ;
	ptr_up = *stack;
	*stack = (*stack)->next;
	ptr_up->next = NULL;
	ft_lstadd_back(stack, ptr_up);
}

void	shift_up_a(t_stack **a)
{
	shift_up(a);
	ft_printf("ra\n");
}

void	shift_up_b(t_stack **b)
{
	shift_up(b);
	ft_printf("rb\n");
}

void	shift_up_ab(t_stack **a, t_stack **b)
{
	shift_up(a);
	shift_up(b);
	ft_printf("rr\n");
}
