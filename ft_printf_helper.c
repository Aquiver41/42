#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>

static int	ft_hex(uintptr_t n)
{
	int		count;
	int		tmp;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		tmp = ft_hex(n / 16);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (write(1, &hex[n % 16], 1) == -1)
		return (-1);
	count++;
	return (count);
}


int	ft_putnbrunsigned(unsigned int n)
{
	int	len;
	int	value;

	len = 0;
	if (n >= 10)
	{
		value = ft_putnbrunsigned(n / 10);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (write(1, &"0123456789"[n % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_puthex_upx(unsigned int n, int type)
{
	int		count;
	int		tmp;
	char	*hex;

	count = 0;
	if (type == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		tmp = ft_puthex_upx(n / 16, type);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (write(1, &hex[n % 16], 1) == -1)
		return (-1);
	count++;
	return (count);
}

