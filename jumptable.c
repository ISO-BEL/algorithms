#include <stdlib.h>
#include <stdio.h>

void (*func(int, int, void (*pfunc)(int, int) ) )(int, int)
include <stdint.h>

#define TABLEFUNC_COUNT 4
void func1(void){ printf("1"); }
void func2(void){ printf("2"); }
void func3(void){ printf("3"); }
void func4(void){ printf("4"); }
enum func_names {func_1, func_2, func_3, func_4};

typedef void (*jump_vv)(void);
typedef int  (*jump_iv)(void); 

//read about the utility of jumps tables and function pointers
int jmp_on_index(uint8_t jmp_index)
{
	static void (const *jump_vv2[])(void) = {func1, func2, func3, func4};
	if(jmp_index < sizeof(jump_vv2) / sizeof(*jump_vv2)) //0-3:4
	{
		jump_vv2[jmp_index]();
	}
	else
	{
		return 1;
	}

}

int main(void)
{

jump_vv jumptable[4] = {func1, func2, func3, func4};
jumptable[func_4](); //prints 4

int status = jmp_on_index(3);

return 0;
}

