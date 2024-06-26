/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:23:58 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/06/10 21:20:21 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		itmp;

	if (!(*stack_a))
		return ;
	tmp = *stack_a;
	if (*stack_b == NULL)
	{
		*stack_b = tmp;
		*stack_a = (*stack_a)->next;
		(*stack_b)->next = NULL;
	}
	else
	{
		itmp = (*stack_a)->index;
		*stack_a = (*stack_a)->next;
		ft_lstadd_front(stack_b, tmp);
		(*stack_b)->index = itmp;
	}
	write(1, "pb\n", 3);
}

void	ra(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_back(stack_a, tmp);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b == NULL)
		return ;
	else
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_lstadd_back(stack_b, tmp);
	}
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}

t_list	*ft_lstlast2(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
