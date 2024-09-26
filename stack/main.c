#include "funcdefinitions.h"


int main(void)
{
	//calling command pattern
	char command = 'h';
	int insert = 0;
	int popped = 0;
	
	while(1)
	{
		printf("enter a command (h - help) :	");
		scanf(" %c", &command);

		switch(command)
		{
			case 'h': printf("commands:\n u - push.\n o - pop.\n p - print.\n c - clear.\n"
							 " e - check if empty.\n f - check if full.\n x - exit.\n");
					  break;
			case 'u': printf("what number would you like to push : ");
					  scanf("%d", &insert);
					  push(insert);
					  break;
			case 'o': popped = pop();
					  if(popped == -1){
						  continue;
					  }
					  printf("the number popped was %d", popped);
					  break;
			case 'p': stack_print();
					  break;
			case 'c': clear();
					  break;
			case 'e': check_empty();
					  break;
			case 'f': check_full();
					  break;
			case 'x': exit(0);
			default : printf("not a command: type h for help");
					  break;
		}
		printf("\n");
	}
	
	exit(0);
}
