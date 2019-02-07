/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:33:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 16:13:16 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_time_interact(int *argc, char ***argv)
{
	int	time;

	time = -1;
	if ((*argv)[(*argc) - 2][0] == 'v')
	{
		time = ft_atoi((*argv)[(*argc) - 1]);
		(*argv)[(*argc) - 1] = NULL;
		(*argc) -= 1;
	}
	return (time);
}

static MINT	init_interact(int *argc, char ***argv)
{
	MINT	interact;

	interact = 0;
	if ((*argv)[(*argc) - 1][0] == 'v' || (*argv)[(*argc) - 1][0] == 'i')
	{
		if ((*argv)[(*argc) - 1][0] == 'i')
			interact = 2;
		else
			interact = 1;
		(*argv)[(*argc) - 1] = NULL;
		(*argc) -= 1;
	}
	return (interact);
}

static int	main_manager(int argc, char **argv)
{
	t_pusw	*lst;
	MINT	interact;
	int		time;

	time = init_time_interact(&argc, &argv);
	interact = init_interact(&argc, &argv);
	if (!check_arg(argv))
		return (0);
	lst = ps_struct_init(argc, argv);
	lst->visu = interact;
	lst->time = (time == -1 ? 0 : time);
	if (interact == 2)
		ps_interact(lst);
	else
		ps_algo(lst);
	ps_free(lst);
	return (1);
}

int			main(int argc, char **argv)
{
	int ret;

	if (argc > 1)
		if (!main_manager(argc, argv))
			ft_dprintf(2, "Error\n");
	return (0);
}
