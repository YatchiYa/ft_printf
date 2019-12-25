#include "../includes/ft_printf.h"

char	*ft_strdup(const	char *s)
{
		char	*str;
			int		i;

				i = 0;
					str = (char*)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
						if (str == NULL)
									return (NULL);
							while (s[i] != '\0')
									{
												str[i] = s[i];
														i++;
															}
								str[i] = '\0';
									return (str);
}
