/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 13:27:35 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

static int	ps_checker2(t_puswc *lst, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		swap_a(lst);
	else if (ft_strcmp(line, "sb") == 0)
		swap_b(lst);
	else if (ft_strcmp(line, "ss") == 0)
		swap_ab(lst);
	else if (ft_strcmp(line, "pa") == 0)
		push_a(lst);
	else if (ft_strcmp(line, "pb") == 0)
		push_b(lst);
	else if (ft_strcmp(line, "ra") == 0)
		rotate_a(lst);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_b(lst);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_ab(lst);
	else if (ft_strcmp(line, "rra") == 0)
		rev_rotate_a(lst);
	else if (ft_strcmp(line, "rrb") == 0)
		rev_rotate_b(lst);
	else if (ft_strcmp(line, "rrr") == 0)
		rev_rotate_ab(lst);
	else
		return (0);
	return (1);
}

int			ps_checker(t_puswc *lst)
{
	char	*line;
	int		index;

	ps_visu(lst, 1);
	index = 0;
	while (get_next_line(lst->fd, &line) == 1)
	{
		if (!ps_checker2(lst, line))
			index = 1;
		ft_memdel((void**)&line);
		ps_visu(lst, 1);
	}
	if (index == 1)
		return (0);
	ps_visu(lst, 0);
	ps_final_check(lst);
	return (1);
}
