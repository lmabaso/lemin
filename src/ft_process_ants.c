/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:37:09 by lmabaso           #+#    #+#             */
/*   Updated: 2018/09/03 18:39:58 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			ft_trans_ant(t_colony **head, t_colony *new_data)
{
	t_colony	*new_node;
	t_colony	*last;

	new_node = ft_memalloc(sizeof(t_colony));
	last = *head;
	new_node = new_data;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return ;
}

void			ft_append_ant(t_colony **head, char *new_data)
{
	t_colony	*new_node;
	t_colony	*last;

	new_node = ft_memalloc(sizeof(t_colony));
	last = *head;
	new_node->ant.ant_name = new_data;
	new_node->ant.room = NULL;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return ;
}

t_colony		*ft_get_ants(t_data *c)
{
	t_colony	*ant_farm;
	int			i;

	i = 1;
	ant_farm = NULL;
	while (i <= c->nb_ants)
	{
		ft_append_ant(&ant_farm, ft_strjoin("L", ft_itoa(i)));
		i++;
	}
	return (ant_farm);
}

void			ft_get_moving(t_ant mr_ant)
{
	while (mr_ant.room)
	{
		ft_putstr(mr_ant.ant_name);
		ft_putchar('-');
		ft_putstr(mr_ant.room->str);
		ft_putchar(' ');
		mr_ant.room = mr_ant.room->next;
	}
}

void			ft_move_ants(t_string *route, t_data *c)
{
	t_colony	*ant_farm;
	t_colony	*tmp;

	ant_farm = ft_get_ants(c);
	tmp = ant_farm;
	while (tmp)
	{
		tmp->ant.room = route->next;
		ft_get_moving(tmp->ant);
		tmp = tmp->next;
		ft_putchar('\n');
	}
}
