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
	while (nbr)
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
		c_jf(&(*fnt)->flags, str[i++]);
	if (str[i] == '0' && ft_strchr("+- #hlzj%", str[i - 1]))
		c_jf(&(*fnt)->flags, str[i++]);
	if (str[i] == '.')
	{
		(*fnt)->accuracy = ft_atoi(str + i + 1);
		i = i + f_len_nbr((*fnt)->accuracy) + 1;
	}
	if (ft_strchr("123456789", str[i]))
	{
		(*fnt)->length = ft_atoi(str + i);
		i = i + f_len_nbr((*fnt)->length);
	}
	if (ft_strchr("zjlh", str[i]))
		c_jf(&(*fnt)->size, str[i++]);
	return (i);
}

t_flgs	*analys_str(char **str)
{
	t_flgs	*fnt;
	int		i;
	char	*tmp;

	i = 0;
	fnt = flag_list();
	tmp = *str;
	while (*tmp)
	{
		if (ft_strchr("-+ #0.123456789zjlh", tmp[0]))
		{
			tmp += f_a_l_s(*str, &fnt);
		}
		if (ft_strchr("sSpdDioOuUxXcC", tmp[0]))
		{
			c_jf(&(fnt)->type, tmp[0]);
			tmp++;
			break ;
		}
		if (ft_strchr("-+# 0123456789zjlh", tmp[0]))
		{
			tmp++;
		}
		if (ft_strchr("+- 0123456789zjlhSspDdiOoUuXxCc", tmp[0]))
		{
			c_jf(&(fnt)->type, tmp[0]);
			break ;
		}
		tmp++;
	}
	*str = tmp;																			
																					// printf("result *str after analys function-\t[%s]\n", tmp);
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
	char	*just_words;
	char	chr[2];
	t_flgs	*input;

	
	just_words = ft_strdup("");
	chr[1] = '\0';
	while (*str)
	{
		res = ft_strdup("");
		if (*str == '%')
		{
			str++;
			input = analys_str(&str);
																				// put_analys(input);
																				// printf("result str after analys function-\t[%s]\n", str);
			find_func(input, &res, ap);
			del_flag_list(&input);
			f_join_free(&just_words, res);																	// printf("result ater analys-\t|%s|\n", res);
		}
		while (str[0] != '%' && *str)
		{
			chr[0] = *str;
			f_join_free(&just_words, chr);
			str++;
		}
		free(res);
	}
	return (just_words);
}
