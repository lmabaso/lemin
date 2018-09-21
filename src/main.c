/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:03:31 by lmabaso           #+#    #+#             */
/*   Updated: 2018/09/04 12:41:38 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				ft_bouncer(t_colony *ft_move_ants_in_maize, char *room)
{
	t_colony	*tmp;

	tmp = ft_move_ants_in_maize;
	while (tmp)
	{
		if (ft_strequ(tmp->ant.room->str, room))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void			ft_ant_op(t_data *c, t_node *map, t_string *input)
{
	t_string	*q;
	t_colony	*ants_in_start;
	t_colony	*ants_in_maize;

	ants_in_maize = NULL;
	q = ft_astar(c, map);
	if (!q)
	{
		ft_node_str_free(&input);
		ft_print_error(c);
	}
	ants_in_start = ft_get_ants(c);
	ft_assign_routs(ants_in_start, q);
	ft_push_to(&ants_in_maize, &ants_in_start);
	ft_display(ants_in_maize);
	while (ants_in_maize)
	{
		ft_move_ants_in_maize(&ants_in_maize);
		if (ft_bouncer(ants_in_maize, q->next->str))
			if (ants_in_start)
				ft_push_to(&ants_in_maize, &ants_in_start);
		ft_display(ants_in_maize);
		ft_remove_ants_at_end(&ants_in_maize, c);
	}
	ft_node_str_free(&q);
}

void			ft_clean(t_data *c, t_node *map)
{
	free(c->start);
	free(c->end);
	ft_node_str_free(&c->tubs);
	ft_node_free2(&c->cells);
	free(c);
	ft_free_map(&map);
}

int				main(void)
{
	char		*line;
	t_data		*c;
	t_node		*map;
	t_string	*input;

	c = ft_memalloc(sizeof(t_data));
	map = NULL;
	line = NULL;
	while (get_next_line(0, &line))
		ft_append_string(&input, line);
	if (ft_error_handle(&input))
	{
		ft_node_str_free(&input);
		ft_print_error(c);
	}
	ft_process_input(input, c);
	ft_show_input(input);
	ft_node_str_free(&input);
	free(input);
	ft_creat_links(&map, c);
	ft_ant_op(c, map, input);
	ft_clean(c, map);
	return (1);
}
