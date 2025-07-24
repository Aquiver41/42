#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *c)
{
	int	len;

	len = 0;
	if (!c)
		return (write(1, "(null)", 6));
	while (c[len])
		len++;
	return (write(1, c, len));
}

static int	ft_type(const char c, va_list arguments)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arguments, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arguments, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(arguments, void *)));
	else if ((c == 'd' || c == 'i'))
		return (ft_putintdec(va_arg(arguments, int)));
	else if (c == 'u')
		return (ft_putnbrunsigned(va_arg(arguments, unsigned int)));
	else if ((c == 'x' || c == 'X'))
		return (ft_puthex_upx(va_arg(arguments, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	return (ft_putchar('%'));
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		i;
	int		length;
	int		prnt;

	i = 0;
	length = 0;
	va_start(arguments, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			prnt = ft_type(format[i], arguments);
               if (prnt == -1)
                    return (va_end(arguments), -1);
		}
          else if (format[i] == '%' && !format[i + 1])
               return (va_end(arguments), -1);
		else
			prnt = write(1, &format[i], 1);
		if (prnt == -1)
			return (va_end(arguments), -1);
		length += prnt;
		i++;
	}
	va_end(arguments);
	return (length);
}
