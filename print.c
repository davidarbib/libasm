/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 01:26:32 by darbib            #+#    #+#             */
/*   Updated: 2020/08/22 03:00:14 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

# define FONT_RED     		"\x1b[31m"
# define FONT_BOLDRED 		"\x1b[1;31m"
# define FONT_RED8			"\x1b[38;5;1m\x1b[48;5;7m"
# define FONT_GREEN   		"\x1b[32m"
# define FONT_BOLDGREEN 	"\x1b[1;32m"
# define FONT_YELLOW  		"\x1b[33m"
# define FONT_BOLDYELLOW	"\x1b[1;33m"
# define FONT_BLUE    		"\x1b[34m"
# define FONT_MAGENTA 		"\x1b[35m"
# define FONT_CYAN    		"\x1b[36m"
# define FONT_RESET   		"\x1b[0m"

int main(int ac, char **av)
{
	(void)ac;
	
	printf(FONT_BOLDYELLOW "-----------------ft_strlen-----------------\n" FONT_RESET);
	extern size_t ft_strlen(const char *s);	
	printf(FONT_BLUE "Test_1_1 : \n" FONT_RESET);
	char *test_s = "42";
	printf("strlen of |%s| : %ld\n", test_s, strlen(test_s));
	printf("ft_strlen of |%s| : %ld\n", test_s, ft_strlen(test_s));
	printf("\n");
	printf(FONT_BLUE "Test_1_2 : \n" FONT_RESET);
	test_s = "";
	printf("strlen of |%s| : %ld\n", test_s, strlen(test_s));
	printf("ft_strlen of |%s| : %ld\n", test_s, ft_strlen(test_s));
	printf("\n");
	printf(FONT_BLUE "Test_1_3 : \n" FONT_RESET);
	test_s = "vlsdjvklksjdvlksjdvlkd vlvkjdlskjdpoijs  jk;fk lkdj";
	printf("strlen of |%s| : %ld\n", test_s, strlen(test_s));
	printf("ft_strlen of |%s| : %ld\n", test_s, ft_strlen(test_s));
	printf("\n");
	printf(FONT_BOLDYELLOW "-----------------ft_strcmp-----------------\n" FONT_RESET);
	extern int	ft_strcmp(const char *s1, const char *s2);
	printf(FONT_BLUE "Test_2_1 : \n" FONT_RESET);
	test_s = "";
	char *test_s2 = "";
	printf("strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, strcmp(test_s, test_s2));
	printf("ft_strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, ft_strcmp(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_2_2 : \n" FONT_RESET);
	test_s = strdup("a");
	test_s2 = strdup("b");
	printf("strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, strcmp(test_s, test_s2));
	printf("ft_strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, ft_strcmp(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_2_3 : \n" FONT_RESET);
	test_s = strdup("b");
	test_s2 = strdup("a");
	printf("strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, strcmp(test_s, test_s2));
	printf("ft_strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, ft_strcmp(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_2_4 : \n" FONT_RESET);
	test_s = strdup("a");
	test_s2 = strdup("a");
	printf("strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, strcmp(test_s, test_s2));
	printf("ft_strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, ft_strcmp(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_2_5 : \n" FONT_RESET);
	test_s = strdup("");
	test_s2 = strdup("a");
	printf("strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, strcmp(test_s, test_s2));
	printf("ft_strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, ft_strcmp(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_2_6 : \n" FONT_RESET);
	test_s = strdup("a");
	test_s2 = strdup("");
	printf("strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, strcmp(test_s, test_s2));
	printf("ft_strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, ft_strcmp(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_2_7 : \n" FONT_RESET);
	test_s = strdup("aaa");
	test_s2 = strdup("aaA");
	printf("strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, strcmp(test_s, test_s2));
	printf("ft_strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, ft_strcmp(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_2_8 : \n" FONT_RESET);
	test_s = strdup("aaA");
	test_s2 = strdup("aaa");
	printf("strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, strcmp(test_s, test_s2));
	printf("ft_strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, ft_strcmp(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_2_9 : \n" FONT_RESET);
	test_s = strdup("aaA");
	test_s2 = strdup("baa");
	printf("strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, strcmp(test_s, test_s2));
	printf("ft_strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, ft_strcmp(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_2_10 : \n" FONT_RESET);
	test_s = strdup("baA");
	test_s2 = strdup("aaa");
	printf("strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, strcmp(test_s, test_s2));
	printf("ft_strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, ft_strcmp(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_2_11 : \n" FONT_RESET);
	test_s = strdup("abA");
	test_s2 = strdup("aaa");
	printf("strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, strcmp(test_s, test_s2));
	printf("ft_strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, ft_strcmp(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_2_12 : \n" FONT_RESET);
	test_s = strdup("aaA");
	test_s2 = strdup("aba");
	printf("strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, strcmp(test_s, test_s2));
	printf("ft_strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, ft_strcmp(test_s, test_s2));
	printf("\n");
	printf(FONT_BOLDYELLOW "-----------------ft_strdup-----------------\n" FONT_RESET);
	extern char *ft_strdup(const char *s);
	printf(FONT_BLUE "Test_3_1 : \n" FONT_RESET);
	test_s = strdup("");
	printf("strdup(|%s|) : |%s|\n", test_s, strdup(test_s));
	printf("ft_strdup(|%s|) : |%s|\n", test_s, ft_strdup(test_s));
	printf("\n");
	printf(FONT_BLUE "Test_3_2 : \n" FONT_RESET);
	test_s = strdup("test");
	printf("strdup(|%s|) : |%s|\n", test_s, strdup(test_s));
	printf("ft_strdup(|%s|) : |%s|\n", test_s, ft_strdup(test_s));
	printf("\n");
	printf(FONT_BLUE "Test_3_3 : \n" FONT_RESET);
	test_s = strdup("994059-309450843        **   954894 kfg;d     kd");
	printf("strdup(|%s|) : |%s|\n", test_s, strdup(test_s));
	printf("ft_strdup(|%s|) : |%s|\n", test_s, ft_strdup(test_s));
	printf("\n");
	printf(FONT_BOLDYELLOW "-----------------ft_strcpy-----------------\n" FONT_RESET);
	extern char *ft_strcpy(char *dest, const char *src);
	printf(FONT_BLUE "Test_4_1 : \n" FONT_RESET);
	test_s = strdup("");
	test_s2 = strdup("");
	printf("strcpy(|%s|, |%s|) : |%s|\n", test_s, test_s2, strcpy(test_s, test_s2));
	printf("ft_strcpy(|%s|, |%s|) : |%s|\n", test_s, test_s2, ft_strcpy(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_4_2 : \n" FONT_RESET);
	test_s = strdup("");
	test_s2 = strdup("fldkj;lkfd");
	printf("strcpy(|%s|, |%s|) : ", test_s, test_s2);
	printf("|%s|\n", strcpy(test_s, test_s2));
	test_s = strdup("");
	test_s2 = strdup("fldkj;lkfd");
	printf("ft_strcpy(|%s|, |%s|) : ", test_s, test_s2);
	printf("|%s|\n", ft_strcpy(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_4_3 : \n" FONT_RESET);
	test_s = strdup("test");
	test_s2 = strdup("ok");
	printf("strcpy(|%s|, |%s|) : ", test_s, test_s2);
	printf("|%s|\n", strcpy(test_s, test_s2));
	test_s = strdup("test");
	test_s2 = strdup("ok");
	printf("ft_strcpy(|%s|, |%s|) : ", test_s, test_s2);
	printf("|%s|\n", ft_strcpy(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_4_4 : \n" FONT_RESET);
	test_s = strdup("ok");
	test_s2 = strdup("test");
	printf("strcpy(|%s|, |%s|) : ", test_s, test_s2);
	printf("|%s|\n", strcpy(test_s, test_s2));
	test_s = strdup("ok");
	test_s2 = strdup("test");
	printf("ft_strcpy(|%s|, |%s|) : ", test_s, test_s2);
	printf("|%s|\n", ft_strcpy(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_4_SEGV : \n" FONT_RESET);
	test_s = NULL;
	test_s2 = strdup("test");
	//printf("strcpy(|%s|, |%s|) : ", test_s, test_s2);
	//printf("|%s|\n", strcpy(test_s, test_s2));
	//printf("ft_strcpy(|%s|, |%s|) : ", test_s, test_s2);
	printf("|%s|\n", ft_strcpy(test_s, test_s2));
	printf("\n");
	printf(FONT_BOLDYELLOW "-----------------ft_write-----------------\n" FONT_RESET);
	extern ssize_t ft_write(int fd, const void *buf, size_t count);
	printf(FONT_BLUE "Test_5_1 : \n" FONT_RESET);
	test_s = strdup("");
	int fd = 1;
	printf("write(%d, |%s|, %ld) :\n", fd, test_s, strlen(test_s));
	printf("ret : %ld\n", write(fd, test_s, strlen(test_s)));
	printf("ft_write(%d, |%s|, %ld) :\n", fd, test_s, strlen(test_s));
	printf("ret : %ld\n", ft_write(fd, test_s, strlen(test_s)));
	printf("\n");
	printf(FONT_BLUE "Test_5_2 : \n" FONT_RESET);
	test_s = strdup("test\n");
	fd = 1;
	printf("write(%d, |%s|, %ld) :\n", fd, test_s, strlen(test_s));
	printf("ret : %ld\n", write(fd, test_s, strlen(test_s)));
	printf("ft_write(%d, |%s|, %ld) :\n", fd, test_s, strlen(test_s));
	printf("ret : %ld\n", ft_write(fd, test_s, strlen(test_s)));
	//printf("strcpy : --%s--\n", strcpy(str, av[2]));
	//printf("ft_strcpy : --%s--\n", ft_strcpy(str2, av[2]));
	/*
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
	char *test_str = "ok\n";
	int ret = ft_write(4, test_str, strlen(test_str));
	printf("ret: %d\n", ret);
	perror("error ");
	exit(EXIT_FAILURE);
	*/
}
