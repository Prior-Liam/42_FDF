/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 12:13:23 by lprior            #+#    #+#             */
/*   Updated: 2017/09/29 16:49:29 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int x;

	x = ft_strlen(s1);
	while (*s2 != '\0')
		s1[x++] = *s2++;
	s1[x] = '\0';
	return (s1);
}
