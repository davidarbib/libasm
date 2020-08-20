/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 01:26:32 by darbib            #+#    #+#             */
/*   Updated: 2020/08/21 01:58:45 by darbib           ###   ########.fr       */
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

int main(int ac, char **av)
{

	(void)ac;

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
}
