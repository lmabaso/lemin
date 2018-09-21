/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:09:39 by lmabaso           #+#    #+#             */
/*   Updated: 2018/09/05 09:41:16 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

size_t		ft_lst_node_len(t_node *head)
{
	size_t	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

size_t		ft_lst_str_len(t_string *head)
{
	size_t	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void		ft_append(t_node **head, char *new_data)
{
	t_node	*new_node;
	t_node	*last;
	t_room	data;

	new_node = ft_memalloc(sizeof(t_node));
	last = *head;
	data.room_num = new_data;
	data.neighbours = NULL;
	data.previous = NULL;
	new_node->data = data;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->index = 0;
		*head = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	new_node->index = last->index + 1;
	last->next = new_node;
	return ;
}

void		ft_node_free(t_node **head)
{
	t_node	*current;
	t_node	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
