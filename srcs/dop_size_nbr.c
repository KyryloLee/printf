/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_size_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:06:39 by klee              #+#    #+#             */
/*   Updated: 2018/01/26 16:06:43 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	dop_size_nbr(t_flgs *input, va_list ap)
{
	if (ft_strstr(input->size, "l"))
	{
		if (ft_strstr(input->type, "u"))
			{
		printf("inside\n");
			return (va_arg(ap, unsigned long int));
			}
		else
			return (va_arg(ap, long));
	}
	else if (ft_strstr(input->size, "h") && !ft_strstr(input->size, "hh"))
	{
		if (ft_strstr(input->type, "u"))
			return ((short int)va_arg(ap, unsigned int));
		else
			return ((short int)va_arg(ap, int));
	}
	else if (ft_one_equ(input->size, "hdD"))
		return (dop_size_nbr2(input, ap));
	return (0);
}

intmax_t	dop_size_nbr2(t_flgs *input, va_list ap)
{
	if (ft_strstr(input->size, "hh"))
	{
		if (ft_strstr(input->type, "u"))
			return ((signed char)va_arg(ap, unsigned int));
		else
			return ((signed char)va_arg(ap, int));
	}
	else if (input->type[0] == 'd')
	{
		if (ft_strstr(input->type, "u"))
			return (va_arg(ap, unsigned int));
		else
			return (va_arg(ap, int));
	}
	else if (input->type[0] == 'D')
	{
		if (ft_strstr(input->type, "u"))
			return (va_arg(ap, unsigned long int));
		else
			return (va_arg(ap, long int));
	}
	return (0);
}