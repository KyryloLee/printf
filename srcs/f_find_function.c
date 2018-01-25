/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_find_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:09:41 by klee              #+#    #+#             */
/*   Updated: 2018/01/23 13:09:42 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_length_dop(t_flgs *input, char **res)
{
	char			*tmp;
	intmax_t		n[2];

	tmp = *res;
	n[0] = ft_strlen(*res) - input->length;
	if (n[0] < 0)
	{
		if (ft_strstr(input->flags, "0"))
			tmp = f_strnew_null(-n[0]);
		else
			tmp = f_strnew_spc(-n[0]);
		if (ft_strstr(input->flags, "-"))
			f_join_free(res, tmp);
		else
			f_join_free_b(res, tmp);
		free(tmp);
	}
}

void	f_length(t_flgs *input, t_prf *new, char **res)
{
	if (input->length)
			f_length_dop(input, res);
	if (new)
		;
}

void	f_flags(t_flgs *input, t_prf *new, char **res)
{
	f_accurancy(input, new, res);
	if (input->length)
	{
		if (input->accuracy == 0 && ft_strstr(input->flags, "0"))
		{
			input->accuracy = input->length;
			f_accurancy(input, new, res);
		}
		else
			f_length(input, new, res);
	}
	if (ft_strstr(input->flags, "#") && ft_strstr(new->flags, "#"))
		f_join_free_b(res, "0x");
}

int		find_func(t_flgs *input, char **res, va_list ap)
{
	t_prf			*new;
	t_prf			*tmp;
	intmax_t		i;

	tmp = type_list();
	new = tmp;
	while (new)
		if (!(ft_strncmp(input->type, new->type, ft_strlen(new->type))))
		{
			if (ft_one_equ(input->type, "dDioOuUxXp"))
			{
				i = f_size_nbr(input, ap);
				new->f(res, i);
			}
			else
				new->f(res, ap);
																	// printf("[%s]\n", new->type);
			f_flags(input, new, res);
			break ;
		}
		else
			new = new->next;
	del_prf(&tmp);
	return (1);
}
