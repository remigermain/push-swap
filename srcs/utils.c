/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 10:28:48 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 11:20:05 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_putbuff(t_pusw *lst, char *str, char len)
{
	if ((lst->ps_count + len) > PS_BUFFSIZE)
	{
		write(1, lst->ps_buff, lst->ps_count);
		lst->ps_count = 0;
	}
	ft_memcpy(lst->ps_buff + lst->ps_count, str, len);
	lst->ps_count += len;
}

void	ps_free(t_pusw *lst)
{
	if (lst != NULL)
	{
		if (lst->stack_a != NULL)
			ft_memdel((void**)&(lst->stack_a));
		if (lst->stack_b != NULL)
			ft_memdel((void**)&(lst->stack_b));
		ft_memdel((void**)&(lst));
	}
}

void	ps_error(t_pusw *lst)
{
	ps_free(lst);
	ft_printf("%1@", "error", "push_swapp", strerror(errno));
}
