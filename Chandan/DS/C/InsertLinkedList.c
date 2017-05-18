// ChandyShot

#include <stdio.h>
#include <malloc.h>

struct Node {
	int data;
	struct Node *next;
};

void insertLinkedList(struct Node **head_ref, int data, int pos){

	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	
	if(!newNode){
		printf("Memory Error !\n");
		return;
	}

	newNode->data = data;
	newNode->next = NULL;
	
	if(pos == 1){
		newNode->next = *head_ref;
		*head_ref = newNode;
		return;
	}

	struct Node *temp = *head_ref;
	while(pos > 2 && temp){
		pos--;
		temp = temp->next;
	}

	if(!temp){
		printf("No Such Position Exists !\n");
		return;
	}

	newNode->next = temp->next;
	temp->next = newNode;
}

void print(struct Node *head){
	while(head){
		printf("%d  ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main(){

	struct Node *head = NULL;
	insertLinkedList(&head, 1, 1);
	insertLinkedList(&head, 2, 2);
	insertLinkedList(&head, 3, 3);
	insertLinkedList(&head, 4, 4);
	
	print(head);
	
	insertLinkedList(&head, 6, 5);
	
	print(head);
	
	insertLinkedList(&head, 5, 5);
	
	print(head);
	
	insertLinkedList(&head, 7, 7);
	insertLinkedList(&head, 9, 8);
	
	print(head);
	
	insertLinkedList(&head, 8, 8);
	
	print(head);
	
	return 0;
}
