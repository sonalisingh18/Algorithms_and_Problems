/*
Author:Sonali Singh
Dated:26/01/19
Linked list implementation 
insertion+deletion+reversal+sorting
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
};

struct node* head;
void insert(int data, int n);
void Delete(int m);
void reverse();
void sort();
void swap(struct node *p, struct node *q);
void print();

int main()
{
  head = NULL;
  insert(3,1);
  insert(7,2);
  insert(9,3);
  insert(7,1);
  insert(24,4);
  insert(1,5);
  print();
  while(1)
  {
    int x,data,n,m;
    scanf("%d",&x);
    if(x>4) break;
    switch(x)
    {case 1: scanf("%d",&data);
            scanf("%d",&n);
            insert(data,n);
            print();
            break;
    case 2: scanf("%d",&m);
            Delete(m);
            print();
            break;
    case 3: reverse();
            print();
            break;
    case 4: sort();
            print();
            break;
    }
  }
}

void insert(int data, int n)
{
  struct node* temp1 = (struct node*)malloc(sizeof(struct node));
  temp1->data = data;
  temp1->next = NULL;
  if(n==1)
  {
    temp1->next=head;
    head = temp1;
    return ;
  }
  struct node* temp2 =head;
  for(int i=0;i<n-2;i++)
    temp2=temp2->next;
  temp1->next = temp2->next;
  temp2->next = temp1;
}

void Delete(int m)
{
    struct node* temp3 = head;
    if(m==1)
    {
      head = temp3->next;
      free(temp3);
      return;
    }
    int j;
    for(j=0;j<m-2;j++)
      temp3 = temp3->next;
    struct node* temp4 = temp3->next;
    temp3->next=temp4->next;
    free(temp4);
}

void reverse()
{
    struct node *current, *prev, *next;
    current=head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return;
}

void sort()
{
        int i;
    do
    {
        i=0;
        struct node* qtr= NULL, *temp2= head;
        while (temp2->next !=qtr)
        {
            if(temp2->data > temp2->next->data)
            {
                swap(temp2, temp2->next);
                i=1;
            }
            temp2=temp2->next;
        }
        qtr=temp2;
    }
    while(i);
}

void swap(struct node *p, struct node *q)
{
    int temp1;
    temp1= p->data;
    p->data= q->data;
    q->data= temp1;
}

void print()
{
  struct node* temp = head;
  while(temp != NULL)
  {
  	printf("%d ",temp->data);
  	temp = temp->next;
  }
  printf("\n");
}
