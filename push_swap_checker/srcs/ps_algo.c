/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 09:35:30 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

int	ps_checker2(t_puswc *lst, char *line)
{
	if (ft_strcmp(line, "ra") == 0)
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
		return (-1);
	return (1);
}	

int		ps_checker(t_puswc *lst)
{
	char	*line;

	while (get_next_line(0, &line) == 1)
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
		else
		{
			if (ps_checker2(lst, line) == -1)
			{
				free(line);
				return (-1);
			}
		}
		free(line);
	}
	return (ft_issort(lst));
}
