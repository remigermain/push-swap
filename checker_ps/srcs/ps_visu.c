/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_visu.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 14:41:45 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 17:11:34 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

static int	pos_tab(t_puswc *lst, int i, char index)
{
	int	j;

	j = 0;
	while (index == 1 && lst->tri[j] != lst->stack_a[i] &&
			j <= (lst->len_b + lst->len_a + 2))
		j++;
	while (index == 2 && lst->tri[j] != lst->stack_b[i] &&
			j <= (lst->len_b + lst->len_a + 2))
		j++;
	return (j);
}

static void	print_stackb(t_puswc *lst)
{
	int	i;
	int	pos;

	i = 0;
	while (i < lst->len_b)
	{
		pos = pos_tab(lst, i, 2) + 11;
		ft_printf("\033[44m", pos % 7);
		ft_printf("%{T_LGREY}%*d%{B_EOC}", pos, lst->stack_b[i++]);
		ft_printf("%*c\n", pos + 2, ' ');
	}
}

static void	print_stacka(t_puswc *lst)
{
	int	i;
	int	pos;

	i = lst->len_a;
	while (i >= 0)
	{
		pos = pos_tab(lst, i, 1) + 11;
		ft_printf("\033[48;5;%dm", pos);
		ft_printf("%{T_LGREY}%*d%{B_EOC}  ", pos, lst->stack_a[i--]);
		ft_printf("%*c\n", pos + 2, ' ');
	}
}

void		ps_visu(t_puswc *lst)
{
	int	len;
	int	id;

	if (lst->visu == 1)
	{
		len = lst->len_a + lst->len_b + 2;
		ft_printf("%*c\n", len + 13, ' ');
		ft_printf("[STACK_B]%*c\n", len + 13, ' ');
		print_stackb(lst);
		ft_printf("%*c\n", len + 13, ' ');
		ft_printf("[STACK_A]%*c\n", len + 13, ' ');
		print_stacka(lst);
		ft_printf("%*c\n", len + 13, ' ');
		len += 4;
		usleep(lst->time * 10000);
		if (!ft_issort(lst))
			ft_printf("\033[K\033[%dA", len);
	}
}
