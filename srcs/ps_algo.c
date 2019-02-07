/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 17:17:13 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static void	visu(t_pusw *lst)
{
	if (lst->visu == 1)
	{
		ps_debugs(lst, 9, 0);
		usleep(lst->time * 1000);
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

static int	find_min(int *stack, int len)
{
	int	min;

	min = 2147483647;
	while (len >= 0)
	{
		if (stack[len] < min)
			min = stack[len];
		len--;
	}
	return (min);
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

static int	find_next_min(int *stack, int len, int tmp)
{
	int	min;

	min = 2147483647;
	while (len >= 0)
	{
		if (stack[len] < min && stack[len] > tmp)
			min = stack[len];
		len--;
	}
	return (min);
}

static int	find_next_max(int *stack, int len, int tmp)
{
	int	min;

	min = -2147483648;
	while (len >= 0)
	{
		if (stack[len] > min && stack[len] < tmp)
			min = stack[len];
		len--;
	}
	return (min);
}


static int	find_med(int *stack, int len)
{
	int		count;
	int		min;
	int		max;

	count = -1;
	max = find_max(stack, len);
	min = find_min(stack, len);
	while ((len / 2) > ++count)
	{
		max = find_next_max(stack, len, max);
		min = find_next_min(stack, len, min);
	}
	return (min);
}

static int	find_nb(int *stack, int len, int nb)
{
	while (len >= 0)
	{
		if (stack[len] == nb)
			return (len);
		len--;
	}
	return (0);
}

static int	sort_realstack_a(t_pusw *lst)
{
	if ((find_min(lst->stack_a, lst->len_a) > find_max(lst->stack_b, lst->len_b)) && sort_stack_a(lst))
		return (1);
	return (0);
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
		else if (sens == 1 && (lst->stack_b > 0 && lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1]))
			rotate_ab(lst);
		else if (sens == 0 && lst->stack_b > 0 && lst->stack_b[lst->len_b] < lst->stack_b[0])
			rev_rotate_ab(lst);
		else if (sens == 1)
			rotate_a(lst);
		else
			rev_rotate_a(lst);
	}
}

void		ps_algo(t_pusw *lst)
{
	int pivot;
	int	sens;
	int	max;

	pivot = 0;
	if (!ft_issort(lst))
	{
		split_stack(lst);
		visu(lst);
		lst->med = find_med(lst->stack_a, lst->len_a);
		sens = find_sens(lst, 1);
		while (!sort_realstack_a(lst))
		{
			visu(lst);
			if (lst->len_a > 0 && lst->stack_a[lst->len_a] > lst->stack_a[lst->len_a - 1] &&
					lst->len_b > 0 && lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1])
				swap_ab(lst);
			else if (lst->len_a > 0 && lst->stack_a[lst->len_a] > lst->stack_a[lst->len_a - 1])
				swap_a(lst);
			else if (lst->len_b > 0 && lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1])
				swap_b(lst);
			else if (lst->stack_a[lst->len_a] <= lst->med)
			{
				push_b(lst);
				lst->med = find_med(lst->stack_a, lst->len_a);
				sens = find_sens(lst, 1);
			}
			else if (sens == 1 && (lst->stack_b > 0 && lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1]))
				rotate_ab(lst);
			else if (sens == 0 && lst->stack_b > 0 && lst->stack_b[lst->len_b] < lst->stack_b[0])
				rev_rotate_ab(lst);
			else if (sens == 1)
				rotate_a(lst);
			else
				rev_rotate_a(lst);
		}
		visu(lst);


		max = find_max(lst->stack_b, lst->len_b);
		if ((sens = find_nb(lst->stack_b, lst->len_b, max)) > (lst->len_b / 2))
			sens = 1;
		else
			sens = 0;
		while (!ft_issort(lst))
		{
			visu(lst);
			if (lst->stack_b[lst->len_b] == max || lst->len_b == 0)
			{
				push_a(lst);
				max = find_max(lst->stack_b, lst->len_b);
				if ((sens = find_nb(lst->stack_b, lst->len_b, max)) > (lst->len_b / 2))
					sens = 1;
				else
					sens = 0;
			}
			else if (sens == 1)
				rotate_b(lst);
			else
				rev_rotate_b(lst);
		}
	}
	visu(lst);
}
