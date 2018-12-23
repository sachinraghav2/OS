#include<stdlib.h>
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
}
