/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 11:45:38 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_stack(int *stack, int len)
{
	while (len > 0)
	{
		if (stack[len] > stack[len - 1])
			return (-1);
		len--;
	}
	return (1);
}

void		ps_algo(t_pusw *lst)
{
	int tri = 1;
	int instruct = 1;
	
	while (ft_issort(lst) == -1)
	{
		ps_debugs(lst, 9, 0);
		ft_printf("\n nombre d'instruction = %d\n\33[K", instruct++);
		usleep(500);
		if (lst->stack_a[lst->len_a] > lst->stack_a[0])
			rotate_a(lst);
		if (lst->len_b != -1 && lst->stack_b[lst->len_b] > lst->stack_a[lst->len_a])
			push_a(lst);
		if (lst->stack_a[lst->len_a] > lst->stack_a[lst->len_a - 1])
			swap_a(lst);
		else
			push_b(lst);
		if (lst->stack_b[lst->len_b] < lst->stack_b[0])
			rev_rotate_b(lst);
		if (lst->len_a <= tri)
		{
			tri++;
			while (lst->len_b != -1)
			{
				instruct++;
				push_a(lst);
			}
		}
	}
	ps_debugs(lst, 9, 0);
	ft_printf("\n nombre d'instruction = %d\n\33[K", instruct++);	
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
	int ret = ft_issort(lst);
	ft_printf("\n\n le tableaux est ");
	if (ret == 1 && lst->len_b == -1)
		ft_printf("%{t_green} [ok]%{t_eoc}");
	else
		ft_printf("%{t_red} [ko]%{t_eoc}");
	ft_printf("\n");
}
