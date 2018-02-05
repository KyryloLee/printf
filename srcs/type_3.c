/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:05:06 by klee              #+#    #+#             */
/*   Updated: 2018/01/23 18:05:07 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_type_bd(char **res, intmax_t input)
{
	char	*s;

	s = ft_itoa((long int)input);
	f_join_free(res, s);
	free(s);
}

void	f_type_nope(char **res, va_list ap)
{
	f_join_free(res, "");
	if (ap)
		;
}

void	f_type_bs(char **res, va_list ap)
{
	wchar_t *s;

	s = va_arg(ap, wchar_t*);
	if (s != NULL)
	{
		// if (MB_CUR_MAX > 1)
			while (*s)
				f_wchar_t(res, *s++);
	}
	else
		f_join_free(res, "(null)");
}