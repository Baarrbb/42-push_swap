/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:34:17 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:10:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	check_move_bis(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strncmp(move, "ss\n", ft_strlen(move)))
	{
		swap_stack(a);
		swap_stack(b);
	}
	else if (!ft_strncmp(move, "rr\n", ft_strlen(move)))
	{
		shift_up(a);
		shift_up(b);
	}
	else if (!ft_strncmp(move, "rrr\n", ft_strlen(move)))
	{
		shift_down(a);
		shift_down(b);
	}
}

static void	check_move(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strncmp(move, "sa\n", ft_strlen(move)))
		swap_stack(a);
	else if (!ft_strncmp(move, "sb\n", ft_strlen(move)))
		swap_stack(b);
	else if (!ft_strncmp(move, "ss\n", ft_strlen(move)))
		check_move_bis(a, b, move);
	else if (!ft_strncmp(move, "pa\n", ft_strlen(move)))
		silent_push_a(a, b);
	else if (!ft_strncmp(move, "pb\n", ft_strlen(move)))
		silent_push_b(a, b);
	else if (!ft_strncmp(move, "ra\n", ft_strlen(move)))
		shift_up(a);
	else if (!ft_strncmp(move, "rb\n", ft_strlen(move)))
		shift_up(b);
	else if (!ft_strncmp(move, "rr\n", ft_strlen(move)))
		check_move_bis(a, b, move);
	else if (!ft_strncmp(move, "rra\n", ft_strlen(move)))
		shift_down(a);
	else if (!ft_strncmp(move, "rrb\n", ft_strlen(move)))
		shift_down(b);
	else if (!ft_strncmp(move, "rrr\n", ft_strlen(move)))
		check_move_bis(a, b, move);
	else
		write(2, "Error\n", 6);
}

static void	check_stack(char **args, t_stack **a, t_stack **b)
{
	if (!is_sort(a) || ft_lstsize(*b))
		ft_printf("KO\n");
	if (is_sort(a) && !ft_lstsize(*b))
		ft_printf("OK\n");
	free_stack(a, 0, 0);
	free_stack(b, args, 1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*move;
	char	**params;

	params = set_params(av + 1);
	if (!params)
		return (0);
	check_args(params);
	stack_b = NULL;
	stack_a = set_stack(params, ac);
	move = get_next_line(0);
	while (move)
	{
		check_move(&stack_a, &stack_b, move);
		free(move);
		move = get_next_line(0);
	}
	if (move)
		free(move);
	check_stack(params, &stack_a, &stack_b);
	return (0);
}
