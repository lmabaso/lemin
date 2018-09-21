/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:12:43 by lmabaso           #+#    #+#             */
/*   Updated: 2018/09/04 13:25:37 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				ft_cont_check(t_string *tmp, t_string **input)
{
	int			pipes;

	pipes = 0;
	while (tmp)
	{
		if (ft_err_room(tmp) == 1)
			return (1);
		if (ft_strchr(tmp->str, '-') && ++pipes)
			break ;
		tmp = tmp->next;
	}
	if (!pipes)
		return (1);
	while (tmp)
	{
		if (ft_err_pipes(tmp, input) == 1)
			return (1);
		if (ft_is_only_space(tmp->str))
			if (ft_is_not_eof(tmp) == 1)
				return (1);
		tmp = tmp->next;
	}
	return (0);
}
