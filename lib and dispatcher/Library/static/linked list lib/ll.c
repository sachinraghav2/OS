#include<stdlib.h>
typedef struct node{
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
}
