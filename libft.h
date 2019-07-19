/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:26:28 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/18 16:53:34 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h> //testing

#define BASE_DIGITS "0123456789abcdef"
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src,
		int c, size_t size);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *str, int c);
void				ft_strclr(char *s);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **str);
char				*ft_strdup(const char *s);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(char const *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack,
		const char *needle, size_t n);
char				*ft_strrchr(const char *str, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(char const *thehaystack, char const *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_isupper(int c);
int					ft_islower(int c);
void				ft_strrev(char *s);
void				ft_chrswap(char *c, char *c2);
size_t				ft_strclen(char const *s, char c);
size_t				ft_word_count(char const *s, char delimiter);

/*
 * *	type/base conversions to a
 */
char				*ft_shorttoa_base(short n, int base);
char				*ft_longlongtoa_base(long long n, int base);
char				*ft_itoa_base(int n, int base);
char				*ft_unsignedlltoa_base(unsigned long long n, int base);

/*
 * *				trashcan
 */

#define DEFAULT_TRASH_SIZE 100
typedef enum
{
	T_CHAR,
	T_INT,
	T_FLOAT
}						e_my_type;

typedef struct			s_trash
{
	e_my_type			type;
	union
	{
		char			*cp;
		int				*ip;
		float			*fp;
	}					u_piece;
}						t_rash;

typedef struct			s_trashcan
{
	t_rash				can[DEFAULT_TRASH_SIZE];
	int					top;
}						t_rash_can;

void					new_trash_bag(t_rash_can *my_trashcan);
void					mom(t_rash_can *my_trashcan, e_my_type tp, ...);
int						trash_overflow(t_rash_can *my_trashcan);
int						trashcan_empty(t_rash_can *my_trashcan);
void					garbage_day(t_rash_can *my_trashcan);

/*
 * *				special strings
 */

typedef struct			s_string
{
	int					len;
	char				*str;
}						t_string;

t_string				*t_string_join(t_string string_one, t_string string_two);
void					print_t_string(t_string *result);


/*
 * *				ft_printf
 */
#define TABLE_LEN 11
#define NUM_H_FLAGS 5
#define NUM_L_FLAGS 3
#define H_FLAGS " #0-+"
#define L_FLAGS "hlL"

typedef struct			s_flags
{
	char				h_flag[NUM_H_FLAGS];
	int					min_width;
	int					precision;
	char				l_flag[3]; //changed from 2 to 3
	char				arg_type;
}						t_flag;


typedef struct          s_dispatch_funcs
{
    const char          key;
    int                 (*func)(t_flag,va_list , t_string**);
}                       t_dispatch_funcs;

typedef struct          s_dispatch_table
{
    t_dispatch_funcs    table[TABLE_LEN];
}                       t_dispatch_table;

int						ft_printf(const char *format, ...);

typedef struct			s_package
{
	t_flag				flag;
	t_string			*string;
	t_rash_can			trash;
	t_string			*mws; //min_width_str
	t_string			sign;
}						t_package;

//parsing
const char				*parse_no_key(const char *format, t_string **result);
const char 				*parse_key(const char *format, t_string **result, t_dispatch_table dispatch, va_list list);
void					init_t_flag(t_flag *flags);
const char				*set_h_flags(const char *format, t_flag *flags);
const char				*set_min_width(const char *format, t_flag *flags);
const char				*set_precision(const char *format, t_flag *flags);
const char				*set_l_flags(const char *formatt, t_flag *flags);
const char				*set_arg_type(const char *format, t_flag *flags, int *code, t_dispatch_table dispatch);
void					result_watcher(t_string **watch, t_string *result, t_rash_can *my_trashcan);

//s flag functs
int						s(t_flag flags, va_list list, t_string **result);
void					str_precision(t_flag *flags, t_string **string, t_rash_can *my_trashcan);
void					str_min_width(t_flag *flags, t_string **string, t_rash_can *my_trashcan);

//c flag functs
int						c(t_flag flags, va_list list, t_string **result);
void					c_min_width(t_flag flags, t_string **string, t_rash_can *my_trashcan);

//p flag functs
int						p(t_flag flags, va_list list, t_string **result);
void					p_min_width(t_flag *flags, t_string **string, t_rash_can *my_trashcan);
void					helper(t_flag *flags, t_string **string, t_rash_can *my_trashcan, t_string *newstr);
size_t					pointer_length(unsigned long long number);
char					*convert_pointer(unsigned long long pointer);

//percent functs
int						percent(t_flag flags, va_list list, t_string **result);

//d and i functs
int						d(t_flag flags, va_list list, t_string **result);
void					d_adjust_precision(t_package *package);
void					d_formatter(t_package *package);
void					d_sign(t_package *package);
void					d_min_width(t_package *package);
void					dhelper(t_package *package);
//o functs
int						o(t_flag flags, va_list list, t_string **result);
void					o_formatter(t_package *package);
void					o_adjust_precision(t_package *package);

//u functs
int						u(t_flag flags, va_list list, t_string **result);

//x functs
int						x(t_flag flags, va_list list, t_string **result);
void					x_formatter(t_package *package);
void					hex_prefix(t_package *package);

//X functs 
int						X(t_flag flags, va_list list, t_string **result);
void					capital(t_package *package);

//flags yet to be done
int						f(t_flag flags, va_list list, t_string **result);

//utils and test functs
void					print_flags(t_flag *flags);
int						contains(char c, char *str, int len);
int						str_num_len(const char *format);








#define _s { 's', &s }
#define _c { 'c', &c }
#define _p { 'p', &p }
#define _d { 'd', &d }
#define _i { 'i', &d }
#define _o { 'o', &o }
#define _u { 'u', &u }
#define _x { 'x', &x }
#define _X { 'X', &X }
#define _f { 'f', &f }
#define _pc { '%', &percent }

#define FUNCS { _s, _c, _p, _d, _i, _o, _u, _x, _X, _f, _pc}
#define INIT_TABLE(x) t_dispatch_table x = { FUNCS }

#endif
