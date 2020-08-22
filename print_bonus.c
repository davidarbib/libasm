/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 01:26:32 by darbib            #+#    #+#             */
/*   Updated: 2020/08/22 00:22:24 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

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

int main(int ac, char **av)
{

	(void)ac;

	/*
	extern int ft_atoi_base(const char *s, const char *base);
	int nb = ft_atoi_base(av[1], av[2]);
	printf("my atoi --%d--\n", nb);
	int nb2 = atoi(av[1]);
	printf("true atoi : --%d--\n", nb2);
	//printf("atoi(arg) : %d\n", atoi(av[1]));
	*/

	extern void ft_list_push_front(t_list **begin_list, void *data);
	/*
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

	extern int ft_list_size(t_list *begin_list);
	printf("nb elem : %d\n", ft_list_size(head)); //expected size : 3
	void *data3 = (void *)strdup("un");
	ft_list_push_front(&head, data3); 
	printf("nb elem : %d\n", ft_list_size(head)); //expected size : 3
	*/
	/*
	extern	void ft_list_sort(t_list **begin_list, int (*cmp)());
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
	ft_list_sort(&head, cmp_int);
	t_list *node = head;
	while (node)
	{
		printf("%d\n", *((int *)node->data));
		node = node->next;
	}
	*/
	extern void ft_list_remove_if(t_list **begin_list, void *data_ref, 
								int (*cmp)(), void (*free_fct)(void *));
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
}
