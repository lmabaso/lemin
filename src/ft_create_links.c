/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_links.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:06:53 by lmabaso           #+#    #+#             */
/*   Updated: 2018/09/03 18:31:11 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			ft_print_error(t_data *c)
{
	ft_putendl("error");
	free(c);
	exit(1);
}

void			ft_add_links(t_node **map, t_data *c, char *s1, char *s2)
{
	if (ft_search_node(*map, s1))
	{
		ft_add_coordinates(map, c->cells, s1);
		ft_add_neigbour(map, s1, ft_strdup(s2));
	}
	else
	{
		ft_append(map, ft_strdup(s1));
		ft_add_coordinates(map, c->cells, s1);
		ft_add_neigbour(map, s1, ft_strdup(s2));
	}
	if (ft_search_node(*map, s2))
	{
		ft_add_coordinates(map, c->cells, s2);
		ft_add_neigbour(map, s2, ft_strdup(s1));
	}
	else
	{
		ft_append(map, ft_strdup(s2));
		ft_add_coordinates(map, c->cells, s2);
		ft_add_neigbour(map, s2, ft_strdup(s1));
	}
}

int				ft_assess(t_node **map, t_data *c, char *s1, char *s2)
{
	if (ft_strequ(s1, s2))
	{
		ft_print_error(c);
	}
	if (ft_search_node(c->cells, s1)
			&& ft_search_node(c->cells, s2))
	{
		ft_add_links(map, c, s1, s2);
	}
	else
		return (1);
	return (0);
}

void			ft_creat_links(t_node **map, t_data *c)
{
	t_string	*tmp;
	char		**s;
	int			i;

	tmp = c->tubs;
	while (tmp)
	{
		s = ft_strsplit(tmp->str, '-');
		if (ft_double_ptr_len((void **)s) == 2)
			if (ft_assess(map, c, s[0], s[1]))
			{
				i = -1;
				while (s[++i])
					free(s[i]);
				free(s);
				s = NULL;
				ft_print_error(c);
			}
		i = -1;
		while (s[++i])
			free(s[i]);
		free(s);
		s = NULL;
		tmp = tmp->next;
	}
}
