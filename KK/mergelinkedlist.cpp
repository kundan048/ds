#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  struct node *next;
};




void push(struct node **newnode, int n)
{
  struct node *new_node = (struct node*)malloc(sizeof(struct node));
  struct node *last = *newnode;
  new_node->data = n;
  new_node->next = NULL;

  if(last==NULL)
  {
    last = new_node;
    return;
  }
  while(last->next!=NULL)
  {
    last = last->next;
  }
  last->next = new_node;
  return;
}

void printListx(struct node *newnode)
{
  cout<<"\n";
  while(newnode!=NULL)
  {
    cout<<newnode->data<<"\t";
    newnode = newnode->next;
  }
}

int main()
{
  struct node *head = NULL;
  struct node *a = NULL;
  struct node *b = NULL;

  push(&a,1);
  push(&a,3);
  push(&a,5);
  push(&b,2);
  push(&b,4);
  push(&b,6);
  printListx(&a);
  printListx(&b);
  //head = mergesort(&a,&b);

  return 0;
}
