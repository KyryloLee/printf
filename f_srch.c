/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_srch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 09:51:23 by klee              #+#    #+#             */
/*   Updated: 2018/01/03 09:51:25 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		f_len_nbr(int nbr)
{
	intmax_t i;

	i = 0;
	while (nbr / 10)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

void	c_jf(char **str, char in)
{
	char	c[2];

	c[1] = '\0';
	c[0] = in;
	f_join_free(str, c);
}

int		f_a_l_s(char *str, t_flgs **fnt)
{
	int		i;

	i = 0;
	if (ft_strchr("-+ #", str[i]))
		c_jf(&(*fnt)->flags, str[i]);
	else if (str[i] == '0' && ft_strchr("+- #hlzj%", str[i - 1]))
		c_jf(&(*fnt)->flags, str[i]);
	else if (str[i] == '.')
	{
		(*fnt)->accuracy = ft_atoi(str + i + 1);
		i = i + f_len_nbr((*fnt)->accuracy) + 1;
	}
	else if (ft_strchr("123456789", str[i]))
	{
		(*fnt)->length = ft_atoi(str + i);
		i = i + f_len_nbr((*fnt)->length);
	}
	else if (ft_strchr("zjlh", str[i]))
		c_jf(&(*fnt)->size, str[i]);
	return (i);
}

t_flgs	*analys_str(char *str, char **res)
{
	t_flgs	*fnt;
	int		i;

	i = 0;
	fnt = flag_list();
	while (str[i])
	{
		if (ft_strchr("-+ #0.123456789zjlh", str[i]))
			i += f_a_l_s(str + i, &fnt);
		else if (ft_strchr("sSpdDioOuUxXcC", str[i]))
		{
			c_jf(&(fnt)->type, str[i]);
			break ;
		}
		else if (ft_strchr("-+# 0123456789zjlh", str[i]))
			i++;
		else
		{
			f_join_free(&(fnt)->type, "%");
			c_jf(res, str[i]);
			break ;
		}
		i++;
	}
	return (fnt);
}

void	put_analys(t_flgs *input)
{
	printf("flags - \t%s\n", input->flags);
	printf("length - \t%d\n", input->length);
	printf("accuracy - \t%d\n", input->accuracy);
	printf("size - \t%s\n", input->size);
	printf("type - \t%s\n", input->type);

}
char	*f_srch(char *str, va_list ap)
{
	char	*res;
	char	chr[2];
	t_flgs	*input;

	res = ft_strdup("");
	chr[1] = '\0';
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			input = analys_str(str, &res);
																				// put_analys(input);
			find_func(input, &res, ap);
			str = ft_strstr(str, input->type);
																				// printf("result of analys_str-\t%s\n", str);
			del_flag_list(&input);
		}
		else
		{
			chr[0] = *str;
			f_join_free(&res, chr);
		}
		str++;
	}
	return (res);
}
