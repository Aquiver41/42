#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	j = ft_strlen(s2);
	i = ft_strlen(s1);
	s3 = (char *)malloc(i + j + 1);
	if (s3 == NULL)
		return (NULL);
	ft_memcpy(s3, s1, i);
	ft_memcpy(s3 + i, s2, j);
	s3[i + j] = '\0';
	return (s3);
}