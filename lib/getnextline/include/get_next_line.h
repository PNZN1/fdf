/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/19 15:55:14 by pniezen       #+#    #+#                 */
/*   Updated: 2022/04/12 11:59:19 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*free_null(char *str);
void	*ft_calloc(size_t count, size_t size);
int		check_new_line(char *storage);
char	*realloc_and_join(char *storage, char *buff);
size_t	get_ft_strlen(const char *s);

#endif
