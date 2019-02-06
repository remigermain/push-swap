/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 16:43:38 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static void	visu(t_pusw *lst)
{
	if (lst->visu == 1)
	{
		ps_debugs(lst, 9, 0);
		usleep(100000);
	}
}

static int	sort_stack(int *stack, int len)
{
	while (len > 0)
	{
		if (stack[len] > stack[len - 1])
			return (0);
		len--;
	}
	return (1);
}

static MINT	find_sens(t_pusw *lst, MINT index)
{
	size_t	count;
	int		count2;
	int		*stack;
	int		len;

	if (index == 1)
		stack = lst->stack_a;
	else
		stack = lst->stack_b;
	if (index == 1)
		len = lst->len_a;
	else
		len = lst->len_b;
	while (count <= len)
	{
		if (stack[count] <= lst->med)
			break ;
		count++;
	}
	count2 = len;
	while (count2 >= 0)
	{
		if (stack[len] <= lst->med)
			break ;
		len++;
	}
	len -= count2;
	if (len > count)
		return (1);
	return (0);
}

static void	split_stack(t_pusw *lst)
{
	MINT	sens;

	sens = find_sens(lst, 1);
	while (lst->len_b < lst->len_a)
	{
		if (lst->stack_a[lst->len_a] <= lst->med)
		{
			push_b(lst);
			sens = find_sens(lst, 1);
		}
		else if (sens == 1 && lst->len_b > 0 && (
					lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1] ||
					lst->stack_b[lst->len_b] > lst->stack_b[0]))
			rotate_ab(lst);
		else if (sens == 1 && lst->len_b > 0  && (
					lst->stack_b[lst->len_b] > lst->stack_b[lst->len_b - 1] ||
					lst->stack_b[lst->len_b] < lst->stack_b[0]))
			rev_rotate_ab(lst);
		else if (sens == 1)
			rotate_a(lst);
		else
			rev_rotate_a(lst);
	}
}

static int	ps_algo2(t_pusw *lst, int pivot)
{
	if (lst->len_a <= pivot)
	{
		pivot++;
		while (lst->len_b != -1)
		{
			push_a(lst);
		}
	}
	return (pivot);
}

void		ps_algo(t_pusw *lst)
{
	int pivot;

	pivot = 0;
	if (!ft_issort(lst))
	{
		if (lst->len_a > 4)
			split_stack(lst);
		while (!ft_issort(lst))
		{
			visu(lst);
			pivot = 0;
			while (!sort_stack(lst->stack_a, lst->len_a - pivot))
				pivot++;
			pivot = lst->len_a - pivot;
			if (lst->stack_a[lst->len_a] > lst->stack_a[0])
				rotate_a(lst);
			if (lst->stack_a[lst->len_a] > lst->stack_a[lst->len_a - 1])
				swap_a(lst);
			else if (lst->len_b != -1 &&
					lst->stack_b[lst->len_b] > lst->stack_a[lst->len_a])
				push_a(lst);
			else if (!sort_stack(lst->stack_a, lst->len_a))
				push_b(lst);
			else if (lst->stack_b[lst->len_b] < lst->stack_b[0])
				rev_rotate_b(lst);
			pivot = ps_algo2(lst, pivot);
		}
	}
	visu(lst);
}
