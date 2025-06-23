#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t src_len;
	size_t i;
	if (!dst && !src)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len) //Eğer size, dst'nin uzunluğundan küçükse src’den hiçbir şey kopyalanmaz.
                         //Sadece toplamda ne kadar yer gerekirdi onu döner: size + src_len
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i < size - 1)) // NULL için -1
	{	dst[dst_len + i] = src[i];
		i++;	
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}