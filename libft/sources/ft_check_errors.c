/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:56:29 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/09 15:02:47 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check_errors(t_print *arg)
{
	if (SPACE == 1 && ft_strchr("cCsSuUxXp%", arg->format[arg->i]))
		SPACE = 0;
	if (SPACE == 1 && PLUS == 1)
		SPACE = 0;
	if (HASH == 1 && ft_strchr("cCdipsu", arg->format[arg->i]))
		HASH = 0;
	if (ZERO == 1 && DASH == 1)
		ZERO = 0;
	if (ZERO == 1 && PFIELD == 1 && ft_strchr("diou", arg->format[arg->i]))
		ZERO = 0;
	if (PFIELD == 1 && ft_strchr("cC", arg->format[arg->i]))
		PFIELD = 0;
	if (arg->length == 1 && ft_strchr("cCpsS", arg->format[arg->i]))
		return (-1);
	if (arg->format[arg->i] == '\'')
		arg->i++;
	return (arg->i);
}
