/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:32:52 by falves-e          #+#    #+#             */
/*   Updated: 2026/04/27 16:15:45 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		last = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(last, del);
	}
}
