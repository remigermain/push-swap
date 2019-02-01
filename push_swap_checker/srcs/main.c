/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:33:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/01 19:19:58 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

int	main_manager(int argc, char **argv)
{
	t_puswc	*lst;
	
	if (check_arg(argv) == -1)
		return (-1);
	lst = ps_struct_init(argc, argv);
	if (ps_checker(lst) == -1)
		return (-1);
	ps_free(lst);
	return (1);
}

int main(int argc, char **argv)
{
	int ret;

	if (argc > 1)
		if (main_manager(argc, argv) == -1)
			ft_dprintf(2, "Error\n");
	return (0);
}
