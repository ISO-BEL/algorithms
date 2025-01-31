#include <stdio.h>
#include <stdlib.h>

struct ll //if you always insert at the end you can easily keep a count 
{
	int value;	
	struct ll *next;
};

struct ll*
init_node(int value)
{
	struct ll *new;
	new = malloc(sizeof(struct ll));
	if(new == NULL)
		fprintf(stderr, "malloc failed in new_node\n");
	
	new->value = value;
	new->next = NULL;
	return new;
}
struct ll*
insert_beginning(struct ll *head, int value)
{
	struct ll *new = init_node(value);
	
	new->next = head;
	head = new;
	
	return head; 
}
void
insert_end(struct ll *head, int value) /* keep a count of nodes to skip to end */
									   /* the last is the first node to be made until
										* this function is called */
{
	struct ll *temp_end = head;
	struct ll *new = init_node(value);
	
	for(; temp_end->next != NULL; temp_end = temp_end->next);
	//untill
	temp_end->next = new; 
}
void
print_list(struct ll *head)
{
	struct ll *temp = head;
	while(temp != NULL)
	{	
		printf("%d -> ", temp->value);	
		temp = temp->next;
	}
}
int 
main(void)
{
	struct ll *head;
	head = init_node(10); 
	head = insert_beginning(head, 20);
	head = insert_beginning(head, 30);
	insert_end(head, 5);
	print_list(head);
	
	exit(0);
}
