/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:01:12 by lmabaso           #+#    #+#             */
/*   Updated: 2018/09/05 09:03:13 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			ft_show_input(t_string *input)
{
	t_string	*tmp;

	tmp = input;
	while (tmp)
	{
		ft_putendl(tmp->str);
		tmp = tmp->next;
	}
	ft_putendl("\n");
}
