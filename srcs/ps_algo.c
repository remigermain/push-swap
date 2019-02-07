/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 13:27:31 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static void	visu(t_pusw *lst)
{
	if (lst->visu == 1)
	{
		ps_debugs(lst, 9, 0);
		usleep(lst->time * 10000);
	}
}

static int	sort_stack_b(t_pusw *lst)
{
	int	len;

	len = lst->len_b;
	while (len > 0)
	{
		if (lst->stack_b[len] < lst->stack_b[len - 1])
			return (0);
		len--;
	}
	return (1);
}

static int	sort_stack_a(t_pusw *lst)
{
	int	len;

	len = lst->len_a;
	while (len > 0)
	{
		if (lst->stack_a[len] > lst->stack_a[len - 1])
			return (0);
		len--;
	}
	return (1);
}

static int	find_max(int *stack, int len)
{
	int	min;

	min = -2147483648;
	while (len >= 0)
	{
		if (stack[len] > min)
			min = stack[len];
		len--;
	}
	return (min);
}

static MINT	find_sens(t_pusw *lst, MINT index)
{
	int		count;
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
	count = 0;
	while (count <= len)
	{
		if (stack[count] <= lst->med)
			break ;
		count++;
	}
	count2 = len;
	while (count2 >= 0)
	{
		if (stack[count2] <= lst->med)
			break ;
		count2--;
	}
	if ((len - count2) == count)
	{
		if (stack[count] <= stack[count2])
			return (1);
		return (0);
	}
	else if ((len - count2) > count)
		return (0);
	return (1);
}

static void	split_stack(t_pusw *lst)
{
	MINT	sens;

	sens = find_sens(lst, 1);
	while (lst->len_b < lst->len_a)
	{
		visu(lst);
		if (lst->stack_a[lst->len_a] <= lst->med)
		{
			push_b(lst);
			sens = find_sens(lst, 1);
		}
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
	int	sens_a;
	int	sens_b;

	pivot = 0;
	if (!ft_issort(lst))
	{
		if (lst->len_a > 4)
			split_stack(lst);
		visu(lst);
		while (!ft_issort(lst))
		{
			visu(lst);
			sens_a = find_sens(lst, 1);
			sens_b = (find_sens(lst, 2) == 1 ? 0 : 1);
			if (sort_stack_a(lst))
				pivot = lst->len_a;
			if (((lst->len_a > 0 && lst->stack_a[lst->len_a - 1] < lst->stack_a[lst->len_a]) &&
				(lst->len_b > 0 && lst->stack_b[lst->len_b - 1] > lst->stack_b[lst->len_b])) &&
					!sort_stack_a(lst) && !sort_stack_b(lst))
				swap_ab(lst);
			else if ((lst->len_a > 0 && lst->stack_a[lst->len_a - 1] < lst->stack_a[lst->len_a])
					&& !sort_stack_a(lst))
				swap_a(lst);
			else if ((lst->len_b > 0 && lst->stack_b[lst->len_b - 1] > lst->stack_b[lst->len_b])
					&& !sort_stack_b(lst))
				swap_b(lst);
			else if (((lst->len_a > 0 && lst->stack_a[0] < lst->stack_a[lst->len_a]) &&
				(lst->len_b > 0 && lst->stack_b[0] > lst->stack_b[lst->len_b])) &&
					!sort_stack_a(lst) && !sort_stack_b(lst))
				rotate_ab(lst);
			else if ((lst->len_a > 0 && lst->stack_a[0] < lst->stack_a[lst->len_a])
					&& !sort_stack_a(lst))
				rotate_a(lst);
			else if ((lst->len_b > 0 && lst->stack_b[0] > lst->stack_b[lst->len_b])
					&& !sort_stack_b(lst))
				rotate_b(lst);
			else if (((lst->len_a > 0 && lst->stack_a[0] > lst->stack_a[lst->len_a]) &&
				(lst->len_b > 0 && lst->stack_b[0] < lst->stack_b[lst->len_b])) &&
					!sort_stack_a(lst) && !sort_stack_b(lst))
				rev_rotate_ab(lst);
			else if ((lst->len_a > 0 && lst->stack_a[0] > lst->stack_a[lst->len_a])
					&& !sort_stack_a(lst))
				rev_rotate_a(lst);
			else if ((lst->len_b > 0 && lst->stack_b[0] < lst->stack_b[lst->len_b])
					&& !sort_stack_b(lst))
				rev_rotate_b(lst);
			else if (sort_stack_a(lst) && lst->stack_b[lst->len_b] == find_max(lst->stack_b, lst->len_b))
				push_a(lst);
		//	if (sort_stack_a(lst) && sort_stack_b(lst))
		//		pivot = ps_algo2(lst, pivot);
	
			//pivot = ps_algo2(lst, pivot);
		}
	}
	visu(lst);
}
