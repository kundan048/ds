#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};


void insertAtHead(struct Node **head_ref, int data){
	
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	if(!newNode){
		printf("Memory Overflo Error !\n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;

	newNode->next = *head_ref;
	*head_ref = newNode;
}

void insertAtTail(struct Node **head_ref, int data){

	if(*head_ref == NULL){
		insertAtHead(head_ref, data);
		return;
	}

	struct Node *current = *head_ref;

	while(current->next != NULL){
		current = current->next;
	}

	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	if(!newNode){
		printf("Memory Overflo Error !\n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;

	current->next = newNode;
}

void print(struct Node *current){
	printf("List is : ");
	while(current){
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}


int main(){
	struct Node *head = NULL;
	insertAtHead(&head, 1);
	insertAtTail(&head, 2);
	insertAtTail(&head, 3);
	insertAtTail(&head, 4);
	print(head);
	return 0;
}
