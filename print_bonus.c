/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 01:26:32 by darbib            #+#    #+#             */
/*   Updated: 2020/08/24 04:36:08 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

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

typedef struct				s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int cmp_int(int *a, int *b)
{
	if (*a <= *b)
		return (-1);
	return (1);
}

int cmp_remove(void *node_data, void *data_ref)
{
	if (((char *)node_data)[0] == ((char *)data_ref)[0])
		return (0);
	return (1);
}

void del_fct(void *data)
{
	free(data);
}

void test_atoi_base()
{
	printf(FONT_BOLDYELLOW "-----------------ft_atoi_base-----------------\n" FONT_RESET);
	extern int ft_atoi_base(const char *s, const char *base);
	printf(FONT_BLUE "Test_1_1 : \n" FONT_RESET);
	char *nb_s = strdup("42");
	char *base = strdup("0123456789");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("atoi(|%s|) : %d\n", nb_s, atoi(nb_s));
	printf("\n");
	printf(FONT_BLUE "Test_1_2 : \n" FONT_RESET);
	nb_s = strdup("0");
	base = strdup("0123456789");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("atoi(|%s|) : %d\n", nb_s, atoi(nb_s));
	printf("\n");
	printf(FONT_BLUE "Test_1_3 : \n" FONT_RESET);
	nb_s = strdup("-42");
	base = strdup("0123456789");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("atoi(|%s|) : %d\n", nb_s, atoi(nb_s));
	printf("\n");
	printf(FONT_BLUE "Test_1_4 : \n" FONT_RESET);
	nb_s = strdup("-0");
	base = strdup("0123456789");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("atoi(|%s|) : %d\n", nb_s, atoi(nb_s));
	printf("\n");
	printf(FONT_BLUE "Test_1_5 : \n" FONT_RESET);
	nb_s = strdup("+42");
	base = strdup("0123456789");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("atoi(|%s|) : %d\n", nb_s, atoi(nb_s));
	printf("\n");
	printf(FONT_BLUE "Test_1_6 : \n" FONT_RESET);
	nb_s = strdup("+0");
	base = strdup("0123456789");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("atoi(|%s|) : %d\n", nb_s, atoi(nb_s));
	printf("\n");
	printf(FONT_BLUE "Test_1_7 : \n" FONT_RESET);
	nb_s = strdup("2147483647");
	base = strdup("0123456789");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("atoi(|%s|) : %d\n", nb_s, atoi(nb_s));
	printf("\n");
	printf(FONT_BLUE "Test_1_8 : \n" FONT_RESET);
	nb_s = strdup("2147483648");
	base = strdup("0123456789");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("atoi(|%s|) : %d\n", nb_s, atoi(nb_s));
	printf("\n");
	printf(FONT_BLUE "Test_1_9 : \n" FONT_RESET);
	nb_s = strdup("-2147483648");
	base = strdup("0123456789");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("atoi(|%s|) : %d\n", nb_s, atoi(nb_s));
	printf("\n");
	printf(FONT_BLUE "Test_1_10 : \n" FONT_RESET);
	nb_s = strdup("0");
	base = strdup("01");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_11 : \n" FONT_RESET);
	nb_s = strdup("10");
	base = strdup("01");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_12 : \n" FONT_RESET);
	nb_s = strdup("-10");
	base = strdup("01");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_13 : \n" FONT_RESET);
	nb_s = strdup("+10");
	base = strdup("01");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_13 : \n" FONT_RESET);
	nb_s = strdup("+1000");
	base = strdup("01");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_14 : \n" FONT_RESET);
	nb_s = strdup("-1000");
	base = strdup("01");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_15 : \n" FONT_RESET);
	nb_s = strdup("a");
	base = strdup("0123456789abcdef");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_16 : \n" FONT_RESET);
	nb_s = strdup("-a");
	base = strdup("0123456789abcdef");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_17 : \n" FONT_RESET);
	nb_s = strdup("+a");
	base = strdup("0123456789abcdef");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_18 : \n" FONT_RESET);
	nb_s = strdup("a");
	base = strdup("-0123456789abcdef");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_19 : \n" FONT_RESET);
	nb_s = strdup("a");
	base = strdup("+0123456789abcdef");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_20 : \n" FONT_RESET);
	nb_s = strdup("a");
	base = strdup("0123456789abc2def");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_21 : \n" FONT_RESET);
	nb_s = strdup("a");
	base = strdup("0");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_22 : \n" FONT_RESET);
	nb_s = strdup("a");
	base = strdup("");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_23 (SEGV): \n" FONT_RESET);
	nb_s = NULL;
	base = strdup("01");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_24 (SEGV): \n" FONT_RESET);
	nb_s = strdup("a");
	base = NULL;
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_25 : \n" FONT_RESET);
	nb_s = strdup("cc");
	base = strdup("0123456789abcdef");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_26 : \n" FONT_RESET);
	nb_s = strdup("c;c");
	base = strdup("0123456789abcdef");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_27 : \n" FONT_RESET);
	nb_s = strdup("cc;");
	base = strdup("0123456789abcdef");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_28 : \n" FONT_RESET);
	nb_s = strdup("    cc");
	base = strdup("0123456789abcdef");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_29 : \n" FONT_RESET);
	nb_s = strdup(" +   cc");
	base = strdup("0123456789abcdef");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_30 : \n" FONT_RESET);
	nb_s = strdup(" -   cc");
	base = strdup("0123456789abcdef");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_31 : \n" FONT_RESET);
	nb_s = strdup("   -cc");
	base = strdup("0123456789abcdef");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_32 : \n" FONT_RESET);
	nb_s = strdup("   +cc");
	base = strdup("0123456789abcdef");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_33 : \n" FONT_RESET);
	nb_s = strdup("   c+c");
	base = strdup("0123456789abcdef");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
	printf(FONT_BLUE "Test_1_34 : \n" FONT_RESET);
	nb_s = strdup("   cc+");
	base = strdup("0123456789abcdef");
	printf("ft_atoi_base(|%s|, |%s|) : %d\n", nb_s, base, ft_atoi_base(nb_s, base));
	printf("\n");
}

void test_list_push_front()
{	
	printf(FONT_BOLDYELLOW "-------------ft_list_push_front-------------\n" FONT_RESET);
	extern void ft_list_push_front(t_list **begin_list, void *data);

	printf(FONT_BLUE "Test_2_1 : \n" FONT_RESET);
	t_list *node = calloc(1, sizeof(t_list));
	node->data = strdup(" ,ca marche !");
	node->next = NULL;
	void *data = (void *)strdup("ok");
	printf("node ptr : %p\n", &node);
	printf("data ptr : %p\n", data);
	ft_list_push_front(&node, data); 
	void *data2 = (void *)strdup("test");
	ft_list_push_front(&node, data2); 
	t_list *head = node;
	while (node)
	{
		printf("%s\n", (char *)node->data);
		node = node->next;
	}
	printf("\n");

	printf(FONT_BLUE "Test_2_2 : \n" FONT_RESET);
	ft_list_push_front(&node, NULL); 
	while (node)
	{
		printf("%s\n", (char *)node->data);
		node = node->next;
	}
	printf("\n");

	printf(FONT_BLUE "Test_2_3 : \n" FONT_RESET);
	ft_list_push_front(NULL, strdup("cc")); 
	printf("\n");

	printf(FONT_BLUE "Test_2_4 : \n" FONT_RESET);
	node = NULL;
	ft_list_push_front(&node, strdup("cc")); 
}

void test_list_size()
{
	printf(FONT_BOLDYELLOW "-------------ft_list_size-------------\n" FONT_RESET);
	extern void ft_list_push_front(t_list **begin_list, void *data);
	extern int ft_list_size(t_list *begin_list);

	printf(FONT_BLUE "Test_3_1 : \n" FONT_RESET);
	
	int a = 5;
	int b = 9;
	int c = -10;
	int d = 0;

	t_list *head = malloc(sizeof(t_list));
	head->data = (void *)&a;
	t_list *null_head = NULL;
	ft_list_push_front(&head, &b); 
	ft_list_push_front(&head, &c); 
	ft_list_push_front(&head, &d);
	t_list *node = head;
	printf("nb elem : %d\n", ft_list_size(head)); //expected size : 3
	void *data3 = (void *)strdup("un");
	ft_list_push_front(&head, data3); 
	printf("nb elem : %d\n", ft_list_size(head)); //expected size : 3
	printf("\n");

	printf(FONT_BLUE "Test_3_2 : \n" FONT_RESET);
	printf("nb elem : %d\n", ft_list_size(NULL)); //expected size : 0
	printf("\n");
}

void test_list_sort()
{
	printf(FONT_BOLDYELLOW "-------------ft_list_sort-------------\n" FONT_RESET);
	extern void ft_list_push_front(t_list **begin_list, void *data);
	extern void ft_list_sort(t_list **begin_list, int (*cmp)());
	
	int a = 5;
	int b = 9;
	int c = -10;
	int d = 0;

	printf(FONT_BLUE "Test_4_1 : \n" FONT_RESET);
	t_list *head = malloc(sizeof(t_list));
	head->data = (void *)&a;
	ft_list_push_front(&head, &b); 
	ft_list_push_front(&head, &c); 
	ft_list_push_front(&head, &d);
	ft_list_sort(&head, cmp_int);
	t_list *node = head;
	while (node)
	{
		printf("%d\n", *((int *)node->data));
		node = node->next;
	}
	printf("\n");

	printf(FONT_BLUE "Test_4_2 (SEGV): \n" FONT_RESET);
	t_list *null_head = NULL;
	head = malloc(sizeof(t_list));
	head->data = (void *)&a;
	ft_list_push_front(&head, &b); 
	ft_list_push_front(&head, &c); 
	ft_list_push_front(&head, &d);
	ft_list_sort(&null_head, cmp_int);
	node = head;
	while (node)
	{
		printf("%d\n", *((int *)node->data));
		node = node->next;
	}
	printf("\n");
}

void test_list_remove_if()
{
	printf(FONT_BOLDYELLOW "-------------ft_list_remove_if-------------\n" FONT_RESET);
	extern void ft_list_push_front(t_list **begin_list, void *data);
	extern void ft_list_remove_if(t_list **begin_list, void *data_ref, 
								int (*cmp)(), void (*free_fct)(void *));
	printf(FONT_BLUE "Test_5_1 : \n" FONT_RESET);
	char *ref = "h";
	
	t_list *head = calloc(1, sizeof(t_list));
	char *s1 = strdup("hello");
	char *s2 = strdup("coucou");
	char *s3 = strdup("hok");
	char *s4 = strdup("anoi");
	char *s5 = strdup("hblabla");
	head->data = (void *)s4;
	ft_list_push_front(&head, s5);
	ft_list_push_front(&head, s3);
	ft_list_push_front(&head, s1);
	ft_list_push_front(&head, s2);
	t_list *node = head;
	while (node)
	{
		printf("%s\n", (char *)node->data);
		node = node->next;
	}
	printf("-----------------------------\n");
	ft_list_remove_if(&head, ref, cmp_remove, del_fct);
	node = head;
	while (node)
	{
		printf("%s\n", (char *)node->data);
		node = node->next;
	}

	printf("\n");
	printf(FONT_BLUE "Test_5_2 (SEGV): \n" FONT_RESET);
	
	head = calloc(1, sizeof(t_list));
	head->data = (void *)s4;
	s1 = strdup("hello");
	s2 = strdup("coucou");
	s3 = strdup("hok");
	s4 = strdup("anoi");
	s5 = strdup("hblabla");
	ft_list_push_front(&head, s5);
	ft_list_push_front(&head, s3);
	ft_list_push_front(&head, s1);
	ft_list_push_front(&head, s2);
	node = head;
	while (node)
	{
		printf("%s\n", (char *)node->data);
		node = node->next;
	}
	printf("-----------------------------\n");
	ft_list_remove_if(&head, ref, cmp_remove, del_fct);
	node = head;
	while (node)
	{
		printf("%s\n", (char *)node->data);
		node = node->next;
	}
}

int main(int ac, char **av)
{
	(void)ac;
	test_atoi_base();
	test_list_push_front();
	test_list_size();
	test_list_sort();
	test_list_remove_if();
}
