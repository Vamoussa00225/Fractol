/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:27:24 by vkanate           #+#    #+#             */
/*   Updated: 2022/03/28 22:49:53 by vkanate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s1_replace;
	unsigned char	*s2_replace;

	i = 0;
	s1_replace = (unsigned char *)s1;
	s2_replace = (unsigned char *)s2;
	while (s1_replace[i] != '\0' && s2_replace[i] != '\0'
		&& s1_replace[i] == s2_replace[i])
	{
		i++;
	}
	if (s1_replace[i] != s2_replace[i])
		return (0);
	return (1);
}
