/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:11:07 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/20 16:16:49 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>

void				*ft_memset(void *b, int c, unsigned int len);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_bzero(void *s, unsigned int n);
void				*ft_calloc(unsigned int count, unsigned int size);
void				*ft_memcpy(void *dest, const void *src, unsigned int n);
void				*ft_memchr(const void *s, int c, unsigned int n);
char				*ft_strdup(const char *s);
void				*ft_memmove(void *dest, const void *src, unsigned int n);
int					ft_memcmp(const void *s1, const void *s2, unsigned int n);
int					ft_atoi(const char *str);
unsigned int		ft_strlcpy(char *dst, const char *src, unsigned int size);
unsigned int		ft_strlcat(char *dst, const char *src, unsigned int size);
char				*ft_strnstr(const char *haystack, const char *needle,
						unsigned int len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
int					ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start,
						unsigned int len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strtrim(char const *s1, char const *set);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				*ft_realloc(void *ptr, size_t size, size_t old_size);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
#endif
