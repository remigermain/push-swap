/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:33:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 09:55:36 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static int	main_manager(int argc, char **argv)
{
	t_pusw	*lst;
	int		interact;

	interact = 0;
	if (argv[argc - 1][0] == 'v')
	{
		argv[argc - 1] = NULL;
		interact = 1;
	}
	if (!check_arg(argv))
		return (0);
	lst = ps_struct_init(argc - interact, argv);
	if (interact == 1)
		ps_interact(lst, 0);
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
