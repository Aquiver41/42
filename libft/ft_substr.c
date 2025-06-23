#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	j;

	if (!s)
		return (NULL); 

	j = ft_strlen(s);
	if (start >= j)
		return (ft_strdup(""));

	if (len > j - start)
		len = j - start;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);

	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';

	return (str);
}
