/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:33:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 13:47:10 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

static int		init_file(int *argc, char ***argv)
{
	int fd;

	fd = 0;
	if (!ft_strcmp((*argv)[(*argc) - 2], "-f"))
	{
		if (!(fd = open((*argv)[(*argc) - 1], O_RDONLY)))
			fd = 0;
		(*argv)[(*argc) - 2] = NULL;
		(*argc) -= 2;
	}
	if ((*argc) < 2)
		return (-1);
	return (fd);
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
	if ((*argc) < 2)
		return (-1);
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
	if ((*argc) < 2)
		return (-1);
	return (interact);
}

static int		main_manager(int argc, char **argv)
{
	t_puswc	*lst;
	char	interact;
	int		time;
	int		ret;
	int		fd;

	ret = 1;
	if ((fd = init_file(&argc, &argv)) == -1 ||
		(time = init_time_interact(&argc, &argv)) == -1 ||
		(interact = init_interact(&argc, &argv)) == -1 ||
		!check_arg(argv))
		return (0);
	lst = ps_struct_init(argc, argv);
	lst->fd = fd;
	lst->instruction = 0;
	lst->visu = interact;
	lst->time = (time == -2 ? 0 : time);
	if (interact == 2)
		ps_interact(lst, 1);
	else
		ret = ps_checker(lst);
	if (lst->fd != 0)
		close(fd);
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
