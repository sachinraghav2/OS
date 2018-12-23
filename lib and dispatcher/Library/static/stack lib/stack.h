typedef struct stackRecord mystack;
void makeEmpty(mystack *);
mystack *createStack(int);
int isEmpty(mystack *);
int isFull(mystack *);
void push(mystack *,int);
void pop(mystack *);
void display_stack(mystack *);
int tos(mystack *);
