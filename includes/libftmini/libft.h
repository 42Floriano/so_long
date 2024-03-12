/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:38:32 by falberti          #+#    #+#             */
/*   Updated: 2024/03/12 14:00:09 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}		t_list;

char		*get_next_line(int fd);
void		read_and_stash(int fd, t_list **stash);
void		add_to_stash(t_list **stash, char *buff, int rd);
void		extract_line(t_list *stash, char **line);
void		clean_stash(t_list **stash);
int			found_nline(t_list *stash);
t_list		*ft_lst_get_last(t_list *stash);
int			get_size_line(t_list *stash);
void		free_stash(t_list *stash);

char		*ft_strdup(const char *s1);
int			ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
void		*ft_memset(void *str, int c, unsigned int l);
char		*ft_itoa(int n);

int			ft_print_char(char c);
int			ft_print_str(char *str);
int			ft_print_int(long nb);
int			ft_printf(const char *format, ...);

#endif