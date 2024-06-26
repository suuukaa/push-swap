/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:29 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/06/12 16:17:04 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_bonus.h"

void	error(void)
{
	write(2, "Error\n", 7);
	exit (1);
}

int	ft_strlenn(char *s)
{
	size_t	k;

	k = 0;
	while (s[k])
		k++;
	return (k);
}

void	norm(int i, int j, char **av)
{
	while (av[i][j])
	{
		if (av[i][j] == '-' || av[i][j] == '+')
		{
			if (av[i][j - 1] >= '0' && av[i][j - 1] <= '9')
				error();
			else if (av[i][j + 1] == ' ')
				error();
			else
				j++;
		}
		if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != ' ')
			error();
		j++;
	}
}

void	check(t_data *p, char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '\0')
			error();
		norm(i, j, av);
		i++;
	}
	copy_args(p, av, 0, ac);
}

void	check_spaces(char **av, int ac)
{
	int	i;
	int	j;
	int	k;
	int	cp;

	i = 1;
	if (ac < 2)
		exit(0);
	while (av[i])
	{
		k = ft_strlenn(av[i]);
		j = 0;
		cp = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
				cp++;
			j++;
		}
		if (cp == k)
			error();
		i++;
	}
}
