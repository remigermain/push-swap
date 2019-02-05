/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 17:35:32 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_final_check(t_pusw *lst)
{
	int ret;

	ret = ft_issort(lst);
	ft_printf("\n\n le tableaux est ");
	if (ret == 1 && lst->len_b == -1)
		ft_printf("%{T_GREEN} [OK]%{T_EOC}");
	else
		ft_printf("%{T_RED} [KO]%{T_EOC}");
	ft_printf("\n");
}

static int	ps_interact2(t_pusw *lst, char *line)
{
	if (!ft_strcmp(line, "pb"))
		push_b(lst);
	else if (!ft_strcmp(line, "ra"))
		rotate_a(lst);
	else if (!ft_strcmp(line, "rb"))
		rotate_b(lst);
	else if (!ft_strcmp(line, "rr"))
		rotate_ab(lst);
	else if (!ft_strcmp(line, "rra"))
		rev_rotate_a(lst);
	else if (!ft_strcmp(line, "rrb"))
		rev_rotate_b(lst);
	else if (!ft_strcmp(line, "rrr"))
		rev_rotate_ab(lst);
	else
		return (0);
	return (1);
}

void		ps_interact(t_pusw *lst)
{
	char	*line;
	int		instruct;

	instruct = 0;
	while (1)
	{
		ps_debugs(lst, 9, 0);
		ft_printf("\n nombre d'instruction = %d\n\33[K", instruct);
		get_next_line(0, &line);
		if (!ft_strcmp(line, "sa") && (instruct++))
			swap_a(lst);
		else if (!ft_strcmp(line, "sb") && (instruct++))
			swap_b(lst);
		else if (!ft_strcmp(line, "ss") && (instruct++))
			swap_ab(lst);
		else if (!ft_strcmp(line, "pa") && (instruct++))
			push_a(lst);
		else if (!ft_strcmp(line, "break") || !ft_strcmp(line, "make"))
			break ;
		else if (ps_interact2(lst, line))
			instruct++;
		free(line);
	}
	ps_final_check(lst);
}
