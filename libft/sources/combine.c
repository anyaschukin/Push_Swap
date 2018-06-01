/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:34:13 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/10 14:36:59 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*apply_precision(t_print *arg, t_out *out, intmax_t len)
{
	char		*add;
	intmax_t	tmp;

	tmp = PREC - len;
	if (CONV == 'S' || CONV == 's')
	{
		while ((out->string[PREC] & 0xC0) == 0x80)
			PREC--;
		PREC > WIDTH ? out->string[PREC] = '\0' : 0;
		PREC < len ? ft_strclr(out->string + PREC) : 0;
	}
	if (PREC >= len && CONV != 's')
	{
		arg->isnegative ? tmp += 1 : 0;
		if (!(add = (char*)malloc(sizeof(char) * tmp + 1)))
			error_exit(ERROR, 1);
		add[tmp] = '\0';
		ft_memset(add, '0', tmp);
		if (!(out->string = ft_strjoin_free(add, out->string, 3)))
			error_exit(ERROR, 1);
		(PREC > WIDTH && DASH) ? DASH = 0 : 0;
	}
	return (out->string);
}

static char	*apply_plus_space_hash(t_print *arg, t_out *out)
{
	if (HASH == 1)
	{
		if (CONV == 'o' || CONV == 'O')
		{
			if (!(out->string = ft_strjoin_free("0", out->string, 2)))
				error_exit(ERROR, 1);
		}
		if (CONV == 'x' || CONV == 'X')
		{
			if (!(out->string = ft_strjoin_free("0x", out->string, 2)))
				error_exit(ERROR, 1);
		}
	}
	if (PLUS == 1 && arg->ispositive == 1)
		out->string = ft_strjoin_free("+", out->string, 2);
	else if (SPACE == 1 && !(arg->isnegative == 1))
		out->string = ft_strjoin_free(" ", out->string, 2);
	return (out->string);
}

static char	*apply_width(t_print *arg, t_out *out, intmax_t len)
{
	char		*add;
	intmax_t	tmp;

	(CONV == 'c' && ft_strcmp("\0", out->value) == 0) ? len = 1 : 0;
	tmp = WIDTH - len;
	if (CONV == 'p' && WFIELD == 1 && ZERO == 1)
		tmp -= 2;
	if (WIDTH > len)
	{
		add = ft_strnew(tmp);
		add[tmp] = '\0';
		ft_memset(add, ' ', tmp);
		if (PREC > 1 && DASH && (CONV != 'c'))
		{
			if (!(out->string = ft_strjoin_free(out->string, add, 3)))
				error_exit(ERROR, 1);
			DASH = 0;
		}
		else
		{
			if (!(out->string = ft_strjoin_free(add, out->string, 3)))
				error_exit(ERROR, 1);
		}
	}
	return (out->string);
}

static char	*apply_zero_dash(t_print *arg, t_out *out)
{
	intmax_t	len;
	intmax_t	vlen;
	intmax_t	move;

	len = ft_strlen(out->string);
	vlen = (CONV == 'C' || CONV == 'S') ? ft_strwlen(out->value) :
		ft_strlen(out->value);
	if (ZERO == 1 && WIDTH > vlen)
	{
		arg->isnegative ? WIDTH++ : 0;
		CONV == 'p' ? vlen += 2 : 0;
		ft_memset(out->string, '0', WIDTH - vlen);
		(SPACE && CONV == 'd') ? *out->string = ' ' : 0;
		(PLUS && arg->ispositive == 1) ? *out->string = '+' : 0;
		if (arg->isnegative == 1 && !(PLUS && arg->ispositive == 1))
			*out->string = '-';
	}
	else if (DASH == 1)
	{
		(CONV != 'p' && (ft_strchr(out->string, 'x'))) ? vlen += 2 : 0;
		(CONV == 'o' && HASH == 1) ? vlen += 1 : 0;
		move = vlen - len;
		ft_strrotate(out->string, len, move);
	}
	return (out->string);
}

char		*combine(t_print *arg, t_out *out, intmax_t len)
{
	PFIELD == 1 ? apply_precision(arg, out, len) : 0;
	apply_plus_space_hash(arg, out);
	WFIELD == 1 ? apply_width(arg, out, ft_strlen(out->string)) : 0;
	(DASH == 1 || ZERO == 1) ? apply_zero_dash(arg, out) : 0;
	return (out->string);
}
