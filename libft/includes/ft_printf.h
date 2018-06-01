/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:19:35 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/10 16:29:48 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>

# define DASH arg->isdash
# define PLUS arg->isplus
# define ZERO arg->iszero
# define SPACE arg->isspace
# define HASH arg->ishash
# define PFIELD arg->precision_field
# define PREC arg->precision
# define WFIELD arg->width_field
# define WIDTH arg->width
# define CONV arg->converter
# define ERROR "Error: out of memory. Exiting"

typedef struct	s_print
{
	char			converter;
	int				i;
	int				ret;
	const char		*format;

	unsigned int	isdash : 1;
	unsigned int	isplus : 1;
	unsigned int	iszero : 1;
	unsigned int	isspace : 1;
	unsigned int	ishash : 1;
	unsigned int	ispercent : 1;

	unsigned int	width_field;
	unsigned int	width;

	unsigned int	precision_field;
	unsigned int	precision;

	unsigned int	ispositive : 1;
	unsigned int	isnegative : 1;

	enum
	{
		none,
		hh,
		h,
		j,
		l,
		ll,
		z,
	}				length;

}				t_print;

typedef struct	s_out
{
	char			*string;
	char			*value;
	intmax_t		vlen;
}				t_out;

/*
** ft_printf Functions
*/

int				ft_printf(const char *format, ...);
int				ft_printf_conversion(va_list *ap, t_print *arg);
void			ft_init_struct(t_print *arg, t_out *out);
int				ft_check_flags(t_print *arg);
int				ft_check_width(t_print *arg);
int				ft_check_precision(t_print *arg);
int				ft_check_length(t_print *arg);
int				ft_check_errors(t_print *arg);
intmax_t		ft_length_conversion(intmax_t nb, t_print *arg);
uintmax_t		ft_ulength_conversion(uintmax_t nb, t_print *arg);
char			*combine(t_print *arg, t_out *out, intmax_t len);

/*
** Conversion Character Functions
*/

void			flag_c(va_list *ap, t_print *arg);
void			flag_d(va_list *ap, t_print *arg);
void			flag_i(va_list *ap, t_print *arg);
void			flag_o(va_list *ap, t_print *arg);
void			flag_p(va_list *ap, t_print *arg);
void			flag_s(va_list *ap, t_print *arg);
void			flag_u(va_list *ap, t_print *arg);
void			flag_x(va_list *ap, t_print *arg);
void			flag_percent(t_print *arg);

#endif
