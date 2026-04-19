/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ilbouidd <marvin@42.fr>                    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/11/10 11:20:26 by ilbouidd          #+#    #+#             */
/*   Updated: 2025/11/10 11:20:26 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <bsd/string.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/*TOUT LES VOID*/
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/*TOUT LES INT*/
int		ft_atoi(const char *nptr);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*TOUT LES CHAR */
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);

/*TOUT LES SIZE_T*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t siz);
size_t	ft_strlen(const char *s);

/*TOUT LES LONG*/
long	ft_atol(const char *nptr);
/*BONUS*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*PRINTF*/
int		ft_printf(const char *str, ...);
int		print_c(int s);
int		print_s(char *s);
int		print_int(int n);
int		print_u(unsigned int n);
int		print_pourcent(void);
int		print_x(unsigned int n, const char format);
int		lenhexa(unsigned int n);
int		print_p(void *ptr);
int		write_pf(char s, int fd);
void	puthexa(unsigned int n, const char logo);

/*GET_NEXT_LINE*/
size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(const char *s1, const char *s2);
char	*ft_strdup_gnl(const char *s1);
char	*get_next_line(int fd);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
void	*ft_free_stock(char **str, int copy_line);

#endif
