/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:21:10 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 13:11:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	llen;

	if (!big && len == 0)
		return (NULL);
	llen = ft_strlen(little);
	if (llen == 0)
		return ((char *)big);
	count = 0;
	while (*big && count < len)
	{
		if ((ft_strncmp((char *)big, (char *)little, llen) == 0)
			&& count + llen <= len)
		{
			return ((char *)big);
		}
		big++;
		count++;
	}
	return (0);
}
