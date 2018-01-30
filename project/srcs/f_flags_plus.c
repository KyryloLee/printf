/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_flags_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:37:20 by klee              #+#    #+#             */
/*   Updated: 2018/01/29 14:37:22 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_flag_plus(t_flgs *input, t_prf *new, char **res)
{
	if (ft_strchr(input->flags, '+') && ft_strchr(new->flags, '+'))
		if (*res[0] != '-')
			f_join_free_b(res, "+");
}

void	f_flag_sps(t_flgs *input, t_prf *new, char **res)
{
	if (input && new && *res)
		;
}

void	f_accurancy_dop(t_flgs *input, intmax_t *n, char **res)
{
	char			*tmp;

	tmp = *res;
	if ((*res[0] == '+' || *res[0] == '-') && input->accuracy)
	{
		n[1] = (*res[0] == '-') ? 1 : 3;
		n[0] = ft_strlen(*res) - input->accuracy - 1;
		*res = ft_strcpy(ft_strnew(ft_strlen(*res) - 1), *res + 1);
		free(tmp);
	}
	if (*res[0] == '0' && input->accuracy && ft_strlen(*res) > 1)
	{
		n[1] = 2;
		*res = ft_strcpy(ft_strnew(ft_strlen(*res) - 2), *res + 2);
		n[0] = ft_strlen(*res) - input->accuracy;
		free(tmp);
	}
	if (n[0] < 0)
	{
		tmp = f_strnew_null(-n[0]);
		f_join_free_b(res, tmp);
		free(tmp);
	}
	(n[1] == 1) ? f_join_free_b(res, "-") : 1 - 1;
	(n[1] == 2) ? f_join_free_b(res, "0x") : 1 - 1;
	(n[1] == 3) ? f_join_free_b(res, "+") : 1 - 1;
}

void	f_accurancy(t_flgs *input, t_prf *new, char **res)
{
	intmax_t		n[2];
	char			*tmp;

	tmp = *res;
	n[0] = ft_strlen(*res) - input->accuracy;
									// printf("len - \t%jd [%s]\n", n[0], *res);
	n[1] = 0;
	if (ft_strchr(new->size, 'z'))
		f_accurancy_dop(input, n, res);
	else
	{
		if (n[0] < 0)
		{
			*res = ft_strncpy(ft_strnew(input->accuracy),\
				*res, input->accuracy);
			free(tmp);
		}
	}
}