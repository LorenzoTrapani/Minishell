/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:05:40 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/29 14:14:26 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**mtx_alloc(int rows, int cols)
{
	int		i;
	char	**mtx;

	i = 0;
	mtx = ft_calloc(rows, sizeof(char *));
	if (!mtx)
		ft_printf(2, "Error during row allocation.\n");
	while (i < rows)
	{
		mtx[i] = ft_calloc(cols, sizeof(char));
		if (!mtx[i])
			ft_printf(2, "Error during col allocation.\n");
		i++;
	}
	return (mtx);
}

char	**copy_mtx(char **mtx)
{
	char	**res;
	int		rows;

	rows = -1;
	res = ft_calloc(count_rows(mtx), sizeof(char *));
	while (mtx[++rows])
		res[rows] = ft_strdup(mtx[rows]);
	return (res);
}

void	free_mtx(char **mtx)
{
	int	i;
	int	len;

	if (!mtx)
		return ;
	len = count_rows(mtx);
	i = 0;
	while (i < len)
	{
		free(mtx[i]);
		mtx[i] = NULL;
		i++;
	}
	free(mtx);
}
