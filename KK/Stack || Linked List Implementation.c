#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(){
	return NULL;
}

void push(struct Node** top, int data)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = *top;
	*top = temp;
	printf("%d pushed\n",data);
	
}
int isEmpty(struct Node* top)
{
	return top == NULL;
}
int pop(struct Node** top)
{
	int data;
	struct Node* temp;
	if(isEmpty(top))
		return INT_MIN;
	temp = *top;
	*top = temp->next;
	printf("%d popped\n",temp->data);
	free(temp);
}
int main()
{
	struct Node* top = NULL;
	push(&top,10);
	push(&top,20);
	push(&top,30);
	push(&top,40);
	pop(&top);
	push(&top,50);
	
	return 0;
}
