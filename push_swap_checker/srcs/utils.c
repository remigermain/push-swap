/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 10:28:48 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 17:56:49 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

int		ft_issort(t_puswc *lst)
{
	int count;

	count = 0;
	if (lst->len_b != -1)
		return (0);
	while (count < (lst->len_a - 1))
	{
		if (lst->stack_a[count] > lst->stack_a[count + 1])
			return (0);
		count++;
	}
	return (1);
}

void	ps_free(t_puswc *lst)
{
	if (lst != NULL)
	{
		if (lst->stack_a != NULL)
			free(lst->stack_a);
		if (lst->stack_b != NULL)
			free(lst->stack_b);
		free(lst);
	}
}

void	ps_error(t_puswc *lst)
{
	ps_free(lst);
	ft_printf("%1@", "error", "push_swapp_checker", strerror(errno));
}
