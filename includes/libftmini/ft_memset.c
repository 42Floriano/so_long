/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:32:40 by falberti          #+#    #+#             */
/*   Updated: 2023/10/30 12:39:58 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, unsigned int l)
{
	unsigned char	*t;

	t = str;
	while (l > 0)
	{
		*t = c;
		t++;
		l--;
	}
	return (str);
}

/*int	main(void)
{
	char test[10];

	ft_memset(test, 'a', 5);
	
	int i = 0;
	while (i < 5)
	{
		printf("%c", test[i]);
		i++;
	}
	return (0);
}*/