/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:49:09 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:11:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	tab_size(char **params)
{
	int	i;

	i = 0;
	if (params)
	{
		while (params[i])
			i++;
	}
	return (i);
}

static char	**ft_realloc(char **old, char **new)
{
	char	**add;
	int		size_old;
	int		size_new;

	size_old = tab_size(old);
	size_new = tab_size(new);
	add = ft_calloc(size_old + size_new + 1, sizeof(char *));
	if (!add)
		return (0);
	return (add);
}

static char	**add_old(char **add, char **old, char **new)
{
	int	i;

	i = -1;
	if (old)
	{
		while (old[++i])
		{
			add[i] = ft_strdup(old[i]);
			if (!add[i])
			{
				free_char_tab(old);
				free_char_tab(new);
				handle_error(add);
			}
		}
		free_char_tab(old);
	}
	return (add);
}

static char	**add_params(char **old, char **new)
{
	char	**add;
	int		i;
	int		j;

	add = ft_realloc(old, new);
	if (!add)
		handle_error(old);
	add = add_old(add, old, new);
	j = -1;
	i = 0;
	while (add[i])
		i++;
	while (new[++j])
	{
		add[i] = ft_strdup(new[j]);
		i++;
	}
	free_char_tab(new);
	return (add);
}

char	**set_params(char **av)
{
	int		i;
	char	**split;
	char	**add;

	i = 0;
	add = 0;
	if (!av[0])
		return (0);
	if (!av[0][0])
		handle_error(0);
	split = ft_split(av[0], ' ');
	if (!split || !split[0])
		handle_error(split);
	add = add_params(0, split);
	while (av[++i])
	{
		split = ft_split(av[i], ' ');
		if (!split || !split[0])
		{
			free_char_tab(split);
			handle_error(add);
		}
		add = add_params(add, split);
	}
	return (add);
}
