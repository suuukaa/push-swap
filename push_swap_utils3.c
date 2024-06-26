/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:42:00 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/06/13 11:23:27 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

void	copy_args(t_data *p, char **av, int a, int ac)
{
	int		len;
	int		i;
	int		j;
	char	*copy;

	check_spaces(av, ac);
	i = 0;
	len = len_args(av);
	copy = malloc(sizeof(char *) * len + 1);
	if (!copy)
		error();
	while (av[++i])
	{
		j = -1;
		copy[a++] = ' ';
		while (av[i][++j])
		{
			copy[a] = av[i][j];
			a++;
		}
	}
	copy[a] = '\0';
	p->res = ft_split(copy, ' ');
	free(copy);
	check_number(p);
}

void	check_number(t_data *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->res[i])
	{
		j = i + 1;
		while (p->res[j])
		{
			if (ft_atoi(p->res[i]) - ft_atoi(p->res[j]) == 0)
				error();
			j++;
		}
		i++;
	}
	str_to_int(p);
}

int	len_res(t_data *p)
{
	int	i;
	int	j;

	i = 0;
	p->e = 0;
	while (p->res[i])
	{
		j = 0;
		while (p->res[i][j])
		{
			j++;
		}
		p->e++;
		i++;
	}
	return (p->e);
}

void	str_to_int(t_data *p)
{
	int	i;
	int	f;
	int	len;

	i = 0;
	f = 0;
	len = len_res(p);
	p->arr = malloc(sizeof(int) * (len + 1));
	if (!p->arr)
		error();
	while (p->res[i])
	{
		p->arr[f] = ft_atoi(p->res[i]);
		f++;
		i++;
	}
	p->arr[f] = 0;
	i = 0;
	while (p->res[i])
		free(p->res[i++]);
	free(p->res);
}
