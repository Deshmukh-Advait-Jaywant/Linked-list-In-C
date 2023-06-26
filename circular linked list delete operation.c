#include<stdio.h>
#include<stdlib.h>
struct CLL
{
	int data;
	struct CLL *next;
}*last=NULL;
void Add_At_Start();
int Delete_At_Start();
int Delete_At_End();
int Delete_At_Specified(int );
void display();
void main()
{
	int z;
	int x,n,i,pos,value;
	do
	{
	printf("\n**************************************************\n");
	printf("|FOR Adding element at begining PRESS 1 	          	  |\n");
	printf("_________________________________________________________\n");
	printf("|For deleting the node at start	PRESS 2		              |\n");
	printf("_________________________________________________________\n");
	printf("|FOR deleting the node at end PRESS 3				   	  |\n");
	printf("_________________________________________________________\n");
	printf("|FOR deleting element at specified PRESS 4              |\n");
	printf("_________________________________________________________\n");
	printf("|FOR Display elements PRESS 5              |\n");
	printf("_________________________________________________________\n");
	printf("|FOR EXITING THE PROGRAM PRESS 6                         |\n");                                     
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
			value=Delete_At_Start();
			printf("******%d element is deleted*******",value);
			break;
		case 3:
			value=Delete_At_End();
			printf("******%d element is deleted*******",value);
			break;
		case 4:
			printf("\nenter the position of element to be deleted : ");
			scanf("%d",&pos);
			value=Delete_At_Specified(pos);
			printf("******%d element is deleted*******",value);
			break;
		case 5:
			display();
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("\nSELECT THE CORRECT OPTION");
			break;
	}
		
	}while(n!=6);
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
int Delete_At_Start()
{
	int x;
	struct CLL *tp;
	if(last==NULL)
	{
		printf("\nCLL is empty");
		return;
	}
	if(last==last->next)
	{
		tp=last;
		x=tp->data;
		last=NULL;
		free(tp);
	}
	else
	{
		tp=last->next;
		x=tp->data;
		last->next=tp->next;
		free(tp);
	}
	return x;
}
int Delete_At_End()
{
	int x;
	struct CLL *tp,*pp;
	if(last==NULL)
	{
		printf("\nCLL is empty");
		return;
	}
	if(last!=last->next)
	{
		tp=last;
		x=tp->data;
		last=NULL;
		free(tp);
	}
	else
	{
		tp=last;
		pp=tp->next;
		while(pp->next!=last)
		{
			pp=pp->next;
		}
		pp->next=last->next;
		last=pp;
		free(tp);
	}
	return x;
}
int Delete_At_Specified(int pos)
{
	int x,count;
	struct CLL *tp,*pp;
	pp=last->next;
	count=1;
	while(count<pos-1)
	{
		pp=pp->next;
		count++;
	}
	tp=pp->next;
	pp->next=tp->next;
	x=tp->data;
	free(tp);
	return x;
}
void display()
{
	struct CLL *tp;
	tp=last->next;
	do
	{
		printf("%4d->",tp->data);
		tp=tp->next;
	}while(tp!=last->next);
}
