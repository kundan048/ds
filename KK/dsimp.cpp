/*

// A linked list node
struct node
{
	int data;
	struct node *next;
}


/////////////////////////// introduction of linked list1

#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
};
void printList(struct node *n){
	while(n!=NULL)
	{
		cout<<" Node is "<<n->data<<"\n";
		n = n->next;
	}
}
int main()
{
	struct node *head = NULL;
	struct node *second = NULL:
	struct node *third = NULL;
	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	printList(head);
return 0;
}

*/
/////////////////////////////// insertion in linked list

#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void push(struct node **head, int n){
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = n;
	newnode->next = (*head);
	(*head) = newnode;
}
void insertAfter(struct node **head, int n,int p){
	if(head==NULL)
	{
		cout<<"cannot be NULL: \n";
		return;
	}
	struct node *prev = *head;
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	for(int i =0;i<p;i++)
	{
		prev = prev->next;
		if(prev->next==NULL)
		{
			cout<<"linked list is small enough cannot process"<<"\n";
			return;
		}
	}
	newnode->data = n;
	newnode->next = prev->next;
	prev->next = newnode;


}
void atEnd(struct node **head, int n){
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	struct node *last = *head;
	newnode->data = n;
	newnode->next =  NULL;
	if(*head==NULL)
	{
		*head = newnode;
		return;
	}
	while(last->next != NULL){
		last = last->next;
	}
	last->next = newnode;
	return;
}

void printList(struct node *node)
{
	while(node!=NULL)
	{
		cout<<node->data<<"\t";
		node = node->next;
	}
	cout<<"\n";
}
void deleteNode(struct node **head, int k)
{
	 struct node *temp = *head;
	 struct node *prev = *head;
	 if(temp!=NULL&&temp->data==k)
	 {
	 	*head = temp->next;
	 	free(temp);
	 	return;
	 }

	 while(temp!=NULL && temp->data != k)
	 {
	 	prev = temp;
	 	temp = temp->next;
	 }

	 if(temp==NULL)
	 	return;

	 prev->next = temp->next;
	 free(temp);
}
void swapdata(struct node **head,int x, int y)
{
	if(x==y)
		return;

	struct node *prevX = NULL;
	struct node *currX = *head;
	while(currX && currX->data!=x)
	{
		prevX=currX;
		currX = currX->next;
	}
	struct node *prevY = NULL;
	struct node *currY = *head;
	while(currY && currY->data != y)
	{
		prevY = currY;
		currY = currY->next;
	}

	if(currX==NULL||currY==NULL)
	{
		return;
	}

	if(prevX != NULL)
	{
		prevX->next = currY;
	}else{
		*head = currY;
	}

	if(prevY != NULL)
	{
		prevY->next = currX;
	}else{
		*head = currX;
	}

	struct node *temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;


}
void reverseList(struct node **head)
{
	struct node *prev = NULL;
	struct node *next;
	struct node *curr = *head;

	while(curr!=NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}
void reverserecursion(struct node **head)
{
	if(*head==NULL)
		return;
	struct node *first = *head;
	struct node *rest = first->next;

	if(rest==NULL)
		return;

		reverserecursion(&rest);
		first->next->next = first;

		first->next = NULL;

		*head = rest;

}

int main()
{
	struct node *head = NULL;
	while(1){
		int k;
		int n;
		int p;
		int l;
		int m;

		cout<<"Enter 1 for insertion in begining \nEnter 2 for insertion after given node \nEnter 3 for insertion at end \nEnter 4 for print the linked list\nEnter 5 to delete node \nEnter 6 to swap \nEnter 7 to reverse the linked list using iteration\nEnter 8 for reverse using recursion\nEnter 9 to exit: \n";

		cin>>k;
		switch(k)
		{
			case 1:
					//beginning
					cout<<"Enter value to be inserted: ";
					cin>>n;
					push(&head, n);

					break;
			case 2:
					//given node
					cout<<"Enter value to be inserted: ";
					cin>>n;
					cout<<"Enter position no.: ";
					cin>>p;
					insertAfter(&head,n,p);

					break;
			case 3:
					//at end
					cout<<"Enter value to be inserted: ";
					cin>>n;
					atEnd(&head, n);
					break;
			case 4:
					//print
					printList(head);

					break;
			case 5:
					//delete node
					cout<<"Enter element to delete: ";
					cin>>n;
					deleteNode(&head,n);
					break;
			case 6:
					//swap through linked list
					cout<<"\nEnter first no. to swap: :";
					cin>>l;
					cout<<"\nEnter second no. to swap :";
					cin>>m;
					swapdata(&head,l,m);
					break;
			case 7:
					//reverse linked list by iterative method
					reverseList(&head);
					break;
			case 8:
					//reverse list by recursion
					reverserecursion(&head);
					break;
			case 9:
					//close
					exit(0);
					break;
			default:
					//if different no. pressed
					cout<<"You have entered wrong keyword";
					break;
		}



	}
}
