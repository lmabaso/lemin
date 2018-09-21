/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proccess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:04:04 by lmabaso           #+#    #+#             */
/*   Updated: 2018/09/03 17:51:30 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			ft_do_map(char *str, t_data *c)
{
	char		**s;
	int			i;
	t_room		tmpr;

	s = ft_strsplit(str, ' ');
	if (ft_double_ptr_len((void **)s) == 3)
	{
		if (c->fstart == 1)
			c->start = ft_strdup(s[0]);
		if (c->fend == 1)
			c->end = ft_strdup(s[0]);
		tmpr.room_num = ft_strdup(s[0]);
		tmpr.pos.x = ft_atoi(s[1]);
		tmpr.pos.y = ft_atoi(s[2]);
		ft_append_data(&c->cells, tmpr);
	}
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	s = NULL;
}

void			ft_do_links(t_string *input, t_string *tmp, t_data *c)
{
	while (tmp)
	{
		if (tmp->str && tmp->str[0] == '#')
		{
			ft_putendl(tmp->str);
			if (!ft_strequ(tmp->str, "##start")
					&& !ft_strequ(tmp->str, "##end"))
				tmp = tmp->next;
		}
		else if (ft_strchr(tmp->str, '-'))
			ft_append_string(&c->tubs, ft_strdup(tmp->str));
		else if (ft_is_only_space(tmp->str))
			break ;
		tmp = tmp->next;
	}
	if (!c->tubs || !c->cells || ft_same_co(c->cells))
	{
		ft_putendl("error");
		ft_node_str_free(&input);
		free(c);
		exit(1);
	}
}

void			ft_process_input(t_string *input, t_data *c)
{
	t_string	*tmp;

	c->fstart = 0;
	c->fend = 0;
	tmp = input;
	c->nb_ants = ft_atoi(tmp->str);
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->str[0] == '#')
			if (!ft_strequ(tmp->str, "##start")
					&& !ft_strequ(tmp->str, "##end"))
				tmp = tmp->next;
		if (!ft_strequ(tmp->str, "##start")
				&& !ft_strequ(tmp->str, "##end"))
			ft_do_map(tmp->str, c);
		c->fstart = (ft_strequ(tmp->str, "##start") ? 1 : 0);
		c->fend = (ft_strequ(tmp->str, "##end") ? 1 : 0);
		if (ft_strchr(tmp->str, '-'))
			break ;
		tmp = tmp->next;
	}
	ft_do_links(input, tmp, c);
}
