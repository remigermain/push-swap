/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/01 19:26:20 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

/*    sa   */
void	swap_a(t_pusw *lst)
{
	int	swap;

	if (lst->len_a > 0)
	{
		swap = lst->stack_a[lst->len_a];
		lst->stack_a[lst->len_a] = lst->stack_a[lst->len_a - 1];
		lst->stack_a[lst->len_a - 1] = swap;
	}
	lst->instruction++;
	ft_printf("sa\n");
}

/*     sb   */
void	swap_b(t_pusw *lst)
{
	int	swap;

	if (lst->len_b > 0)
	{
		swap = lst->stack_b[lst->len_b];
		lst->stack_b[lst->len_b] = lst->stack_b[lst->len_b - 1];
		lst->stack_b[lst->len_b - 1] = swap;
	}
	lst->instruction++;
	ft_printf("sb\n");
}

/*   ss   */
void	swap_ab(t_pusw *lst)
{
	swap_a(lst);
	swap_b(lst);
}

/*    pa   */
void	push_a(t_pusw *lst)
{
	if (lst->len_b >= 0)
		lst->stack_a[++lst->len_a] = lst->stack_b[lst->len_b--];
	lst->instruction++;
	ft_printf("pa\n");
}

/*    pb  */
void	push_b(t_pusw *lst)
{
	if (lst->len_a >= 0)
		lst->stack_b[++lst->len_b] = lst->stack_a[lst->len_a--];
	lst->instruction++;
	ft_printf("pb\n");
}

/*    ra    */
void	rotate_a(t_pusw *lst)
{
	int len;

	len = lst->len_a;
	if (lst->len_a > 0)
	{
		while (len >= 0)
		{
			lst->stack_a[len + 1] = lst->stack_a[len];
			len--;
		}
		lst->stack_a[0] = lst->stack_a[lst->len_a + 1];
	}
	lst->instruction++;
	ft_printf("ra\n");
}

/*    rb    */
void	rotate_b(t_pusw *lst)
{
	int len;

	len = lst->len_b;
	if (lst->len_b > 0)
	{
		while (len >= 0)
		{
			lst->stack_b[len + 1] = lst->stack_b[len];
			len--;
		}
		lst->stack_b[0] = lst->stack_b[lst->len_b + 1];
	}
	lst->instruction++;
	ft_printf("rb\n");
}

/*    rr   */
void	rotate_ab(t_pusw *lst)
{
	rotate_a(lst);
	rotate_b(lst);
}

/*    rra    */
void	rev_rotate_a(t_pusw *lst)
{
	int len;

	len = 0;
	if (lst->len_a > 0)
	{
		lst->stack_a[lst->len_a + 1] = lst->stack_a[0];
		while (len < (lst->len_a + 1))
		{
			lst->stack_a[len] = lst->stack_a[len + 1];
			len++;
		}
	}
	lst->instruction++;
	ft_printf("rra\n");
}

/*    rrb    */
void	rev_rotate_b(t_pusw *lst)
{
	int len;

	len = 0;
	if (lst->len_b > 0)
	{
		lst->stack_b[lst->len_b + 1] = lst->stack_b[0];
		while (len < (lst->len_b + 1))
		{
			lst->stack_b[len] = lst->stack_b[len + 1];
			len++;
		}
	}
	lst->instruction++;
	ft_printf("rrb\n");
}

/*    rrr   */
void	rev_rotate_ab(t_pusw *lst)
{
	rev_rotate_a(lst);
	rev_rotate_b(lst);
}