/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 01:26:32 by darbib            #+#    #+#             */
/*   Updated: 2020/08/24 00:13:44 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

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

void test_strlen()
{
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
	printf(FONT_BLUE "Test_1_4 (SEGV) : \n" FONT_RESET);
	test_s = NULL;
	//printf("strlen of |%s| : %ld\n", test_s, strlen(test_s));
	printf("ft_strlen of |%s| : %ld\n", test_s, ft_strlen(test_s));
	printf("\n");
}

void test_strcmp()
{
	printf(FONT_BOLDYELLOW "-----------------ft_strcmp-----------------\n" FONT_RESET);
	extern int	ft_strcmp(const char *s1, const char *s2);
	printf(FONT_BLUE "Test_2_1 : \n" FONT_RESET);
	char *test_s = "";
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
	printf(FONT_BLUE "Test_2_13 (SEGV) : \n" FONT_RESET);
	test_s = NULL;
	test_s2 = strdup("aba");
	//printf("strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, strcmp(test_s, test_s2));
	printf("ft_strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, ft_strcmp(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_2_14 (SEGV) : \n" FONT_RESET);
	test_s = strdup("aaa");
	test_s2 = NULL;
	//printf("strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, strcmp(test_s, test_s2));
	printf("ft_strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, ft_strcmp(test_s, test_s2));
	printf("\n");
	printf(FONT_BLUE "Test_2_15 (SEGV) : \n" FONT_RESET);
	test_s = NULL;
	test_s2 = NULL;
	//printf("strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, strcmp(test_s, test_s2));
	printf("ft_strcmp(|%s|, |%s|) : %d\n", test_s, test_s2, ft_strcmp(test_s, test_s2));
	printf("\n");
}

void test_strcpy()
{
	printf(FONT_BOLDYELLOW "-----------------ft_strcpy-----------------\n" FONT_RESET);
	extern char *ft_strcpy(char *dest, const char *src);
	printf(FONT_BLUE "Test_4_1 : \n" FONT_RESET);
	char *test_s = strdup("");
	char *test_s2 = strdup("");
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
	printf("ft_strcpy(|%s|, |%s|) : ", test_s, test_s2);
	printf("|%s|\n", ft_strcpy(test_s, test_s2));
	printf("\n");
}

void test_strdup()
{
	printf(FONT_BOLDYELLOW "-----------------ft_strdup-----------------\n" FONT_RESET);
	extern char *ft_strdup(const char *s);
	printf(FONT_BLUE "Test_3_1 : \n" FONT_RESET);
	char *test_s = strdup("");
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
	printf(FONT_BLUE "Test_3_4 (SEGV) : \n" FONT_RESET);
	test_s = NULL;
	//printf("strdup(|%s|) : |%s|\n", test_s, strdup(test_s));
	printf("ft_strdup(|%s|) : |%s|\n", test_s, ft_strdup(test_s));
	printf("\n");
}

void test_write()
{
	printf(FONT_BOLDYELLOW "-----------------ft_write-----------------\n" FONT_RESET);
	extern ssize_t ft_write(int fd, const void *buf, size_t count);
	printf(FONT_BLUE "Test_5_1 : \n" FONT_RESET);
	char *test_s = strdup("");
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
	printf("\n");
	printf(FONT_BLUE "Test_5_3 : \n" FONT_RESET);
	test_s = strdup("test\n");
	fd = 1;
	size_t len = 3;
	printf("write(%d, |%s|, %ld) :\n", fd, test_s, len);
	printf("ret : %ld\n", write(fd, test_s, len));
	printf("ft_write(%d, |%s|, %ld) :\n", fd, test_s, len);
	printf("ret : %ld\n", ft_write(fd, test_s, len));
	printf("\n");
	printf(FONT_BLUE "Test_5_4 : \n" FONT_RESET);
	test_s = strdup("test\n");
	fd = 8;
	len = 3;
	printf("write(%d, |%s|, %ld) :\n", fd, test_s, len);
	printf("ret : %ld\n", write(fd, test_s, len));
	perror(FONT_BOLDRED "Error" FONT_RESET);
	printf("ft_write(%d, |%s|, %ld) :\n", fd, test_s, len);
	printf("ret : %ld\n", ft_write(fd, test_s, len));
	perror(FONT_BOLDRED "Error" FONT_RESET);
	printf("\n");
	printf(FONT_BLUE "Test_5_5(SEGV) : \n" FONT_RESET);
	test_s = NULL;
	fd = 8;
	len = 3;
	printf("write(%d, |%s|, %ld) :\n", fd, test_s, len);
	printf("ret : %ld\n", write(fd, test_s, len));
	printf("ft_write(%d, |%s|, %ld) :\n", fd, test_s, len);
	printf("ret : %ld\n", ft_write(fd, test_s, len));
}

void test_read()
{
	printf(FONT_BOLDYELLOW "-----------------ft_read-----------------\n" FONT_RESET);
	int fd = open("test_read.txt", O_RDONLY);
	extern ssize_t ft_read(int fd, const void *buf, size_t count);
	printf(FONT_BLUE "Test_6_1 : \n" FONT_RESET);
	char *test_s = strdup("");
	fd = open("test_read.txt", O_RDONLY);
	printf("read(%d, |%s|, %ld) :\n", fd, test_s, strlen(test_s));
	printf("ret : %ld\n", read(fd, test_s, strlen(test_s)));
	printf("test_s after read : |%s|\n", test_s);
	close(fd);
	fd = open("test_read.txt", O_RDONLY);
	printf("ft_read(%d, |%s|, %ld) :\n", fd, test_s, strlen(test_s));
	printf("ret : %ld\n", ft_read(fd, test_s, strlen(test_s)));
	printf("test_s after ft_read : |%s|\n", test_s);
	close(fd);
	printf("\n");
	printf(FONT_BLUE "Test_6_2 : \n" FONT_RESET);
	test_s = strdup("buffer");
	fd = open("test_read.txt", O_RDONLY);
	printf("read(%d, |%s|, %ld) :\n", fd, test_s, strlen(test_s));
	printf("ret : %ld\n", read(fd, test_s, strlen(test_s)));
	printf("test_s after read : |%s|\n", test_s);
	close(fd);
	test_s = strdup("buffer");
	fd = open("test_read.txt", O_RDONLY);
	printf("ft_read(%d, |%s|, %ld) :\n", fd, test_s, strlen(test_s));
	printf("ret : %ld\n", ft_read(fd, test_s, strlen(test_s)));
	printf("test_s after ft_read : |%s|\n", test_s);
	close(fd);
	printf("\n");
	printf(FONT_BLUE "Test_6_3 : \n" FONT_RESET);
	test_s = strdup("buffer");
	size_t len = 3;
	fd = open("test_read.txt", O_RDONLY);
	printf("read(%d, |%s|, %ld) :\n", fd, test_s, len);
	printf("ret : %ld\n", read(fd, test_s, len));
	printf("test_s after read : |%s|\n", test_s);
	close(fd);
	test_s = strdup("buffer");
	fd = open("test_read.txt", O_RDONLY);
	printf("ft_read(%d, |%s|, %ld) :\n", fd, test_s, len);
	printf("ret : %ld\n", ft_read(fd, test_s, len));
	printf("test_s after ft_read : |%s|\n", test_s);
	close(fd);
	printf("\n");
	printf(FONT_BLUE "Test_6_4 : \n" FONT_RESET);
	test_s = strdup("buffer");
	fd = 8;
	len = 3;
	printf("read(%d, |%s|, %ld) :\n", fd, test_s, len);
	printf("ret : %ld\n", read(fd, test_s, len));
	printf("test_s after read : %s\n", test_s);
	perror(FONT_BOLDRED "Error" FONT_RESET);
	test_s = strdup("buffer");
	printf("ft_read(%d, |%s|, %ld) :\n", fd, test_s, len);
	printf("ret : %ld\n", ft_read(fd, test_s, len));
	printf("test_s after ft_read : |%s|\n", test_s);
	perror(FONT_BOLDRED "Error" FONT_RESET);
	printf("\n");
	printf(FONT_BLUE "Test_6_5(SEGV) : \n" FONT_RESET);
	test_s = NULL;
	fd = 8;
	len = 3;
	printf("read(%d, |%s|, %ld) :\n", fd, test_s, len);
	printf("ret : %ld\n", read(fd, test_s, len));
	printf("ft_read(%d, |%s|, %ld) :\n", fd, test_s, len);
	printf("ret : %ld\n", ft_read(fd, test_s, len));
}

int main()
{
	test_strlen();
	test_strcmp();
	test_strcpy();
	test_strdup();
	test_write();
	test_read();
	return (0);
}
