#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sourc;
	size_t			i;

	dest = (unsigned char *)dst;
	sourc = (unsigned char *)src;
	i = 0;
	if (dest == NULL && sourc == NULL)
		return (NULL);
	while (i < n)
	{
		dest[i] = sourc[i];
		i++;
	}
	return (dst);
}