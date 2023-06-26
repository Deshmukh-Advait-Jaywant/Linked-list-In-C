#include<stdio.h>
#include<stdlib.h>
struct CLL
{
	int data;
	struct CLL *next;
}*last=NULL;
void Add_At_Start();
void Add_At_End();
void Add_At_Specified();
void display();
void main()
{
	int z;
	int x,n,i,pos;
	do
	{
	printf("**************************************************\n");
	printf("|FOR Adding element at begining PRESS 1 	          	  |\n");
	printf("_________________________________________________________\n");
	printf("|FOR  Adding element at end PRESS 2    |\n");
	printf("_________________________________________________________\n");
	printf("|FOR Adding element at specified PRESS 3              |\n");
	printf("_________________________________________________________\n");
	printf("|FOR Display elements PRESS 4              |\n");
	printf("_________________________________________________________\n");
	printf("|FOR EXITING THE PROGRAM PRESS 5                         |\n");                                     
	printf("**********************************************************\n");
	printf("enter your choice: \n");
	scanf("%d",&n);
	int search;
	switch(n)
	{
		case 1:
			printf("enter a element : ");
			scanf("%d",&x);
			Add_At_Start(x);
			break;
		case 2:
			printf("enter a element : ");
			scanf("%d",&x);
			Add_At_End(x);
			break;
		case 3:
			printf("enter the position : ");
			scanf("%d",&pos);
			printf("enter a element : ");
			scanf("%d",&x);
			 Add_At_Specified(x,pos);
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
		
	}while(n!=5);
}
void Add_At_Start(int x)
{
	//create a temporary node
	struct CLL *tp;
	//creating a node
	tp=(struct CLL *)malloc(sizeof(struct CLL));
	if(tp==NULL)
	{
		printf(" circular Linked List is full");
		return;
	}
	if(last==NULL)
	{
		tp->data=x;
		tp->next=tp;
		last=tp;
	}
	else
	{
		tp->data=x;
		tp->next=last->next;
		last->next=tp;
	}
	printf("\n******element is added at the begining*****\n");
}
void Add_At_End(int x)
{

	struct CLL *tp;
	if(tp==NULL)
	{
		printf("\nLINKED LIST IS EMPTY\n");
		return;
	}
	if(last==NULL)
	{
		tp->data=x;
		tp->next=tp;
		last=tp;
	}
	else
	{
		tp->data=x;
		tp->next=last->next;
		last->next=tp;
		last=tp;
	}
	printf("\n****element is added at the end****\n");
}
void Add_At_Specified(int x,int pos)
{
	int count;
	struct CLL *tp,*pp;
	
	if(tp=NULL)
	{
		printf("\nCLL is full");
		return;
	}
	if(pos==1)
	{
		tp->data=x;
		tp->next=last->next;
		last->next=tp;
	}
	else
	{
		count=1;
		pp=last->next;
		while(pp->next!=last->next)
		{
			pp=pp->next;
			count++;
		}
		if(pos==count+1)
		{
			tp->data=x;
			tp->next=last->next;
			last->next=tp;
			last=tp;
		}
		else
		{
			count=1;
			pp=last->next;
			while(count<pos-1)
			{
				pp=pp->next;
				count++;
			}
			tp->data=x;
			tp->next=pp->next;
			pp->next=tp;
		}
	}
}
void display()
{
	struct CLL *tp;
	
	tp=last->next;
	while(tp->next!=last->next)
	{
		printf("%4d->",tp->data);
		tp=tp->next;
	}
}
