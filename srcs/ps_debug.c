/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_debug.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:19:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/01 15:00:52 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_debugs(t_pusw *lst, int nb, int index)
{
	int count;

	count = 0;
	if (lst->len_a > lst->len_b)
		count = lst->len_a;
	else
		count = lst->len_b;
	count++;
	ft_printf("%15c%{T_BLUE}[   stack_a   ]%{T_YELLOW}      [   stack_b  ]%{T_EOC}\n", ft_intlen(count), lst->len_b);
	ft_printf("%15c%{T_BLUE}[%13d]%{T_YELLOW}      [%12d]%{T_EOC}\n\n", ft_intlen(count), lst->len_a, lst->len_b);
	while (--count >= 0)
	{
		ft_printf("%13d ", count);
		if (count <= lst->len_a)
			ft_printf("|%{T_LGREY}%12d%{T_EOC}|       ", lst->stack_a[count]);
		else
			ft_printf("|%13c|      ", ' ');
		if (count <= lst->len_b)
			ft_printf("|%{T_LGREY}%12d%{T_EOC}|", lst->stack_b[count]);
		else
			ft_printf("|%12c|", ' ');
		ft_printf("\n");
	}
	if (index == 1)
		ft_printf("\33[K\33[%dA", MAX(lst->len_a, lst->len_b) + 1 + nb);
}

void	ps_debug(t_pusw *lst)
{
	int count;

	count = -1;
	ft_printf("\n%{T_LGREY}------------------------------ Debug ---------------%{T_EOC}\n\n");
	if (lst->stack_a != NULL)
	{
		count = MAX(lst->len_a, lst->len_b);
		ft_printf("%15c%{T_BLUE}[   stack_a   ]%{T_YELLOW}      [   stack_b  ]%{T_EOC}\n\n", ft_intlen(count), lst->len_b);
		while (--count >= 0)
		{
			ft_printf("%13d |%{T_LGREY}%13d%{T_EOC}|      ", count, lst->stack_a[count]);
			if (count < lst->len_b)
				ft_printf("|%{T_LGREY}%12d%{T_EOC}|", lst->stack_b[count]);
			else
				ft_printf("|%12c|", ' ');
			ft_printf("\n");
		}
	}
	ft_printf("\n\n max = %{T_LGREY}%12d%{T_EOC}  %C\n min = %{T_LGREY}%12d%{T_EOC}  %C\n\n", lst->max, 0x2B06, lst->min, 0x2B07);
	ft_printf("\n%{T_LGREY}-----------------------------------------------------%{T_EOC}\n\n");
}
