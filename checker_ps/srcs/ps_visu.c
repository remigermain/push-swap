/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_visu.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 14:41:45 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 10:51:43 by rgermain    ###    #+. /#+    ###.fr     */
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
	return ((lst->len_b + lst->len_a + 2) - j);
}

static void	print_stackb(t_puswc *lst, int plus, int max)
{
	int	ret;
	int	i;
	int	pos;

	i = 0;
	while (i <= lst->len_b)
	{
		pos = pos_tab(lst, i, 2) + 11;
		ft_printf("|  \033[48;5;%dm", pos % 7);
		ret = ft_printf("%{T_BLACK}%*d", plus + (pos / 2),
				lst->stack_b[i++]) - 5;
		ret += ft_printf("%*c%{B_EOC}", pos - ret + plus, ' ') - 4;
		ft_printf("%*c|\n", max - ret, ' ');
	}
}

static void	print_stacka(t_puswc *lst, int plus, int max)
{
	int ret;
	int	i;
	int	pos;

	i = lst->len_a;
	while (i >= 0)
	{
		pos = pos_tab(lst, i, 1) + 11;
		ft_printf("|  \033[48;5;%dm", pos);
		ret = ft_printf("%{T_BLACK}%*d", plus + (pos / 2),
				lst->stack_a[i--]) - 5;
		ret += ft_printf("%*c%{B_EOC}", pos - ret + plus, ' ') - 4;
		ft_printf("%*c|\n", max - ret, ' ');
	}
}

void		ps_visu(t_puswc *lst, int j)
{
	int	max;
	int	plus;
	int	len;

	if (lst->visu == 1)
	{
		len = lst->len_a + lst->len_b + 2;
		plus = MAX(ft_intlen(lst->tri[0]),
				ft_intlen(lst->tri[len - 1])) + 2;
		max = (plus * 4) + len;
		ft_printf("|%*@|\n", max + 3, "char", '-');
		ft_printf("|%*s%*c|\n", (max / 2),
				"[STACK_B]", (max / 2) + 2, ' ');
		print_stackb(lst, plus, max);
		ft_printf("|%*@|\n", max + 3, "char", '-');
		ft_printf("|%*s%*c|\n", (max / 2),
				"[STACK_A]", (max / 2) + 2, ' ');
		print_stacka(lst, plus, max);
		ft_printf("|%*@|\n", max + 3, "char", '-');
		usleep(lst->time * 10000);
		if (j)
			ft_printf("\033[K\033[%dA", len + 5);
	}
}
