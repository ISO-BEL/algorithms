#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//REDO WITH LINKED_LIST 


#define QUEUE_SIZE 20
#define COMMAND_AMOUNT 3 

/* control <"dequeue"> <"queue"> <"print"> <"free"> */ 
/* add ... arg for mutiple inputs into the queue */
int interact_queue(char *control, int num)
{
	static int queue[QUEUE_SIZE];
	static int back = 0;
	static int front = 0;
	
	enum action {enqueue, dequeue, print};
	struct queue
	{	char *control_string;
		enum action target;
	};
	struct queue lookup[COMMAND_AMOUNT] = { {"enqueue", enqueue},
	{"dequeue", dequeue}, {"print", print}, };
	
	for(int i = 0; i < COMMAND_AMOUNT; i++)
	{	if( (strcmp(control, lookup[i].control_string) ) == 0)
		{	
			switch(lookup[i].target)
			{	
				case enqueue : printf("reached enqueue\n");
							   if(back > QUEUE_SIZE - 1)
							   {	fprintf(stderr, "queue full\n");
									break;
							   }
							   queue[back] = num;
							   back++;
							   break;

				case dequeue : printf("reached dequeue\n");
							   int capture;
							   capture = queue[front];
							   int store;
							   //shift
							   for(int i = 1; i < back; i++)
							   {	queue[i - 1] = queue[i];
							   }
							   back--;
							   return capture;
							   break;

				case print   : printf("<print>\n");
							   for(int i = 0; i < back; i++)
								   printf("%d,", queue[i]);
							   break;

				default		 : printf("not an option\n"); /*shouldnt ever reach*/
			}
			break;
		}
	}
}
int main(void)
{
	int num;
	interact_queue("enqueue", 20);
	interact_queue("enqueue", 29);
	interact_queue("enqueue", 210);
	num = interact_queue("dequeue", 0);
	interact_queue("print", 0);

	exit(0);
}



