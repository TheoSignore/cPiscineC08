/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:00:02 by tsignore          #+#    #+#             */
/*   Updated: 2020/07/22 11:11:46 by tsignore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char				*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*dup;

	dup = (char *)malloc(ft_strlen(src) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < ft_strlen(src) + 1)
	{
		dup[i] = src[i];
	}
	return (dup);
}

t_stock_str			ft_ctor(char *str)
{
	t_stock_str str_more;

	str_more.size = ft_strlen(str);
	str_more.str = str;
	str_more.copy = ft_strdup(str);
	return (str_more);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < ac)
		tab[i] = ft_ctor(av[i]);
	tab[i] = ft_ctor("");
	return (tab);
}
