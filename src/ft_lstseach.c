/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstseach.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:38:15 by lmabaso           #+#    #+#             */
/*   Updated: 2018/09/04 15:40:24 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				ft_search_node(t_node *head, char *x)
{
	t_node		*current;

	current = head;
	while (current != NULL)
	{
		if (ft_strequ(current->data.room_num, x))
			return (1);
		current = current->next;
	}
	return (0);
}

void			ft_get_room(t_node **head, char *room)
{
	while ((*head) != NULL)
	{
		if (ft_strequ((*head)->data.room_num, room))
			return ;
		(*head) = (*head)->next;
	}
}

t_node			*ft_find_room(t_node *head, char *room)
{
	t_node		*current;

	current = head;
	while (current != NULL)
	{
		if (ft_strequ(current->data.room_num, room))
			return (current);
		current = current->next;
	}
	return (NULL);
}

int				ft_search(t_string *str, char *to_find)
{
	t_string	*tmp;

	tmp = str;
	while (tmp)
	{
		if (ft_strequ(tmp->str, to_find))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
