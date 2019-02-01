/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:38:55 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/31 18:22:09 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftprintf_error(t_pf *lst, char *str, size_t index)
{
	ft_putstr_fd("\n  / \\    WARNING\n / | \\  FT_PRINT ERROR", 2);
	ft_putstr_fd("\n/  o  \\\n-------\n     	[", 2);
	if (index == 1)
		ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\"", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("]     \n\n", 2);
	if (lst != NULL)
	{
		if (lst->str != NULL)
			free(lst->str);
		free(lst);
	}
	exit(0);
}

int		ulen_base(ULONG nb, size_t base)
{
	return (nb >= base ? ulen_base(nb / base, base) + 1 : 1);
}

size_t	len_pstrn(UCHAR *str, size_t len, size_t index)
{
	size_t i;
	size_t a;

	i = 0;
	a = 0;
	if (index == 1)
		len = ft_ustrlen(str) + 1;
	while (str[i] != '\0' && i < len)
	{
		if (ft_isprint(str[i] && str[i] != '\n') || str[i] == '\t')
			a++;
		else
			a += 2;
		i++;
	}
	return (a);
}

void	conv_nlen(t_pf *lst)
{
	int	*tmp;

	tmp = va_arg(lst->va_copy, int*);
	if (tmp != NULL)
		*tmp = (lst->count + lst->buff_count);
}
