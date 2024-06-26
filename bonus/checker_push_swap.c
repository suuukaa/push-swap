/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:32:43 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/06/12 20:30:28 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_bonus.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str2[i] == str1[i])
		i++;
	return (str1[i] - str2[i]);
}

void	copy_insta(t_list **stack_a, t_list **stack_b, char *read)
{
	if (!ft_strcmp(read, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(read, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(read, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(read, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(read, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(read, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(read, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(read, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(read, "rrr\n"))
		rrr(stack_a, stack_b);
	else if (!ft_strcmp(read, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(read, "rr\n"))
		rr(stack_a, stack_b);
	else
		error();
}

char	*check_sort(t_list **stack_a, t_list **stack_b)
{
	char	*read;

	read = get_next_line(0);
	while (read)
	{
		copy_insta(stack_a, stack_b, read);
		free(read);
		read = get_next_line(0);
	}
	return (read);
}
