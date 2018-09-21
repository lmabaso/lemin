/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:45:51 by lmabaso           #+#    #+#             */
/*   Updated: 2018/09/04 15:52:44 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_node			*ft_as_lowest_f(t_node *head)
{
	t_node		*tmp;
	t_node		*winner;

	tmp = head;
	winner = ft_memalloc(sizeof(t_node));
	winner->data = head->data;
	while (tmp)
	{
		if (winner->data.f > tmp->data.f)
			winner->data = tmp->data;
		tmp = tmp->next;
	}
	return (winner);
}

t_astar			*init_astar(void)
{
	t_astar		*s;

	s = ft_memalloc(sizeof(t_astar));
	s->path_to_finish = NULL;
	s->open_set = NULL;
	s->closed_set = NULL;
	s->path_to_finish = NULL;
	s->winner = NULL;
	s->current = NULL;
	s->tmp = NULL;
	s->neighbour = NULL;
	s->tmp_g = 0.0;
	s->winner = NULL;
	s->tmp_nei = NULL;
	return (s);
}

void			ft_astar_cont(t_astar *s, t_data *c, t_node *map)
{
	s->element = ft_find_room(map, s->current->data.room_num)->data;
	s->tmp_nei = s->element.neighbours;
	while (s->tmp_nei)
	{
		s->neighbour = &ft_find_room(map, s->tmp_nei->str)->data;
		s->neighbour->previous = &s->current->data;
		if (!ft_search_node(s->closed_set, s->neighbour->room_num))
		{
			s->tmp_g = s->current->data.g + 1;
			if (ft_search_node(s->open_set, s->neighbour->room_num))
			{
				if (s->tmp_g < s->neighbour->g)
					s->neighbour->g = s->tmp_g;
			}
			else
				s->neighbour->g = s->tmp_g;
			s->neighbour->h = ft_get_distance(s->neighbour->pos,
					ft_find_room(map, c->end)->data.pos);
			s->neighbour->f = s->neighbour->g + s->neighbour->h;
			ft_append_data(&s->open_set,
					ft_find_room(map, s->neighbour->room_num)->data);
		}
		s->tmp_nei = s->tmp_nei->next;
	}
}

void			ft_make_path(t_astar *s)
{
	s->tmp = s->current;
	s->winner = s->tmp;
	ft_append_string(&s->path_to_finish,
			ft_strdup(s->tmp->data.room_num));
	while (s->tmp->data.previous != NULL)
	{
		ft_append_string(&s->path_to_finish,
				ft_strdup(s->tmp->data.previous->room_num));
		s->tmp->data = *s->tmp->data.previous;
	}
	ft_node_free(&s->winner);
}

t_string		*ft_astar(t_data *c, t_node *map)
{
	t_astar		*s;

	s = init_astar();
	ft_append_data(&s->open_set, ft_find_room(map, c->start)->data);
	while (ft_lst_node_len(s->open_set) > 0)
	{
		s->winner = ft_as_lowest_f(s->open_set);
		s->current = s->winner;
		if (ft_strequ(s->current->data.room_num, c->end))
		{
			ft_make_path(s);
			break ;
		}
		delete_node(&s->open_set, s->current->data.room_num);
		ft_append_data(&s->closed_set,
				ft_find_room(map, s->current->data.room_num)->data);
		ft_astar_cont(s, c, map);
	}
	ft_node_free(&s->closed_set);
	ft_node_free(&s->open_set);
	ft_reverse(&s->path_to_finish);
	return (s->path_to_finish);
}
