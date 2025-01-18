#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Set
{
	int *values;
	int size;
};
/* --------------------------------------------------------------------- */
// set behavior
// --
// should not accept duplicates, potentionally return; and say which had a dup;
// should increase in size as you input more values
// --
/* ---------------------------------------------------------------------- */
void set_init(struct Set *setA);
void set_insert(struct Set *setA, int num);
void set_from_array(int *a, int size, struct Set *setA);
void set_print(struct Set *setA);
void set_union(struct Set *setA, struct Set *setB, struct Set *setC);
void set_intersection(struct Set *setA, struct Set *setB, struct Set *setC);
void set_subtract(struct Set *setA, struct Set *setB, struct Set *setC);

int main(void)
{
	int a[10];
	for(int i = 0; i < 10; i++)
		a[i] = i;

	struct Set setA;
	struct Set setB;
	struct Set setC;
	struct Set setD;
	struct Set setE;

	set_init(&setA);
	set_insert(&setA, 5);
	set_insert(&setA, 3);
	set_insert(&setA, 4);
	set_insert(&setA, 5);

	set_init(&setB);
	set_from_array(a, 10, &setB);
	set_print(&setA);
	set_print(&setB);

	set_init(&setC);
	set_union(&setA, &setB, &setC);
	set_print(&setC);

	set_init(&setD);
	set_intersection(&setA, &setB, &setD);
	set_print(&setD);
	set_insert(&setD, 18);
	set_print(&setD);

	set_init(&setE);
	set_subtract(&setB, &setA, &setE);
	set_print(&setE);
	exit(0);
} 

void set_init(struct Set *setA)
{
	setA->values = malloc(sizeof(int));
	setA->size = 0;
}

void set_insert(struct Set *setA, int num)
{
	for(int i = 0; i < setA->size; i++)
		if(num == setA->values[i]) 
			return;

	setA->values[setA->size] = num;
	setA->size++;
	setA->values = realloc(setA->values, sizeof(int) + sizeof(int) * setA->size);
}

void set_from_array(int *a, int size, struct Set *setA)
{
	for(int i = 0; i < size; i++)
		set_insert(setA, a[i]);		
}

void set_print(struct Set *setA)
{
	for(int i = 0; i < setA->size; i++)
	{
		if(i == setA->size - 1)
		{
			printf("%d\n", setA->values[i]);
			continue;
		}
		printf("%d,", setA->values[i]);
	}
}
void set_union(struct Set *setA, struct Set *setB, struct Set *setC)
{
	/* setA */
	for(int i = 0; i < setA->size; i++)
			set_insert(setC, setA->values[i]);
	/* setB */ 
	for(int i = 0; i < setB->size; i++)
			set_insert(setC, setB->values[i]);
}
void set_intersection(struct Set *setA, struct Set *setB, struct Set *setC)
{
	for(int j = 0; j < setB->size; j++)
		for(int i = 0; i < setA->size; i++)
			if(setB->values[j] == setA->values[i]) 
				set_insert(setC, setB->values[j]);
}
void set_subtract(struct Set *setA, struct Set *setB, struct Set *setC)
{
	int flag;
	for(int j = 0; j < setA->size;)
	{
		flag = 0;
		for(int i = 0; i < setB->size; i++)
		{
			if(setA->values[j] == setB->values[i])
			{
				flag = 1;
				j++;
				break;
			}
			if(flag == 0 && i == setb->size - 1)
			{
				set_insert(setC, setA->values[j]);
				j++;
			}
		}
	}
}
