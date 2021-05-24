/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:14:21 by saray             #+#    #+#             */
/*   Updated: 2021/02/08 10:50:00 by saray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# define LEFT 1
# define RIGHT 0

typedef struct	s_elem
{
	char		type;
	char		*data;
	char		pad;
	int			align;
	int			width;
	int			size;
	int			prec;
	int			zero_flag;
	int			error_flag;
	wchar_t		wchar;
}				t_elem;

int				ft_printf(const char *str, ...);
int				elem_print(const char **str, va_list *param);
char			*ft_fill_buffer(t_elem *e);
char			*ft_prec(t_elem *e);
char			*arg_to_str(char *arg);
char			*arg_to_ptr(unsigned long long ptr);
char			*arg_to_chr(t_elem *e, wchar_t x);
char			*fix_hex(char *src);
void			fix_minus(char *src);
void			ft_set_flag(const char **str, t_elem *e, va_list *param);
void			ft_set_prec(const char **str, t_elem *e, va_list *param);
int				ft_set_data(t_elem *e, va_list *param);
int				ft_set_padlen(t_elem *e, int datalen);

#endif
