/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:40:36 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/01/30 16:29:27 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*int	main(void)
{
	const char	*s;

	s = "Ay! Maria Luisa";
	printf("Funcion original: %lu\n", strlen(s));
	printf("Funcion propia:   %zu\n", ft_strlen(s));
	return (0);
}*/
