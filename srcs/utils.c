/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 10:28:48 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 11:14:37 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_issort(t_pusw *lst)
{
	int count;

	count = lst->len_a;
	if (lst->len_b != -1)
		return (0);
	while (count > 0)
	{
		if (!(lst->stack_a[count] < lst->stack_a[count - 1]))
			return (0);
		count--;
	}
	return (1);
}

int		sort_stack_a(t_pusw *lst)
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

int		sort_realstack_a(t_pusw *lst)
{
	if ((find_min(lst->stack_a, lst->len_a) >
				find_max(lst->stack_b, lst->len_b)) && sort_stack_a(lst))
		return (1);
	return (0);
}

void	ps_free(t_pusw *lst)
{
	if (lst != NULL)
	{
		if (lst->stack_a != NULL)
			ft_memdel((void**)&(lst->stack_a));
		if (lst->stack_b != NULL)
			ft_memdel((void**)&(lst->stack_b));
		ft_memdel((void**)&(lst));
	}
}

void	ps_error(t_pusw *lst)
{
	ps_free(lst);
	ft_printf("%1@", "error", "push_swapp", strerror(errno));
}
