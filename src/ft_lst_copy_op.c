/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_copy_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:57:26 by lmabaso           #+#    #+#             */
/*   Updated: 2018/09/04 15:09:26 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_string		*copy_string(t_string *l1)
{
	t_string	*l2;
	t_string	*pre_elem;
	t_string	*elem;

	l2 = NULL;
	pre_elem = NULL;
	while (l1)
	{
		if (!(elem = ft_memalloc(sizeof(t_string))))
			return (NULL);
		elem->str = ft_strdup(l1->str);
		elem->next = NULL;
		if (!l2)
		{
			l2 = elem;
			pre_elem = elem;
		}
		else
		{
			pre_elem->next = elem;
			pre_elem = elem;
		}
		l1 = l1->next;
	}
	return (l2);
}

t_node			*ft_node_dup(t_node *l1)
{
	t_node		*elem;

	elem = ft_memalloc(sizeof(t_node));
	if (elem == NULL)
		exit(1);
	elem->data = l1->data;
	elem->data.f = l1->data.f;
	elem->data.g = l1->data.g;
	elem->data.neighbours = copy_string(l1->data.neighbours);
	elem->data.previous = NULL;
	elem->data.room_num = l1->data.room_num;
	elem->next = NULL;
	return (elem);
}
