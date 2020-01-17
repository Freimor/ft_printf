#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_printf
{
	char	*format;
	int		fd;
	va_list	list;
	int 	anker;
}				t_printf;

#endif // !FT_PRINTF_H