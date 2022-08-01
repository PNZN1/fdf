/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 17:36:08 by pniezen       #+#    #+#                 */
/*   Updated: 2022/04/15 15:51:37 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

#include <stdlib.h>

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
