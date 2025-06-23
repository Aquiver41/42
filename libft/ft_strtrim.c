#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new;

	if (!s1 || !set )
		return 0;
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1); // sondan başlamak için 
	while (end > start && ft_strchr(set ,s1[end - 1]))
		end--;
	new = (char *)malloc(sizeof(char) * (end - start + 1)); // end - start : yeni uzunluk
	if (!new)
	return 0;
	ft_strlcpy(new, s1 + start, end - start + 1); // (kopyalanacak dizi , yeni stringin başı[yani pointer, s1 in tututğu pointerın start fazlası] , max boyut)
	return (new);
}