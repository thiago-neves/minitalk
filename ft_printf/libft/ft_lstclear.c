/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:37:09 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:37:10 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;

	if (!del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		prev = *lst;
		*lst = prev->next;
		free(prev);
	}
	*lst = NULL;
}
