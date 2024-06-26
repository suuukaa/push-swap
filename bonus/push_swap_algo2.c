/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:30:45 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/06/12 17:14:20 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_bonus.h"

void	sort(t_list **stack_b, t_list **stack_a, int i)
{
	t_data	p;

	while (*stack_b)
	{
		p.max = get_pos(stack_b, ft_lstsize(*stack_b));
		p.b_max = get_pos(stack_b, ft_lstsize(*stack_b) - 1);
		p.maxins = p.max;
		p.b_maxins = p.b_max;
		if (ft_lstsize(*stack_b) == 1)
		{
			pa(stack_a, stack_b);
			break ;
		}
		if (p.max > i)
			p.maxins = ft_lstsize(*stack_b) - p.max + 2;
		if (p.b_max > i)
			p.b_maxins = ft_lstsize(*stack_b) - p.b_max + 2;
		if (p.b_maxins > p.maxins)
			push_element(stack_b, stack_a, p.max);
		else
			norm_sort(&p, stack_a, stack_b);
	}
}

void	norm_sort(t_data *p, t_list **stack_a, t_list **stack_b)
{
	push_element(stack_b, stack_a, p->b_max);
	p->max = get_pos(stack_b, ft_lstsize(*stack_b) + 1);
	push_element(stack_b, stack_a, p->max);
	sa(stack_a);
}

void	sort_push_swap(t_list **stack_a, t_list **stack_b, int q)
{
	int		k;

	k = 0;
	while (1)
	{
		if ((*stack_a)->index < k)
		{
			pb (stack_a, stack_b);
			k++;
		}
		else if ((*stack_a)->index <= q + k)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			k++;
		}
		else
			ra(stack_a);
		if (!(*stack_a))
			break ;
	}
	sort(stack_b, stack_a, ft_lstsize(*stack_b) / 2);
}

void	push_element(t_list **stack_b, t_list **stack_a, int pos)
{
	int		i;
	int		j;
	int		len;
	t_list	*tmp;

	tmp = *stack_b;
	j = -1;
	i = ft_lstsize(*stack_b) / 2;
	if (i < pos)
	{
		len = ft_lstsize(*stack_b) - pos;
		while (++j <= len)
			rrb(stack_b);
		pa(stack_a, stack_b);
	}
	else
	{
		while (++j < pos - 1)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
}
