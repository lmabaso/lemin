/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_ants_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:45:57 by lmabaso           #+#    #+#             */
/*   Updated: 2018/09/03 18:46:11 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			ft_assign_routs(t_colony *ants, t_string *da_wae)
{
	while (ants)
	{
		ants->ant.room = da_wae;
		ants = ants->next;
	}
}

t_colony		*ft_pop(t_colony **head)
{
	t_colony	*pop;

	pop = NULL;
	if (!*head)
		return (NULL);
	pop = *head;
	*head = (*head)->next;
	pop->next = NULL;
	return (pop);
}

void			ft_push_to(t_colony **dest, t_colony **src)
{
	t_colony	*tmp;

	tmp = ft_pop(src);
	tmp->ant.room = tmp->ant.room->next;
	ft_trans_ant(dest, tmp);
}

void			ft_move_ants_in_maize(t_colony **ants)
{
	t_colony *tmp;

	tmp = *ants;
	while (tmp)
	{
		tmp->ant.room = tmp->ant.room->next;
		tmp = tmp->next;
	}
}

void			ft_display(t_colony *ants)
{
	t_colony *tmp;

	tmp = ants;
	while (tmp)
	{
		ft_putstr(tmp->ant.ant_name);
		ft_putchar('-');
		ft_putstr(tmp->ant.room->str);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
