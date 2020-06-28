#include "ft_printf.h"

//заменить join let на strjoin
void ft_printf(char* format, ...)
{
    t_data  setings;
    va_list factor;         // указатель на необязательный параметр
    va_start(factor, format);   // устанавливаем указатель
    char *c = format;           // исправить
    while (*c)
    {
        init_data(&setings);
        if(*c != '%')
            ft_putchar(*c); // это медленно, лучше выводить не по символу, а сразу строкой
        else
        {
            c++;
            if (*c == '%')
            {
                ft_putchar(*c);
                break;
            }
            setings.flag = spot_flag(&c);
            setings.width = ft_atoi_2(&c);
            if (*c == '.')
            {
                c++;
                setings.precision = ft_atoi_2(&c);
            }
            setings.mod = spot_mod(&c);
            setings.type = spot_type(&c);
            if (setings.type.f)
            {  setings.precision = (setings.precision == 0) ? 6 : setings.precision;
                if (setings.mod.L)
                    setings.dvalue.Ld = va_arg(factor, long double);
                else
                    setings.dvalue.d = va_arg(factor, double);
            }
            else
                setings.value = va_arg(factor, void*);
            print_value(&setings);
        }
        c++;
    }
    va_end(factor);
}
