/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strrchr.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: msinke <msinke@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/13 18:34:15 by msinke			#+#	#+#			 */
/*   Updated: 2023/10/13 18:42:35 by msinke		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if (c == 0)
		return ((char *)str + i);
	while (i != SIZE_MAX)
	{
		if (c == str[i])
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char s[] = "Tripuille";

// 	printf("%s\n", ft_strchr(s, 't' + 256));
// 	printf("original %s\n", strchr(s, 't' + 256));
// 	return (0);
// }
