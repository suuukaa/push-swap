/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:42:19 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/06/12 19:54:15 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_H
# define LIB_PUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	char	**res;
	int		index;
	int		*arr;
	int		e;
	void	*p;
	int		max;
	int		b_max;
	int		maxins;
	int		b_maxins;
}	t_data;

// inst
void	sa(t_list **stack);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list**stack_b);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
// linked list
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*arr_to_list(t_data *p);
t_list	*ft_lstlast2(t_list *lst);
int		ft_lstsize(t_list *lst);
// functions
void	error(void);
void	check(t_data *p, char **av, int ac);
void	check_spaces(char **av, int ac);
char	**ft_split(char *s, char c);
void	copy_args(t_data *p, char **av, int a, int ac);
int		len_args(char **av);
int		ft_strlen(char *s);
void	check_number(t_data *p);
int		len_res(t_data *p);
void	str_to_int(t_data *p);
int		ft_atoi(char *str);
void	sort_arr(t_data *p);
void	swap(int *a, int *b);
void	number_index(t_list *stack, t_data *p);
int		check_list_sort(t_list *stack_a, t_data *p);
int		get_position(t_list *stack_a, bool in);
void	sort_3_2_nbr(t_list **stack_a, t_data *p);
void	sort4_nbr(t_list **stack_a, t_list **stack_b, t_data *p);
void	sort5_nbr(t_list **stack_a, t_list **stack_b, t_data *p, int index);
void	do_sa_ra(t_list **stack);
void	norm(int i, int j, char **av);
void	sort_push_swap(t_list **stack_a, t_list **stack_b, int q);
t_list	*get_content(t_list *stack_a, bool in);
void	sort(t_list **stack_b, t_list **stack_a, int i);
void	push_element(t_list **stack_b, t_list **stack_a, int pos);
int		get_pos(t_list **stack, int ind);
void	size_stack(t_list **stack_a, t_list **stack_b, t_data *p);
void	sort_5(t_list **stack_a, t_list **stack_b, int ind);
void	norm_sort(t_data *p, t_list **stack_a, t_list **stack_b);

#endif