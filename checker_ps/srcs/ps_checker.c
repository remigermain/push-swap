/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 14:56:56 by rgermain    ###    #+. /#+    ###.fr     */
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

static	void	ps_initncurses(t_puswc *lst)
{
	if (lst->visu != 0)
	{
		lst->win = initscr();
		noecho();
		use_default_colors();
		start_color();
		curs_set(0);
		lst->win_h = 0;
		lst->win_w = 0;
		init_pair(1, -1, -1);
		init_pair(2, 7, -1);
		init_pair(3, 4, -1);
		init_pair(4, 3, -1);
		getmaxyx(lst->win, lst->win_h, lst->win_w);
		refresh();
		ps_visu_header(lst);
	}
}

void	ps_endcurses(t_puswc *lst)
{
	if (lst->visu != 0)
	{
		endwin();
	}
}

int			ps_checker(t_puswc *lst)
{
	char	*line;

	ps_initncurses(lst);
	ps_visu(lst, 1);
	while (get_next_line(0, &line) == 1)
	{
		if (!ps_checker2(lst, line))
		{
			free(line);
			return (0);
		}
		free(line);
		ps_visu(lst, 1);
	}
	ps_visu(lst, 0);
	ps_endcurses(lst);
	ps_final_check(lst);
	return (1);
}
