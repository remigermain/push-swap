/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 17:21:19 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

static void	ps_interact2(t_puswc *lst, char *line)
{
	if (!ft_strcmp(line, "sa"))
		swap_a(lst);
	else if (!ft_strcmp(line, "sb"))
		swap_b(lst);
	else if (!ft_strcmp(line, "ss"))
		swap_ab(lst);
	else if (!ft_strcmp(line, "pb"))
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
	else if (!ft_strcmp(line, "pa"))
		push_a(lst);
}

static void	ps_interact_undo(t_puswc *lst, char *line)
{
	if (!ft_strcmp(line, "sa"))
		swap_a(lst);
	else if (!ft_strcmp(line, "sb"))
		swap_b(lst);
	else if (!ft_strcmp(line, "ss"))
		swap_ab(lst);
	else if (!ft_strcmp(line, "pa"))
		push_b(lst);
	else if (!ft_strcmp(line, "pb"))
		push_a(lst);
	else if (!ft_strcmp(line, "ra"))
		rev_rotate_a(lst);
	else if (!ft_strcmp(line, "rb"))
		rev_rotate_b(lst);
	else if (!ft_strcmp(line, "rr"))
		rev_rotate_ab(lst);
	else if (!ft_strcmp(line, "rra"))
		rotate_a(lst);
	else if (!ft_strcmp(line, "rrb"))
		rotate_b(lst);
	else if (!ft_strcmp(line, "rrr"))
		rotate_ab(lst);
	if (lst->instruction > 0)
		lst->instruction -= 2;
}

static int	ps_free_interact(t_puswc *lst, char **line)
{
	int ret;

	ret = 0;
	if ((*line) != NULL)
	{
		if (!ft_strcmp((*line), "break"))
			ps_final_check(lst);
		if (!ft_strcmp((*line), "undo"))
			ret = -1;
		ft_memdel((void**)line);
	}
	return (ret);
}

int			ps_interact(t_puswc *lst, int ret)
{
	char *line;

	ps_ivisu(lst);
	while (get_next_line(0, &line) == 1)
	{
		if (!ft_strcmp(line, "break") || !ft_strcmp(line, "undo"))
			return (ps_free_interact(lst, &line));
		else
			ps_interact2(lst, line);
		ret = ps_interact(lst, 1);
		if (ret == 0)
			return (ps_free_interact(lst, &line));
		else if (ret == -1)
			ps_interact_undo(lst, line);
		ft_memdel((void**)&line);
		ps_ivisu(lst);
	}
	return (ps_free_interact(lst, &line));
}
