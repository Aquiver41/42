#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	len;

	len = 0;
	while ( len < n )
	{
		if (((unsigned char *)s)[len] == (unsigned char)c)
			return ((void *)(s + len));
		len++;
	}
	return (0);
}


	/*char str[] = "Hello, world!";
	char *result;

	result = ft_memchr(str, 'o', 5);
	if (result)
		printf("Found character 'o': %s\n", result);
	else
		printf("Character 'o' not found in the first 5 characters.\n");

	result = ft_memchr(str, 'x', 5);
	if (result)
		printf("Found character 'x': %s\n", result);
	else
		printf("Character 'x' not found in the first 5 characters.\n");

	return 0;
	*/#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = { -1, 0, 1, 2 };
    void *ptr = memchr(str, -1, 4);  // ❌ Hata: -1 signed ama memchr unsigned bekliyor

    if (ptr)
        printf("Bulundu\n");
    else
        printf("Bulunamadı\n");  // ✅ Çoğu zaman bu çalışır ama yanlış nedenlerle

    return 0;
}



// 	free(dizi[i]);