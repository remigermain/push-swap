/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_debug.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:19:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 09:50:30 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_debugs2(t_pusw *lst, int count)
{
	while (--count >= 0)
	{
		ft_printf("%13d ", count);
		if (count <= lst->len_a)
			ft_printf("|%{T_LGREY}%13d%{T_EOC}|       ", lst->stack_a[count]);
		else
			ft_printf("|%13c|       ", ' ');
		if (count <= lst->len_b)
			ft_printf("|%{T_LGREY}%12d%{T_EOC}|", lst->stack_b[count]);
		else
			ft_printf("|%12c|", ' ');
		ft_printf("\n");
	}
	ft_printf("\n%{T_LGREY}[	nombre d'instruction = %{T_EOC}");
	ft_printf("%12d", lst->instruction);
	ft_printf("%{T_LGREY}         ]%{T_EOC}\n");
}

static void	ps_debugs(t_pusw *lst, int nb, int index)
{
	int count;

	count = 0;
	if (index == 1)
		ft_printf("\33[K\33[%dA", MAX(lst->len_a, lst->len_b) + 1 + nb);
	ft_printf("\n\33%{T_LGREY}------------------------------ Debug");
	ft_printf(" ---------------%{T_EOC}\n\n");
	if (lst->len_a > lst->len_b)
		count = lst->len_a;
	else
		count = lst->len_b;
	count++;
	ft_printf("%15c%{T_BLUE}[   stack_a   ]%{T_YELLOW}     ", ' ');
	ft_printf(" [   stack_b  ]%{T_EOC}\n");
	ft_printf("%15c%{T_BLUE}[%13d]%{T_YELLOW}     ", ' ', lst->len_a);
	ft_printf(" [%12d]%{T_EOC}\n\n", lst->len_b);
	ps_debugs2(lst, count);
}

void		ps_visu(t_pusw *lst)
{
	if (lst->visu == 1)
	{
		ps_debugs(lst, 9, 0);
		usleep(lst->time * 10000);
	}
}
