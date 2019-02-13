/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 18:18:54 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int	find_med(int *stack, int len)
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

int	find_nb(int *stack, int len, int nb)
{
	while (len >= 0)
	{
		if (stack[len] == nb)
			return (len);
		len--;
	}
	return (0);
}

int	find_sens(t_pusw *lst, int max)
{
	int pos;

	pos = find_nb(lst->stack_b, lst->len_b, max);
	if (pos > (lst->len_b / 2))
		return (1);
	return (0);
}

int	find_midsens(t_pusw *lst)
{
	int count;
	int count2;

	count = 0;
	count2 = lst->len_a;
	while (count <= lst->len_a && lst->stack_a[count] > lst->pivot)
		count++;
	while (count2 >= 0 && lst->stack_a[count2] > lst->pivot)
		count2--;
	if ((lst->len_a - count2) == (count + 1))
	{
		if (lst->stack_a[count] < lst->stack_a[count2])
			return (1);
		return (0);
	}
	else if ((lst->len_a - count2) > (count + 1))
		return (0);
	return (1);
}
