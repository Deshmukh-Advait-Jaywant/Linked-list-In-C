#include<stdio.h>
#include<stdlib.h>
struct CLL
{
	int data;
	struct CLL *next,*prev;
}*head=NULL;
void Add();
int del();
void add_end();
void add_specific();
int Isempty();
int IsFull();
void count();
void display();
int del_end();
int del_at_specified();
void search_value();
void main()
{
	int z;
	int x,n,i,pos,value,search_val;
	do
	{
	printf("\n********************************************************\n");
	printf("|FOR Adding element at begining PRESS 1         	  |\n");
	printf("|FOR Display elements PRESS 2		                  |\n");
	printf("|FOR is empty operation PRESS 3		                  |\n");
	printf("|FOR is full operation PRESS 4		                  |\n");
	printf("|FOR count operation PRESS 5		                  |\n");
	printf("|FOR add at end operation PRESS 6		              |\n");
	printf("|FOR add at specific operation PRESS 7                |\n");
	printf("|FOR delete PRESS 8                        	          |\n");
	printf("|FOR deleting at the end 9                            |\n");
	printf("|FOR deleting at the specified 10                            |\n");
	printf("|FOR search a elemenet 11                           |\n");
	printf("|FOR EXITING THE PROGRAM PRESS 12                         |\n"); 
	printf("**********************************************************\n");
	printf("enter your choice: \n");
	scanf("%d",&n);
	int search;
	switch(n)
	{
		case 1:
			printf("enter a element : ");
			scanf("%d",&x);
			Add(x);
			break;
		case 2:
			display();
			break;
		case 3:
			if(IsEmpty())
			{
				printf("\nDLL is empty\n");
			}
			else
			{
				printf("\nDLL is not empty");
			}
			break;
		case 4:
			if(IsFull())
			{
				printf("\nDLL is full\n");
			}
			else
			{
				printf("\nDLL is not full");
			}
			break;
		case 5:
			count();
			break;
		case 6:
			printf("enter a element : ");
			scanf("%d",&x);
			add_end(x);
			break;
		case 7:
			printf("enter a element : ");
			scanf("%d",&x);
			printf("enter a position : ");
			scanf("%d",&pos);
			add_specific(x,pos);
			break;
		case 8:
			value=del();
			printf("\n**** %d element is deleted****\n",value);
			break;
		case 9:
			value=del_end();
			printf("\n**** %d element is deleted****\n",value);
			break;
		case 10:
			printf("enter a position : ");
			scanf("%d",&pos);
			value=del_at_specified(pos);
			printf("\n**** %d element is deleted****\n",value);
			break;
		case 11:
			printf("enter a search element : ");
			scanf("%d",&search_val);
			search_value(search_val);
			break;
		case 12:
			exit(0);
			break;
		default:
			printf("\nSELECT THE CORRECT OPTION");
			break;
	}
		
	}while(n!=12);
}
void count()
{
	int count=0;
	struct CLL *tp;
	tp=(struct CLL *)malloc(sizeof(struct CLL));
	tp=head;
	while(tp!=NULL)
	{
		count++;
		tp=tp->next;
	}
	printf("\n**** count : %d ",count);
}
void add_specific(int x,int pos)
{
	int count=1;
	struct CLL *tp,*pp;
	//creating a node
	tp=(struct CLL *)malloc(sizeof(struct CLL));
	if(tp==NULL)
	{
		printf(" double Linked List is full");
		return;
	}
	pp=head;
	while(count<pos-1)
	{
		pp=pp->next;
		count++;
	}
		tp->data=x;
		tp->next=pp->next;
		pp->next=tp;
		tp->prev=pp;
		tp->next->prev=tp;	
		printf("*******#");
}
void add_end(int x)
{
	
	struct CLL *tp,*pp;
	//creating a node
	tp=(struct CLL *)malloc(sizeof(struct CLL));
	if(tp==NULL)
	{
		printf(" double Linked List is full");
		return;
	}
	if(head==NULL)
	{
	tp->data=x;
	tp->next=head;
	if(head!=NULL)
	{
		head->prev=tp;
	}
	tp->prev=NULL;
	head=tp;
	}
	else
	{
	
	pp=head;
	while(pp->next!=NULL)
	{
		pp=pp->next;
	}
	tp->data=x;
	pp->next=tp;
	tp->prev=pp;
	tp->next=NULL;
	
	}
	printf("\n*****NODE ADDED SUCESSFULLY*****\n");
}
void Add(int x)
{
	//create a temporary node
	struct CLL *tp;
	//creating a node
	tp=(struct CLL *)malloc(sizeof(struct CLL));
	if(tp==NULL)
	{
		printf(" double Linked List is full");
		return;
	}
	tp->data=x;
	tp->next=head;
	if(head!=NULL)
	{
		head->prev=tp;
	}
	tp->prev=NULL;
	head=tp;
	printf("\n******element is added at the begining*****\n");
}
int IsEmpty()
{
	if(head==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int IsFull()
{
	 struct CLL *tp;
	tp=(struct CLL *)malloc(sizeof(struct CLL));
	if(tp==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int del()
{
	int x;
	struct CLL *tp;
	//creating a node
	tp=(struct CLL *)malloc(sizeof(struct CLL));
	if(head==NULL)
	{
		printf("DLL is empty");
		return;
	}
	
	tp=head;
	head=head->next;
	if(tp->next!=NULL)
	{
		head->prev=NULL;
	}
	x=tp->data;
	free(tp);
	return x;
}
void display()
{
	struct CLL *tp;
	if(head==NULL)
	{
		printf("double linked list is empty");
		return;
	}
	tp=head;
	while(tp!=NULL)
	{
		printf("%4d->",tp->data);
		tp=tp->next;
	}
}
int del_end()
{
	int x;
	struct CLL *tp,*pp;
	//creating a node
	
	if(head==NULL)
	{
		printf("DLL is empty");
		return;
	}
	tp=head;
	int count=0;
	while(tp!=NULL)
	{
		count++;
		tp=tp->next;
	}
	if(count==1)
	{
		tp=head;
		head=head->next;
		if(tp->next!=NULL)
		{
			head->prev=NULL;
		}
		x=tp->data;
		free(tp);
		return x;
	}
	while(tp->next!=NULL)
	{
		tp=tp->next;
	}
	pp=head;
	while(pp->next!=tp)
	{
		pp=pp->next;
	}
	x=tp->data;
	pp->next=NULL;
	free(tp);
	return x;
}
int del_at_specified(int pos)
{
	int x=0,count=1;
	struct CLL *tp;
	//creating a node
	
	if(head==NULL)
	{
		printf("DLL is empty");
		return;
	}
	tp=head;

	while(count<pos)
	{
		tp=tp->next;
			count++;
	}
	x=tp->data;
	tp->prev->next=tp->next;
	tp->next->prev=tp->prev;
	free(tp);
	return x;
}
void search_value(int search_val)
{
	struct CLL *tp;
	int count=1;
	//creating a node
	tp=(struct CLL *)malloc(sizeof(struct CLL));
	if(head==NULL)
	{
		printf("DLL is empty");
		return;
	}
	tp=head;
	while(tp->data!=search_val)
	{
		tp=tp->next;
		count++;
	}
	printf("element found at %d position",count);
}
