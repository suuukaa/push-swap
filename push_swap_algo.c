/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:50:08 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/06/12 17:02:31 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

void	sort_3_2_nbr(t_list **stack, t_data *p)
{
	t_list	*t;
	t_list	*t2;

	if (!check_list_sort(*stack, p))
		return ;
	if (p->e == 2)
		sa(stack);
	else
	{
		t = (*stack)->next;
		t2 = (*stack)->next->next;
		if ((*stack)->content > t->content && (*stack)->content < t2->content)
			sa(stack);
		else if ((*stack)->content > t->content && t->content > t2->content)
		{
			sa(stack);
			rra(stack);
		}
		else if (t->content < t2->content && t2->content < (*stack)->content)
			ra(stack);
		else if ((*stack)->content < t2->content && t2->content < t->content)
			do_sa_ra(stack);
		else
			rra(stack);
	}
}

void	sort4_nbr(t_list **stack_a, t_list **stack_b, t_data *p)
{
	int		index;

	while (1)
	{
		if (ft_lstsize(*stack_a) == 3)
		{
			sort_3_2_nbr(stack_a, p);
			pa(stack_a, stack_b);
			return ;
		}
		else
		{
			while (1)
			{
				index = get_position(*stack_a, 0);
				if (index == (*stack_a)->index)
				{
					pb(stack_a, stack_b);
					break ;
				}
				else
					ra(stack_a);
			}
		}
	}
}

void	sort5_nbr(t_list **stack_a, t_list **stack_b, t_data *p, int index)
{
	while (1)
	{
		if (ft_lstsize(*stack_a) == 4)
		{
			sort4_nbr(stack_a, stack_b, p);
			if (ft_lstsize(*stack_b) == 1)
				pa(stack_a, stack_b);
			return ;
		}
		else
		{
			sort_5(stack_a, stack_b, index);
		}
	}
}

void	sort_5(t_list **stack_a, t_list **stack_b, int ind)
{
	int	pos;

	while (1)
	{
		ind = get_position(*stack_a, 0);
		pos = get_pos(stack_a, 1);
		if (ind == (*stack_a)->index)
		{
			pb(stack_a, stack_b);
			break ;
		}
		else if (pos > 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
}

int	get_pos(t_list **stack, int ind)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == ind)
			return (i + 1);
		i++;
		tmp = tmp->next;
	}
	return (i);
}
