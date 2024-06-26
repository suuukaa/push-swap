/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:44:48 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/06/13 11:24:00 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int	ft_atoi(char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res * sign > 2147483647 || res * sign < -2147483648)
			error();
		i++;
	}
	return (res * sign);
}

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc (sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	else
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
		ft_lstlast(*lst)->next = new;
	new->next = NULL;
}

t_list	*arr_to_list(t_data *p)
{
	t_list	*lst;
	t_list	*new ;
	int		i;
	int		j;

	i = 1;
	j = p->e;
	new = NULL;
	lst = ft_lstnew(p->arr[0]);
	while (j > 1)
	{
		new = ft_lstnew(p->arr[i]);
		ft_lstadd_back(&lst, new);
		i++;
		j--;
	}
	return (lst);
}
