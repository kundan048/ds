// Inserting a node in Linked List
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link ;
};

void push(struct node** head, int value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->link = (*head);
	(*head)= newnode;
	
}
void insertAfter(struct node* prev, int value)
{
	if(prev==NULL)
	{
		printf("cant be null");
		return;
	}
	struct node* newnode= (struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->link=prev->link;
	prev->link=newnode;
}
void append(struct node** head,int value)
{
	struct node* newnode= (struct node*)malloc(sizeof(struct node));
	struct node *last = *head;
	newnode->data=value;
	newnode->link= NULL;
	if(*head == NULL)
	{
		*head = newnode;
		return;
	}
	while(last->link!=NULL)
	{
		last = last->link;
	}
	last->link=newnode;
	
}
void printList(struct node* chhapja)
{
	while(chhapja!=NULL)
	{
		printf(" %d ",chhapja->data);
		chhapja = chhapja->link;
	}
}



int main()
{
  /* Start with the empty list */
  struct node* hea = NULL;
 
  // Insert 6.  So linked list becomes 6->NULL
  append(&hea, 6);
 
  // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  push(&hea, 7);
 
  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  push(&hea, 1);
 
  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
  append(&hea, 4);
 
  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
  insertAfter(hea->link, 8);
 
  printf("\n Created Linked list is: ");
  printList(hea);
 
  return 0;
}
