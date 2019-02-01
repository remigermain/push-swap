/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_int.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:24:00 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/31 18:06:14 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	lst_putnb_unb(t_pf *lst)
{
	if (LENGHT == 1 && CONV != 'O' && CONV != 'U'
			&& CONV != 'D')
		lst->ul_nb = (unsigned short)va_arg(lst->va_copy, ULONG);
	else if (LENGHT == 2 && CONV != 'O' && CONV != 'U'
			&& CONV != 'D')
		lst->ul_nb = (unsigned char)va_arg(lst->va_copy, ULONG);
	else if (LENGHT == 10)
		lst->ul_nb = va_arg(lst->va_copy, long);
	else if (LENGHT == 20)
		lst->ul_nb = va_arg(lst->va_copy, ULONG);
	else if (LENGHT == 100)
		lst->ul_nb = va_arg(lst->va_copy, intmax_t);
	else if (LENGHT == 1000)
		lst->ul_nb = va_arg(lst->va_copy, size_t);
	else if (CONV == 'o' || CONV == 'x' || CONV == 'X' ||
			CONV == 'u' || CONV == 'X')
		lst->ul_nb = va_arg(lst->va_copy, unsigned int);
	else
		lst->ul_nb = va_arg(lst->va_copy, ULONG);
	if (SIGN == '+' && (CONV == 'd' || CONV == 'D' ||
				CONV == 'I' || CONV == 'i'))
		PSIGN = "+";
}

static void	lst_putnb_snb(t_pf *lst)
{
	long nb_tmp;

	if (LENGHT == 1)
		nb_tmp = (short)va_arg(lst->va_copy, int);
	else if (LENGHT == 2)
		nb_tmp = (char)va_arg(lst->va_copy, int);
	else if (LENGHT == 10)
		nb_tmp = va_arg(lst->va_copy, long);
	else if (LENGHT == 20)
		nb_tmp = va_arg(lst->va_copy, long);
	else if (LENGHT == 100)
		nb_tmp = va_arg(lst->va_copy, intmax_t);
	else if (LENGHT == 1000)
		nb_tmp = va_arg(lst->va_copy, size_t);
	else if (CONV == 'D' || CONV == 'I' || LENGHT != 0)
		nb_tmp = va_arg(lst->va_copy, long);
	else
		nb_tmp = va_arg(lst->va_copy, int);
	PSIGN = (nb_tmp < 0 ? "-" : "");
	if (SIGN == '+' && nb_tmp >= 0 && (CONV == 'd' ||
				CONV == 'D' || CONV == 'I' || CONV == 'i'))
		PSIGN = "+";
	lst->ul_nb = (nb_tmp < 0 ? -nb_tmp : nb_tmp);
}

void		lst_putint(t_pf *lst)
{
	if (CONV == 'd' || (CONV == 'i') ||
			(CONV == 'D' && LENGHT == 0))
		lst_putnb_snb(lst);
	else
		lst_putnb_unb(lst);
	if (CONV == 'p' || ((CONV == 'x' || CONV == 'X')
				&& HASH == 1 && lst->ul_nb != 0))
		PSIGN = (MAJ == 1 ? "0X" : "0x");
}

static void	ft_spacecalc(t_pf *lst, int len)
{
	if ((HASH == 1 && (CONV == 'o' || CONV == 'O')) &&
		!((lst->ul_nb == 0 && POINT == 1 && PRECI > 0) ||
			(POINT == 0 && lst->ul_nb == 0)))
	{
		HASH = 1;
		if ((POINT == 1 && PRECI > len))
			PRECI = (PRECI != 0 ? PRECI - 1 : PRECI);
		if (FIELD < 0)
			FIELD++;
	}
	else
		HASH = 0;
	if (POINT == 1 && PRECI >= 0)
		ZERO = 0;
	if (SPACE == 1 && SIGN != '+' && ft_strlen(PSIGN) == 0
			&& CONV != 'u' && CONV != 'U')
	{
		put_prefix(lst, 0, 1, 0);
		if (FIELD > 0)
			FIELD--;
		else if (FIELD < 0)
			FIELD++;
	}
}

void		conv_int(t_pf *lst)
{
	int len;
	int max;

	lst_putint(lst);
	len = ulen_base(lst->ul_nb, BASE);
	if (lst->ul_nb == 0 && POINT == 1 && PRECI == 0)
		len = 0;
	ft_spacecalc(lst, len);
	max = MAX(len, PRECI) + ft_strlen(PSIGN);
	if (ZERO == 1)
		put_buff(lst, PSIGN, ft_strlen(PSIGN), 0);
	put_prefix(lst, max + HASH, FIELD, ZERO);
	if (ZERO == 0)
		put_buff(lst, PSIGN, ft_strlen(PSIGN), 0);
	put_prefix(lst, 0, HASH, 1);
	put_prefix(lst, len, PRECI, 1);
	if (!(POINT == 1 && PRECI == 0 && lst->ul_nb == 0))
		put_itoa(lst, lst->ul_nb);
	put_prefix(lst, max, -FIELD, 0);
}
