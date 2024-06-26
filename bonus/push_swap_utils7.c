/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:22:54 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/06/12 20:29:36 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_bonus.h"

void	rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*second_last;

	second_last = ft_lstlast2(*stack_a);
	if (!second_last)
		return ;
	last = second_last->next;
	second_last->next = NULL;
	ft_lstadd_front(stack_a, last);
}

void	rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*second_last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	second_last = ft_lstlast2(*stack_b);
	if (!second_last)
		return ;
	last = second_last->next;
	second_last->next = NULL;
	ft_lstadd_front(stack_b, last);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_arr(t_data *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->e)
	{
		j = i + 1;
		while (j < p->e)
		{
			if (p->arr[i] > p->arr[j])
				swap(&p->arr[i], &p->arr[j]);
			j++;
		}
		i++;
	}
}
