#include<stdio.h>
#include<stdlib.h>
#include "stack.h"/*
typedef struct stackRecord{
	int capacity,top;
	int *array;
	}mystack;
void makeEmpty(mystack *s)
{
	s->top=-1;
}
mystack *createStack(int max)
{
	mystack *s=(mystack *)malloc(sizeof(mystack));
	s->array=(int *)malloc(sizeof(int)*max);
	s->capacity=max;
	makeEmpty(s);
	return s;
}
int isEmpty(mystack *s)
{
	return s->top==-1;
}
int isFull(mystack *s)
{
	return (s->top)==(s->capacity-1);
}
void push(mystack *s,int val)
{
	if(isFull(s))
		printf("The stack is full!\n");
	else
		s->array[++s->top]=val;
}
void pop(mystack *s)
{
	if(isEmpty(s))
		printf("Stack is already empty.\n");
	else
		s->top--;
}
void display_stack(mystack *s)
{
	int temp=s->top;
	if(isEmpty(s))
		printf("The stack is empty!\n");
	else
	{
		while(temp!=-1)
		{
			printf("%d\n",s->array[temp]);
			temp--;
		}
	}
}
int tos(mystack *s)
{
	if(isEmpty(s))
		return -999;
	else
		return s->array[s->top];
}*/
int main()
{
	mystack *ms;
	ms=createStack(20);
	int ch,val;
	while(1)
	{
		printf("Choose:\n1.Push().\n2.Pop()\n3.display_stack()\n4.top().\n5.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the value: ");
				scanf("%d",&val);
				push(ms,val);
				break;
			case 2: pop(ms);
				break;
			case 3: display_stack(ms);
				break;
			case 4: val=tos(ms);
				printf("Top value is %d.\n",val);
				break;
			case 5: exit(0);
			default: printf("Enter proper choice!!!\n");
		}
	}
	return 0;
}
