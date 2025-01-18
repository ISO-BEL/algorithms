//add string commnads (lookup table)
//add reallocation of the size of the stack

#include "stack.h" //stack_size variable / stack functions / c standards
int *stack;
int top = 0;
int size;

enum Commands{c_push, c_pop, c_clear, c_print, c_dupe, c_check_full, c_check_empty, c_realloc};
struct lookup
{
	char command_string[20];
	enum Commands command_actual; 
};
struct lookup lookup_table[/* command amount */]
={ {"push", c_push}, {"pop", c_pop}, {"clear", c_clear}, {"print", c_print}, {"dupe", c_dupe},
   {"check_full", c_check_full}, {"check_empty", c_check_empty}, {"realloc", c_realloc}, }; 

int main(void)
{
	int n;
	enum Commands selected;
	char command_string[12];
	printf("what size stack do you want?\n");
	scanf("%d", &size);
	stack = malloc((sizeof *stack) * size);
	memset(stack, 0, sizeof stack);
	
	while(strcmp(command_string, "exit") != 0)
	{
	printf("enter you command: ");
	scanf(" %s", command_string);
	for(int i = 0; i < 8; i++)
	{
		if( strcmp(command_string, lookup_table[i].command_string) == 0)
		{ selected = lookup_table[i].command_actual;
		}
	}
	switch(selected)
	{
		case c_push: printf("what number would you like to push?: ");
				     scanf("%d", &n);
				     push(n);
				     break;
		case c_pop : n = pop();
				     printf("pop took %d out of the stack", n);
				     break;

		case c_clear : clear();
					   printf("cleared");
					   break;
		case c_print : print();
					   break;
		case c_dupe  : printf("how many times you want to dupe top of stack?: ");
					   scanf("%d", &n);
					   dupe(n);
					   break;

		case c_check_full  : n = check_full();
							 if(n == false)
								 printf("returned false");
							 else 
								 printf("is full");
							 break;
		case c_check_empty : n = check_empty();
							 if(n == false) 
								 printf("returned false");
							 else 
								 printf("is empty");
							 break;
		case c_realloc	   : printf("how big do you want the stack to be?");
							 scanf("%d", &size);
							 stack = realloc(stack, (sizeof *stack) * size);
							 break;

		default : printf("[not a command!]\ncommand list\n -push\n -pop\n -clear\n"
				  " -print\n -dupe\n -check_full\n -check_empty\n -exit");
	}
	printf("\n");
	}

	exit(0);
}
