#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
  unsigned char *d; // void * idi yani türü belirtilmemişti artık char oldu.byte(8bit) türünde
  const unsigned char *s; // ayn şekilde fakat const(sabit değer) yani değiştirilemez.byte türünde

  	if (!dst || !src) //dst veya src yoksa null döndür. bitir.
			return (NULL);
	d = (unsigned char *)dst; //void * idi byte işleyebilecek hale getiriyoruz.
	s = (const unsigned char *)src; // aynısı
	if (d < s) //eğer dst, src'den önce geliyorsa yani hafızada daha düşük bir adreste ise
	// bu durumda memmove işlemi normal bir şekilde ilerleyebilir.
	{
		while (len--) //len sıfır olana kadar devam et
		{
			*d++ = *s++; //dst'ye src'den gelen veriyi kopyala. d ve s'yi bir sonraki byte'a ilerlet.
		}
	}
	else
	{
		d+= len; //her iki işaretçiyi de sona kadar ilerlet.bir sonraki byte'a ilerlet.
		s+= len; 
		while ( len--)
		{
			*--d = *--s; //dst'ye src'den gelen veriyi kopyala ama bu sefer sondan başa doğru ilerle
		}
	}
	return (dst);
}

// 100 101 102
//  a   b   c

/*
	d+ = len => 100 + 3 = 103
	len-- olup girdiğinde kopyalamaya 102 de itibaren başlar.


*/
#include <stdio.h>
int main() {
	char src[] = "Hello, World!";
	char dst[50];

	printf("Before memmove: %s\n", dst);
	ft_memmove(dst, src, 13);
	printf("After memmove: %s\n", dst);

	// Test overlapping regions
	char overlap[] = "1234567890";
	printf("Before overlapping memmove: %s\n", overlap);
	ft_memmove(overlap + 2, overlap, 8); // Move "12345678" to "34567890"
	printf("After overlapping memmove: %s\n", overlap);

	return 0;
}