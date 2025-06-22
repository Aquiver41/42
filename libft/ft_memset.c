#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b2;

	b2 = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b2[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

#include <stdio.h>
int main() {
	char str[50] = "Hello, World!";
	printf("Before memset: %s\n", str);
	ft_memset(str, '*', 5);
	printf("After memset: %s\n", str);
	return 0;
}
