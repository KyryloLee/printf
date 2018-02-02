/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:29:40 by klee              #+#    #+#             */
/*   Updated: 2018/01/02 14:29:43 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list	ap;
	int		d;
	char	*s;

	va_start(ap, format);
	s = f_srch(format, ap);
	va_end(ap);
	d = ft_strlen(s);
	write(1, s, d);
	free(s);
	return (d);
}
