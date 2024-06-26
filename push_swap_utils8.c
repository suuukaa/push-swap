/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils8.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:09:49 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/06/10 21:07:09 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int	check_list_sort(t_list *stack_a, t_data *p)
{
	int	j;

	j = p->e;
	if (!stack_a || !stack_a->next)
		return (0);
	while (j >= 0)
	{
		if (stack_a->content > stack_a->next->content)
			return (1);
		stack_a = stack_a->next;
		j--;
		if (stack_a->next == NULL)
			return (0);
	}
	return (0);
}

int	get_position(t_list *stack_a, bool in)
{
	t_list	*tmp;
	int		min;
	int		max;

	max = stack_a->index;
	min = stack_a->index;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	if (in)
		return (max);
	return (min);
}

void	number_index(t_list *stack, t_data *p)
{
	t_list	*tmp;
	int		i;

	sort_arr(p);
	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i <= ft_lstsize(stack))
		{
			if (p->arr[i] == tmp->content)
			{
				tmp->index = i + 1;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	else
	{
		while (lst)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}
