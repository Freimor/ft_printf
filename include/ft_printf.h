#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_printf
{
	char		*format;
	char		*stroke;
	int			fd;
	va_list		list;
	int 		anker;
	t_modlayer	mod;
}				t_printf;

typedef struct	s_modlayer
{
	int			error;
	char		*flag;
	int			remove_0;
	char		type;
	int			size;
	int			field_len;
	int			precision;
	int			precision_zero;
	char		orientation;
	char		zeromod;
	char		sharp;
	char		sign;
	char		isprecision;
	char		specificator;
}				t_modlayer;

int				c_type(t_modlayer mod, t_printf work);
void			init_structure(t_printf work, char *format);

#endif // !FT_PRINTF_H