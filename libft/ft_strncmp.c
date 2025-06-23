#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t len;

	len = 0;
	if (n == 0)
		return (0);
	while (s1 && s2 && s1[len] == s2[len] && len < n -1)
	{
		len++;
	}
	return ((unsigned char)s1[len] - (unsigned char)s2[len]);
}