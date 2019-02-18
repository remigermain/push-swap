/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:33:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 10:49:21 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

static t_puswc	*ps_struct_init(int argc, char **argv)
{
	t_puswc	*lst;
	size_t	count;

	count = 0;
	lst = NULL;
	if (!(lst = (t_puswc*)malloc(sizeof(t_puswc))))
		ps_error(lst);
	lst->stack_a = NULL;
	lst->stack_b = NULL;
	lst->tri = NULL;
	lst->len_a = argc - 2;
	lst->len_b = -1;
	if (!(lst->stack_a = (int*)malloc(sizeof(int) * argc)))
		ps_error(lst);
	if (!(lst->stack_b = (int*)malloc(sizeof(int) * argc)))
		ps_error(lst);
	if (!(lst->tri = (int*)malloc(sizeof(int) * argc)))
		ps_error(lst);
	while (--argc > 0)
	{
		lst->stack_a[count] = ft_atoi(argv[argc]);
		lst->tri[count++] = ft_atoi(argv[argc]);
	}
	ft_sort_integer_table(lst->tri, lst->len_a + 1);
	return (lst);
}

static int		init_time_interact(int *argc, char ***argv)
{
	int	time;

	time = -2;
	if (!ft_strcmp((*argv)[(*argc) - 2], "-v") ||
			!ft_strcmp((*argv)[(*argc) - 2], "-i"))
	{
		time = ft_atoi((*argv)[(*argc) - 1]);
		(*argv)[(*argc) - 1] = NULL;
		(*argc) -= 1;
	}
	return (time);
}

static char		init_interact(int *argc, char ***argv)
{
	char	interact;

	interact = 0;
	if (!ft_strcmp((*argv)[(*argc) - 1], "-v") ||
			!ft_strcmp((*argv)[(*argc) - 1], "-i"))
	{
		if (!ft_strcmp((*argv)[(*argc) - 1], "-i"))
			interact = 2;
		else
			interact = 1;
		(*argv)[(*argc) - 1] = NULL;
		(*argc) -= 1;
	}
	return (interact);
}

static int		main_manager(int argc, char **argv)
{
	t_puswc	*lst;
	char	interact;
	int		time;
	int		ret;

	ret = 1;
	time = init_time_interact(&argc, &argv);
	interact = init_interact(&argc, &argv);
	if (argc < 2)
		return (1);
	if (!check_arg(argv))
		return (0);
	lst = ps_struct_init(argc, argv);
	lst->instruction = 0;
	lst->visu = interact;
	lst->time = (time == -2 ? 0 : time);
	if (interact == 2)
		ps_interact(lst, 1);
	else
		ret = ps_checker(lst);
	ps_free(lst);
	return (ret);
}

int				main(int argc, char **argv)
{
	int ret;

	if (argc > 1)
		if (!main_manager(argc, argv))
			ft_dprintf(2, "Error\n");
	return (0);
}
