/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:54:46 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:10:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	if (ft_lstsize(*a) < 1)
		return ;
	ptr = *a;
	(*a) = (*a)->next;
	ptr->next = NULL;
	ft_lstadd_front(b, ptr);
	ft_printf("pb\n");
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	if (ft_lstsize(*b) < 1)
		return ;
	ptr = *b;
	(*b) = (*b)->next;
	ptr->next = NULL;
	ft_lstadd_front(a, ptr);
	ft_printf("pa\n");
}

void	silent_push_b(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	if (ft_lstsize(*a) < 1)
		return ;
	ptr = *a;
	(*a) = (*a)->next;
	ptr->next = NULL;
	ft_lstadd_front(b, ptr);
}

void	silent_push_a(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	if (ft_lstsize(*b) < 1)
		return ;
	ptr = *b;
	(*b) = (*b)->next;
	ptr->next = NULL;
	ft_lstadd_front(a, ptr);
}
