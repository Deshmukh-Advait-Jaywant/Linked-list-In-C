#include<stdio.h>
#include<stdlib.h>
struct CLL
{
	int data;
	struct CLL *next,*prev;
}*last=NULL;
void Add();
void Add_end();
void display();
int del();
void Add_At_Specified();
int del_at_end();
int del_at_specified();
void duplicate();
void main()
{
	int z;
	int x,n,i,pos,value,search_val;
	do
	{
	printf("\n********************************************************\n");
	printf("|FOR Adding element at begining PRESS 1         	  |\n");
	printf("|FOR Display elements PRESS 2			                  |\n");
	printf("|FOR deleting elements PRESS 3			                  |\n");
	printf("|FOR add elements at end PRESS 4			                  |\n");
	printf("|FOR deleting elements at end PRESS 5			                  |\n");
	printf("|FOR deleting elements at specified PRESS 6		                  |\n");
	printf("|FOR deleting duplicate elements at specified PRESS 7		                  |\n");
	printf("|FOR EXITING THE PROGRAM PRESS 8                    |\n"); 
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
			value=del();
			printf("\n*****%d is deleted ******",value);
			break;
		case 4:
			printf("enter a element : ");
			scanf("%d",&x);
			Add_end(x);
			break;
		case 5:
			value=del_at_end();
			printf("\n*****%d is deleted ******",value);
			break;
		case 6:
			printf("enter a position : ");
			scanf("%d",&pos);
			value=del_at_specified(pos);
		//	printf("\n*****%d is deleted ******",value);
			break;
		case 7:
			duplicate();
		case 8:
			printf("enter a number");
			scanf("%d",&x);
			printf("enter a position : ");
			scanf("%d",&pos);
			Add_At_Specified(x,pos);
			break;
		default:
			printf("\nSELECT THE CORRECT OPTION");
			break;
	}
		
	}while(n!=9);
}
void duplicate()
{
	int x;
	struct CLL *tp,*pp;
	//creating a node
	tp=(struct CLL *)malloc(sizeof(struct CLL));
	if(tp==NULL)
	{
		printf("its full");
		return;
	}
	tp=last->next;
	do
	{
		pp=last->next;
		while(pp!=pp->next)
		{
			if(pp->data==tp->data)		
			{
				pp->prev->next=pp->next;
				pp->next->prev=pp->prev;
				free(pp);
			}
			pp=pp->next;
		}
		tp=tp->next;
	}while(tp!=tp->next);
	tp=last->next;
	do
	{
		printf("%4d->",tp->data);
		tp=tp->next;
	}while(tp!=last->next);
}
void Add_At_Specified(int x,int pos)
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
	if(last==NULL)
	{
		printf("11111111");
		tp->data=x;
		tp->next=tp;
		tp->prev=tp;
		last=tp;
	}
	else
	{
		printf("11112222222221111");
		count=1;
		pp=last->next;
		while(pp!=last->next)
		{
			pp=pp->next;
			count++;
		}
		if(pos==count+1)
		{	
		printf("11133333333333311111");
			tp->data=x;
			tp->next=last->next;
			last->next->prev=tp;
			last->next=tp;
			tp->prev=last;
			last=tp;
		}
		else
		{
			printf("111144444444444441111");
			count=1;
			pp=last->next;
			while(count<pos-1)
			{
				pp=pp->next;
				count++;
			}
			tp->data=x;
			tp->next=pp->next;
			pp->next->prev=tp;
			pp->next=tp;
			tp->prev=pp;
		}
	}
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
	if(last==NULL)
	{
		tp->data=x;
		tp->next=tp;
		tp->prev=tp;
		last=tp;
	}
	else
	{
		if(last->next==last)
		{
			tp->data=x;
			tp->next=last;
			last->next=tp;
			last->prev=tp;
			tp->prev=last;
		}
		else
		{
			tp->data=x;
			tp->next=last->next;
			tp->next->prev=tp;
			last->next=tp;
			tp->prev=last;
		}
	}
}
void Add_end(int x)
{
	struct CLL *tp;
	//creating a node
	tp=(struct CLL *)malloc(sizeof(struct CLL));
	if(tp==NULL)
	{
		printf(" double Linked List is full");
		return;
	}
	
	if(last==NULL)
	{
		tp->data=x;
		tp->next=tp;
		tp->prev=tp;
		last=tp;	
	}
	else
	{
		tp->data=x;
		tp->next=last->next;
		last->next->prev=tp;
		last->next=tp;
		tp->prev=last;
		last=tp;
		
	}
}
void display()
{
	struct CLL *tp;
	if(last==NULL)
	{
		printf(" Circular double linked list is empty");
		return;
	}
	tp=last->next;
	do
	{
		printf("%4d->",tp->data);
		tp=tp->next;
	}while(tp!=last->next);
}
int del_at_end()
{
	int x=0;
	struct CLL *tp,*pp;
	if(last==NULL)
	{
		printf("\nDCLL is empty");
		return ;
	}
	//initilizing tp to last and pp to last second node
	tp=last;
	pp=last->prev;
	
	//delete element at end
	x=tp->data;
	pp->next=tp->next;
	tp->next->prev=pp;
	last=pp;
	free(tp);
	return x;
}
int del_at_specified(int pos)
{
	int x=0,count=1;
	struct CLL *tp,*pp;
	if(last==NULL)
	{
		printf("\nDCLL is empty");
		return ;
	}
	//

	tp=last->next;
	// to check if the user wants to delete the first node
	
	if(pos==1)
	{
		printf("111111111");
		
		tp=last->next;
		if(last==last->next)
		{
			x=tp->data;
			last=NULL;
			free(tp);
		}
		else
		{
			x=tp->data;
			last->next=tp->next;
			tp->next->prev=last;
			free(tp);
		}	
	}
	//to check if ser wants to delete the last node;
	else
	{
		printf("222222222");
		pp=last->next;
		while(pp!=last->next)
		{
			pp=pp->next;
			count++;
		}
		if(pos==count)
		{
			printf("222333333333333222222");	
		tp=last;
		pp=last->prev;
		//delete element at end
		x=tp->data;
		pp->next=tp->next;
		tp->next->prev=pp;
		last=pp;
		free(tp);
		}
		else
		{
				printf("2223333333333334444444444444222222");
			count=1;
			//=last->next;
			while(count<pos)
			{
				tp=tp->next;
				count++;	
			}	
			tp->prev->next=tp->next;
			tp->next->prev=tp->prev;
			free(tp);
		}
	}
	//againg initiling count
}
int del()
{
	int x=0;
	struct CLL *tp;
	if(last==NULL)
	{
		printf("\nDCLL is empty");
		return ;
	}
	tp=last->next;
	if(last==last->next)
	{
		x=tp->data;
		last=NULL;
		free(tp);
	}
	else
	{
		x=tp->data;
		last->next=tp->next;
		tp->next->prev=last;
		free(tp);
	}
	return x;
}
