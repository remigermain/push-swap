/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo_find3.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 19:12:21 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 18:31:55 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	find_mid_med(t_pusw *lst)
{
	int	val;
	int	min;
	int	i;

	val = 8;
	if (val > (lst->len_a / (val / 2)))
		val = 2;
	min = find_min(lst->stack_a, lst->len_a);
	i = 0;
	while (++i < ((lst->len_a / val) + (lst->len_a % val)))
		min = find_next_min(lst->stack_a, lst->len_a, min);
	lst->pivot = min;
}

int		find_sens2(t_pusw *lst)
{
	int pos;
	int pos2;
	int t_pos;
	int t_pos2;

	pos = find_sens(lst, lst->max);
	pos2 = find_sens(lst, lst->max_n);
	pos = find_nb(lst->stack_b, lst->len_b, lst->max);
	pos2 = find_nb(lst->stack_b, lst->len_b, lst->max_n);
	t_pos = pos;
	t_pos2 = pos2;
	if (pos > (lst->len_b / 2))
		t_pos = lst->len_b - pos;
	else
		t_pos++;
	if (pos2 > (lst->len_b / 2))
		t_pos2 = lst->len_b - pos2;
	else
		t_pos2++;
	if (t_pos < t_pos2)
	{
		if (pos > (lst->len_b / 2))
			return (1);
		return (0);
	}
	if (pos2 > (lst->len_b / 2))
		return (1);
	return (0);
}
