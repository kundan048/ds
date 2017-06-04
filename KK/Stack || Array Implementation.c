#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack{
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
}

int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity -1;
}

int isEmpty(struct Stack* stack)
{
	return stack->top ==-1;
}

void push(struct Stack* stack, int item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top]= item;
	printf("%d pushed\n",item);
}
int pop(struct Stack* stack)
{
	if(isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}
int main()
{
	struct Stack* stack = createStack(100);
	push(stack,5);
	push(stack,15);
	push(stack,25);
	push(stack,35);
	push(stack,45);
	push(stack,55);
	printf("%d popped\n",pop(stack));
	push(stack,5);
	push(stack,65);
	
	return 0;
}
