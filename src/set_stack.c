/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:22:44 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:10:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sort_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	tmp = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

static int	*char_to_int_tab(char **av, int size)
{
	int	*tab;
	int	i;

	tab = malloc(size * sizeof(int));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		if (av[i])
			tab[i] = ft_atoi(av[i]);
	}
	tab = sort_tab(tab, size);
	return (tab);
}

static int	end_pos(int *tab, int size, int nb)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (tab[i] == nb)
			return (i);
	}
	return (-1);
}

t_stack	*set_stack(char **av, int ac)
{
	int		i;
	int		nb;
	int		*tab;
	t_stack	*stack_a;
	t_stack	*node;

	i = -1;
	tab = char_to_int_tab(av, ac - 1);
	if (!tab)
		return (0);
	stack_a = 0;
	node = 0;
	while (av[++i])
	{
		nb = ft_atoi(av[i]);
		node = ft_lstnew(nb);
		if (!node)
			free_stack(&stack_a, av, 1);
		node->end_pos = end_pos(tab, ac - 1, nb);
		ft_lstadd_back(&stack_a, node);
	}
	free(tab);
	return (stack_a);
}
