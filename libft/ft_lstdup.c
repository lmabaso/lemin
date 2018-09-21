/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:21:05 by lmabaso           #+#    #+#             */
/*   Updated: 2018/09/05 11:40:04 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstdup(t_list *head)
{
	t_list *tmp;

	tmp = NULL;
	while (head)
	{
		ft_lstadd(&tmp, ft_lstnew(head->content, head->content_size));
		head = head->next;
	}
	return (tmp);
}
