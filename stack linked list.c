#include<stdio.h>
#include<stdlib.h>
struct data_node
{
	int data;
	struct data_node *next;
}*top=NULL;
void push();
int pop();
void display();
void main()
{
    int x,ch;
	do
	{
	printf("\n1.CREATING THE LIST");
	printf("\n2.PUSH");
	printf("\n3.POP");
    printf("\n4.DISPLAYING ALL ELEMENTS ");
    printf("\n5. TO EXIT\n ");

	
	printf("\nenter your choice: ");
	scanf("%d",&ch);

	switch(ch)
		{
		case 1:
		    top=NULL;    
			printf("\nStack is created");
			break;
		case 2:
			printf("\nenter a element : ");
			scanf("%d",&x);
		    push(x);
		    printf("Your element is added");
			break;
		case 3:
			pop(x);
			printf("\nYour element is deleted");
		    break;
		case 4:
		    display();
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("\nSELECT THE CORRECT OPTION");
			break;
	}
		
	}while(ch!=5);
}
void push(int x)
{
	//create a temporary node
	struct data_node *tp;
	//creating a node
	tp=(struct data_node *)malloc(sizeof(struct data_node));
	if(tp==NULL)
	{
		printf("Linked List is full");
		exit(0);
	}
	tp->data=x;		//adding new data 
	tp->next=top;	//new node points to new node
	top=tp;			//hp points to node
	//*count=*count+1;
}
int pop(int x)
{
	struct data_node *tp;
	if(top==NULL)
	{
		printf("Stack using linked list is empty");
	}
	tp=top;
	top=top->next;
	free(tp);
}
void display()
{
	struct data_node *tp;
	tp=top;
	if(top==NULL)
	{
		printf("\n Stack IS EMPTY\n");
		return;
	}
	while(tp!=NULL)
	{
		printf("%d->",tp->data);
		tp=tp->next;
		
	}
	printf("\n");
}
