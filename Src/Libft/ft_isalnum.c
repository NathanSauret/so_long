/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:52:08 by nsauret           #+#    #+#             */
/*   Updated: 2024/05/30 13:59:58 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c >= 'a' && c <= 'z')
		return (8);
	else if (c >= 'A' && c <= 'Z')
		return (8);
	else if (c >= '0' && c <= '9')
		return (8);
	return (0);
}
