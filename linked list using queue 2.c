#include<stdio.h>
#include<stdlib.h>
struct Queue
{
	int data;
	struct Queue *next;
};
struct Queue *front,*rear;
void creating();
void Enqueue(int );
int Dequeue();
void Traversal();
int main()
{
	int ch,x,value; 
	do
	{
		printf("enter 1 for creating operation");
		printf("enter 2 for Enqueue operation");
		printf("enter 3 for Denqueue operation");
		printf("enter 4 for Traversal operation");
		printf("enter 5 for quiting from the program");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				creating();
			case 2:
				printf("enter a element : \n");
				scanf("%d",x);
				Enqueue(x);
				break;
			case 3:
				value=Dequeue();
				printf("\nThe deleted element is : %d",value);
				break;
			case 4:
				Traversal();
				break;
			case 5:
				exit(0);
		}
	} while(ch!=5);	
	return 0;
}
void creating()
{
	front=NULL;
	rear=NULL;
}
void Enqueue(int x)
{
	struct Queue *tp;
	tp=(struct Queue *)malloc(sizeof(struct Queue));
	if(tp==NULL)
	{
		printf("queue is full");
	}
	else
	{
		tp->data=x;
		tp->next=NULL;
		if(front==NULL)
		{
			front=tp;
			rear=tp;
		}
		else
		{
			rear->next=tp;
			rear=tp;
		}
	}
}
int Dequeue()
{
	int x;
	struct Queue *tp;
	if(front==NULL)
	{
		printf("queue is empty");
	}
	else
	{
		if(front==rear)
		{
			rear=NULL;
		}
		tp=front;
		x=tp->data;
		front=front->next;
		free(tp);
	}
	return x;
}
void Traversal()
{
	struct Queue *tp;
	if(front==NULL)
	{
		printf("queue is empty");
	}
	else
	{
		tp=front;
		while(tp!=NULL)
		{
			printf("%4d->",tp->data);
			tp=tp->next;
		}
	}
}
