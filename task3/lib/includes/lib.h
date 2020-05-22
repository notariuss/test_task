#ifndef LIB_H
# define LIB_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "mprintf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*my_memset(void *b, int c, size_t len);
void				*my_bzero(void *s, size_t n);
void				*my_memcpy(void *restrict dst, const void *restrict src,
		size_t n);
void				*my_memccpy(void *restrict dst, const void *restrict src,
		int c,
		size_t n);
void				*my_memmove(void *dst, const void *src, size_t len);
void				*my_memchr(const void *s, int c, size_t n);
int					my_memcmp(const void *s1, const void *s2, size_t n);
size_t				my_strlen(const char *s);
char				*my_strdup(const char *s1);
char				*my_strcpy(char *dst, const char *src);
char				*my_strncpy(char *dst, const char *src, size_t len);
char				*my_strcat(char *restrict s1, const char *restrict s2);
char				*my_strncat(char *restrict dest, const char *restrict src,
		size_t n);
size_t				my_strlcat(char *restrict dst, const char *restrict src,
		size_t dstsize);
char				*my_strchr(const char *s, int c);
char				*my_strrchr(const char *s, int c);
char				*my_strstr(const char *haystack, const char *needle);
char				*my_strnstr(const char *haystack, const char *needle,
		size_t len);
int					my_strcmp(const char *s1, const char *s2);
int					my_strncmp(const char *s1, const char *s2, size_t n);
int					my_atoi(const char *str);
int					my_isalpha(int c);
int					my_isdigit(int c);
int					my_isalnum(int c);
int					my_isascii(int c);
int					my_isprint(int c);
int					my_toupper(int c);
int					my_tolower(int c);
void				*my_memalloc(size_t size);
void				my_memdel(void **ap);
char				*my_strnew(size_t size);
void				my_strdel(char **as);
void				my_strclr(char *s);
void				my_striter(char *s, void (*f)(char *));
void				my_striteri(char *s, void (*f)(unsigned int, char *));
char				*my_strmap(char const *s, char (*f)(char));
char				*my_strmapi(char const *s, char (*f)(unsigned int, char));
int					my_strequ(char const *s1, char const *s2);
int					my_strnequ(char const *s1, char const *s2, size_t n);
char				*my_strsub(char const *s, unsigned int start, size_t len);
char				*my_strjoin(char const *s1, char const *s2);
char				*my_strjoin(char const *s1, char const *s2);
char				*my_strtrim(char const *s);
char				**my_strsplit(char const *s, char c);
char				*my_itoa(int n);
void				my_putchar(char c);
void				my_putstr(char const *str);
void				my_putendl(char const *s);
void				my_putnbr(int n);
void				my_putchar_fd(char c, int fd);
void				my_putstr_fd(char const *s, int fd);
void				my_putendl_fd(char const *s, int fd);
void				my_putnbr_fd(int n, int fd);
t_list				*my_lstnew(void const *content, size_t content_size);
void				my_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				my_lstdel(t_list **alst, void (*del)(void *, size_t));
void				my_lstadd(t_list **alst, t_list *new);
void				my_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*my_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
long int			my_nbrlen(long long int n);
char				*my_itoa_base(int nbr, char const *base_str);
void				my_strrev(char *str);
void				my_free_tab(char **tab);
void				my_ptr_swap(void **p1, void **p2);
void				my_puterr(int n, char *str, ...);
#endif
