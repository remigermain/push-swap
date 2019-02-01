/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/01 18:47:04 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	check_final(t_pusw *lst)
{
	int ret = ft_issort(lst->stack_a, lst->len_a);
	ft_printf("\n\n le tableaux est ");
	if (ret == 1 && lst->len_b == -1)
		ft_printf("%{T_GREEN} [OK]%{T_EOC}");
	else
		ft_printf("%{T_RED} [KO]%{T_EOC}");
	ft_printf("\n");
}

void		ps_algo(t_pusw *lst)
{
	int tmp;

	while (lst->len_a != -1)
	{
//		ps_debugs(lst, 9, 0);
//		usleep(20000);
		tmp = lst->stack_a[lst->len_a];
		rotate_a(lst);
		while (lst->len_b != -1 && lst->stack_b[lst->len_b] < tmp)
			push_a(lst);
		rev_rotate_a(lst);
		push_b(lst);
	}
	while (lst->len_b != -1)
		push_a(lst);
	ft_printf("\n nb = d'instruction = %d\n", lst->instruction);
}

void	ps_algo2(t_pusw *lst)
{
	char	*line;
	int		instruct;

	instruct = 1;
	while (1)
	{
		ps_debugs(lst, 9, 0);
		ft_printf("\n nombre d'instruction = %d\n\33[K", instruct++);
		get_next_line(0, &line);
		if (ft_strcmp(line, "sa") == 0)
			swap_a(lst);
		else if (ft_strcmp(line, "sb") == 0)
			swap_b(lst);
		else if (ft_strcmp(line, "ss") == 0)
			swap_ab(lst);
		else if (ft_strcmp(line, "pa") == 0)
			push_a(lst);
		else if (ft_strcmp(line, "pb") == 0)
			push_b(lst);
		else if (ft_strcmp(line, "ra") == 0)
			rotate_a(lst);
		else if (ft_strcmp(line, "rb") == 0)
			rotate_b(lst);
		else if (ft_strcmp(line, "rr") == 0)
			rotate_ab(lst);
		else if (ft_strcmp(line, "rra") == 0)
			rev_rotate_a(lst);
		else if (ft_strcmp(line, "rrb") == 0)
			rev_rotate_b(lst);
		else if (ft_strcmp(line, "rrr") == 0)
			rev_rotate_ab(lst);
		else if (ft_strcmp(line, "break") == 0 || ft_strcmp(line, "make") == 0)
			break ;
		else
			instruct--;
		free(line);
	}
	check_final(lst);
}
