#include <stdlib.h>

static int	word_count(const char *s, char c)
{
	int count = 0;
	int in_word = 0;

	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(const char *start, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	int		i = 0;
	int		start = 0;
	int		end = 0;
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!result)
		return (NULL);
	while (s[end])
	{
		if (s[end] != c)
		{
			start = end;
			while (s[end] && s[end] != c)
				end++;
			result[i++] = word_dup(s + start, end - start);
		}
		else
			end++;
	}
	result[i] = NULL;
	return (result);
}


#include <stdio.h>

int main(void)
{
	char **dizi = ft_split("  ", ' ');
	for (int i = 0; dizi[i]; i++)
		printf("Kelime %d: %s\n", i, dizi[i]);
}