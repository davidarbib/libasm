/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 01:26:32 by darbib            #+#    #+#             */
/*   Updated: 2020/08/18 19:47:32 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

struct	s_list
{
	void			*data;
	struct s_list	*next;
}

int main(int ac, char **av)
{
	(void)ac;
	
	//extern void pdigit(int a);
	//extern int add_one(int a);
	//int b = add_one(14);
	//printf("b : %d\n", b);
	//extern size_t ft_strlen(const char *s);	
	//printf("strlen : %ld\n", strlen(av[1]));
	//printf("ft_strlen : %ld\n", ft_strlen(av[1]));
	//extern int	ft_strcmp(const char *s1, const char *s2);
	//printf("strcmp : %d\n", strcmp(av[1], av[2]));
	//printf("ft_strcmp : %d\n", ft_strcmp(av[1], av[2]));
	/*
	extern char *ft_strcpy(char *dest, const char *src);
	char *str = strdup(av[1]);
	char *str2 = strdup(av[1]);
	//printf("strcpy : --%s--\n", strcpy(str, av[2]));
	//printf("ft_strcpy : --%s--\n", ft_strcpy(str2, av[2]));
	strcpy(str, av[2]);
	ft_strcpy(str2, av[2]);
	printf("\n----------------------\n"); 
	write(1,str,strlen(str));
	char c = '\n';
	write(1,&c,1);
	write(1,str2,strlen(str2));
	*/
	/*
	extern char *ft_strdup(const char *s);

	char *str1 = strdup(av[1]);
	printf("strdup : --%s--\n", str1);
	char *str2 = ft_strdup(av[1]);
	printf("ft_strdup : --%s--\n", str2);
	*/
	/*
	extern ssize_t ft_read(int fd, void *buf, size_t count);
	char s[6];
	ssize_t ret = ft_read(0, s, 5);
	s[5] = 0;
	printf("ft_read ; ret : %d ; --%s--\n", (int)ret, s);
	ret = ft_read(3, s, 5);
	s[5] = 0;
	printf("ft_read ; ret : %d ; --%s--\n", (int)ret, s);
	perror("error ");
	exit(EXIT_FAILURE);
	*/
	/*
	extern ssize_t ft_write(int fd, const void *buf, size_t count);
	int ret = ft_write(4, av[1], strlen(av[1]));
	printf("ret: %d\n", ret);
	perror("error ");
	exit(EXIT_FAILURE);
	*/
	extern int ft_atoi_base(const char *s, const char *base);
	int nb = ft_atoi_base(av[1], av[2]);
	printf("my atoi --%d--\n", nb);
	int nb2 = atoi(av[1]);
	printf("true atoi : --%d--\n", nb2);
	//printf("atoi(arg) : %d\n", atoi(av[1]));
}
