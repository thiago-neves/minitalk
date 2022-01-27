/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:38:27 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:38:28 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cont;

	cont = 1;
	if (lst == 0)
		return (--cont);
	while (lst->next != 0)
	{
		lst = lst->next;
		cont++;
	}
	return (cont);
}
