/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_ptr_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:40:26 by lmabaso           #+#    #+#             */
/*   Updated: 2018/09/05 11:42:11 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_double_ptr_len(void **str)
{
	size_t count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
