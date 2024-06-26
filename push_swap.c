/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:41:14 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/06/13 11:22:49 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

t_list	*get_content(t_list *stack_b, bool in)
{
	t_list		*min;
	t_list		*max;

	max = stack_b;
	min = stack_b;
	while (stack_b)
	{
		if (stack_b->content > max->content)
			max = stack_b;
		if (stack_b->content < min->content)
			min = stack_b;
		stack_b = stack_b->next;
	}
	if (in)
		return (max);
	return (min);
}

int	len_args(char **av)
{
	int	i;
	int	j;
	int	h;

	i = 1;
	j = 0;
	h = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			h++;
			j++;
		}
		i++;
	}
	return (h);
}

void	do_sa_ra(t_list **stack)
{
	sa(stack);
	ra(stack);
}

void	size_stack(t_list **stack_a, t_list **stack_b, t_data *p)
{
	if (ft_lstsize(*stack_a) <= 3)
		sort_3_2_nbr(stack_a, p);
	else if (ft_lstsize(*stack_a) == 4)
		sort4_nbr(stack_a, stack_b, p);
	else if (ft_lstsize(*stack_a) == 5)
		sort5_nbr(stack_a, stack_b, p, 0);
	else if (ft_lstsize(*stack_a) < 250)
	{
		sort_push_swap(stack_a, stack_b, 15);
	}
	else
		sort_push_swap(stack_a, stack_b, 42);
}

int	main(int ac, char **av)
{
	t_data	p;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	check(&p, av, ac);
	stack_a = arr_to_list(&p);
	number_index(stack_a, &p);
	if (!check_list_sort(stack_a, &p))
		exit(0);
	size_stack(&stack_a, &stack_b, &p);
	free(p.arr);
	exit(0);
}
