#include<stdio.h>
#include<stdlib.h>
#include "ll.h"
//extern struct node;
/*typedef struct node{
	int val;
	struct node *prev,*next;
	}mynode;
mynode *insert_at_beg(mynode *head,int val)
{
	mynode *temp=malloc(sizeof(mynode));
	temp->val=val;
	temp->next=NULL;
	temp->prev=NULL;
	if(head==NULL)
	{
		head=temp;
		return head;
	}
	temp->next=head;
	head->prev=temp;
	head=temp;
	return head;
	
}

mynode *insert_at_end(mynode *head, int val)
{
	mynode *temp=malloc(sizeof(mynode)),*temp1=head;
	temp->val=val;
	temp->next=NULL;
	temp->prev=NULL;
	if(head==NULL)
	{
		head=temp;
		return head;
	}
	while(temp1->next!=NULL)
		temp1=temp1->next;
	temp1->next=temp;
	temp->prev=temp1;
	return head;
}
mynode *delete_at_beg(mynode *head)
{
	mynode *temp=head;
	if(head==NULL)
	{
		printf("The List is already empty.\n");
		return head;
	}
	if(head->next==NULL)
	{
		head=NULL;
		free(temp);
		return head;
	}
	head=head->next;
	head->prev=NULL;
	free(temp);
	return head;
}
mynode *delete_at_end(mynode *head)
{
	mynode *temp1=head,*temp2;
	if(head==NULL)
	{
		printf("The List is already empty.\n");
		return head;
	}
	if(head->next==NULL)
	{
		head=NULL;
		free(temp1);
		return head;
	}
	while(temp1->next!=NULL)
		temp1=temp1->next;
	temp2=temp1->prev;
	temp2->next=NULL;
	free(temp1);
	return head;
}
mynode *search(mynode *head, int val)
{
	if(head==NULL)
	{
		printf("List is Empty.\n");
		return head;
	}
	while(head!=NULL)
	{
		if(head->val==val)
			break;
		head=head->next;
	}
	return head;
}
void display(mynode *head)
{	printf("\n");
	if(head==NULL)
	{
		printf("List is empty.\n");
		return;
	}
	while(head!=NULL)
	{
		printf("%d\n",head->val);
		head=head->next;
	}	
	printf("\n");
}*/
int main()
{
	int ch,val;
	mynode *head=NULL,*temp;
	while(1)
	{
		printf("\n");
		printf("Choose:\n1.insert_at_beg().\n2.insert_at_end().\n3.delete_at_beg.\n4.delete_at_end.\n5.Search and element.\n6.Display.\n7.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the value: ");
				scanf("%d",&val);
				head=insert_at_beg(head,val);
				break;
			case 2: printf("Enter the value: ");
				scanf("%d",&val);
				head=insert_at_end(head,val);
				break;
			case 3: head=delete_at_beg(head);
				break;
			case 4: head=delete_at_end(head);
				break;
			case 5:/* printf("Enter the value you want to search: ");
				scanf("%d",&val);
				temp=search(head,val);
				if(temp==NULL)
				{
					printf("Element not found.!\n");
					continue;
				}
				printf("%d found.\n",temp->val);*/
				break;
			case 6: display(head);
				break;
			case 7: exit(0);
			default: printf("Enter proper choice!!!\n");
		}
	}
	return 0;
}
