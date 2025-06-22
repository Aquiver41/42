#include "libft.h"
#include <stdlib.h>

// Sayının uzunluğunu (basamak sayısı + negatif işareti) hesaplar
static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char *ft_itoa(int n)
{
    int len = ft_intlen(n);
    char *str = (char *)malloc(sizeof(char) * (len + 1)); // +1 for '\0'
    long num = n; // int'in sınırlarını aşmamak için long kullan
    if (!str)
        return NULL;

    str[len] = '\0'; // Null terminator . sonuna null atarak başlar

    if (num == 0)
        str[0] = '0';

    if (num < 0)
    {
        str[0] = '-';
        num = -num;
    }

    while (num > 0)
    {
        str[--len] = (num % 10) + '0'; // nulldan önceki basamağı alır ve karaktere çevirir.
        num /= 10;
    }

    return str;
}

#include <stdio.h>

int main()
{
	int a = -234;
	ft_itoa(a);
	printf("a: %s\n", ft_itoa(a));
}