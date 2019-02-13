/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_visu.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 14:41:45 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 14:57:43 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

void		ps_visu_confi(t_puswc *lst, int i)
{
	unsigned char *str;

	move((lst->win_h / 4) + i + 4, (lst->win_w / 8));
	addstr("tapez ");
	addch('E' | A_BLINK | COLOR_PAIR(4));
	addch('N' | A_BLINK | COLOR_PAIR(4));
	addch('T' | A_BLINK | COLOR_PAIR(4));
	addch('E' | A_BLINK | COLOR_PAIR(4));
	addch('R' | A_BLINK | COLOR_PAIR(4));
	addstr(" pour commencer le visualisateur");
	while (getch() != '\n')
	{
		move((lst->win_h / 4) + i + 5, (lst->win_w / 8));
		addstr("                ");
		move((lst->win_h / 4) + i + 5, (lst->win_w / 8));
		addstr("wrong commands");
		refresh();
		usleep(200000);
	}
	clear();
}
void		ps_visu_header(t_puswc *lst)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open("srcs/header", O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		move((lst->win_h / 4) + i++, (lst->win_w / 8));
		while (line[j] != '\0')
		{
			if (!ft_strstr(line, "r_germain"))
				addch(line[j++] | A_NORMAL | COLOR_PAIR(2));
			else
				addch(line[j++] | A_NORMAL | COLOR_PAIR(3));
		}
		addch('\n');
		wborder(lst->win, 50, 50, 50, 50, 50, 50, 50, 50);
		refresh();
		ft_memdel((void**)(&line));
	}
	ps_visu_confi(lst, i);
}

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
	int			max;
	int			plus;
	int			len;
	
	wborder(lst->win, 50, 50, 50, 50, 50, 50, 50, 50);
	if (lst->visu == 1)
	{
		len = lst->len_a + lst->len_b + 2;
		plus = MAX(ft_intlen(lst->tri[0]),
				ft_intlen(lst->tri[len - 1])) + 2;
		max = (plus * 4) + len;
		ft_printf("|%*@|\n", max + 3, "char", '-');
		ft_printf("|%*s%*c |\n", (max / 2),
				"[STACK_B]", (max / 2) + 2, ' ');
		print_stackb(lst, plus, max);
		ft_printf("|%*@|\n", max + 3, "char", '-');
		ft_printf("|%*s%*c |\n", (max / 2),
				"[STACK_A]", (max / 2) + 2, ' ');
		print_stacka(lst, plus, max);
		ft_printf("|%*@|\n", max + 3, "char", '-');
		usleep(lst->time * 10000);
		if (j)
			//ft_printf("\033[K\033[%dA", len + 5);
			move(0, 0);
	}
}
