#include<stdio.h>
#include<stdlib.h>
struct data_node
{
	int data;
	struct data_node *next;
}*hp=NULL;
void create_sll();
void insert_sll();
void display_sll();
void insert_at_spcified();
void insert_at_end();
int IsEmpty_sll();
int IsFull_sll();
int Delete_sll();
int Display_sll();
int Destroy_sll();
void main()
{
	//struct data_node *hp=NULL;
	int z;
	int x,n,i,count=0,num;
	do
	{
	printf("**************************************************\n");
	printf("|FOR CREATING LINKED LIST PRESS 1 	          	  |\n");
	printf("_________________________________________________________\n");
	printf("|FOR CREATING INSERTING ELEMENT TO LINKED LIST PRESS 2    |\n");
	printf("_________________________________________________________\n");
	printf("|FOR DISPLAYING ALL ELEMENTS IN LIST PRESS 3              |\n");
	printf("_________________________________________________________\n");
	printf("|TO ENTER THE ELEMENT AT SPECIFIED POSITION OF ELEMENTS PRESS 4|\n");
	printf("_________________________________________________________\n");
	printf("|TO ENTER THE ELEMENT AT THE END OF ELEMENTS PRESS 5|\n");
	printf("_________________________________________________________\n");
	printf("|TO KNOW LIST IS EMPTY OR NOT OF ELEMENTS PRESS 6         |\n");
	printf("_________________________________________________________\n");
	printf("|TO KNOW LIST IS FULL OR NOT OF ELEMENTS PRESS 7         |\n");
	printf("_________________________________________________________\n");
	printf("|FOR DELETING AN ELEMENT PRESS 8                          |\n"); 
	printf("_________________________________________________________\n");
	printf("|FOR SEARCHING AN ELEMENT PRESS 9                         |\n"); 
	printf("_________________________________________________________\n");
	printf("|FOR DESTROYING LINKED LIST PRESS 10                      |\n");  
	printf("_________________________________________________________\n");
	printf("|FOR EXITING THE PROGRAM PRESS 11                         |\n");                                     
	printf("**********************************************************\n");
	printf("enter your choice: \n");
	scanf("%d",&n);
	int search;
	switch(n)
	{
		case 1:
			printf("enter a element : ");
			scanf("%d",&x);
			create_sll(x,&count);
			break;
		case 2:
			printf("enter a element : ");
			scanf("%d",&x);
			insert_sll(x,&count);
			break;
		case 3:
			display_sll();
			break;
		case 4:
			printf("enter the position : ");
			scanf("%d",&num);
			printf("enter a element : ");
			scanf("%d",&x);
			 insert_at_spcified(x,num);
			break;
		case 5:
			printf("enter a element : ");
			scanf("%d",&x);
			insert_at_end(x);
			break;
		case 6:
			if(IsEmpty_sll(&count))
			{
				printf("LINKED LIST IS EMPTY\n");
			}
			else
			{
				printf("\nLINKED LIST IS NOT EMPTY\n");
			}
			break;
		case 7:
			if(IsFull_sll())
			{
				printf("LINKED LIST IS FULL\n");
			}
			else
			{
				printf("\nLINKED LIST IS NOT FULL\n");
			}
			break;
		case 8:
			Delete_sll(&count);
			break;
		case 9:
			printf("enter the element you want to search");
			scanf("%d",&search);
			if(IsEmpty_sll(&count))
			{
				printf("\nLINKED LIST IS EMPTY");
			}
			else
			{
				z=Display_sll(search);
				if(z==-1)
				{
				printf("\nTHE ELEMENT IS NOT FOUND\n");
			}
				else
				{	
				printf("the element is found at %d",z);
			}
			
			}
			break;
		case 10:
			if(IsEmpty_sll(&count))
			{
				printf("\nLINKED LIST IS EMPTY");
			}
			else
			{
				Destroy_sll();
				printf("YOUR LINKED LIST IS DESTROYED\n");
			}
			break;
		case 11:
			exit(0);
			break;
		default:
			printf("\nSELECT THE CORRECT OPTION");
			break;
	}
		
	}while(n!=11);
}
void create_sll(int x,int *count)
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
	hp=tp;			//hp points to node
	tp->data=x;		//adding new data 
	hp->next=NULL;
	*count=*count+1;	
//	printf("%d",tp->data);
}
void insert_sll(int x,int *count)
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
	tp->next=hp;	//new node points to new node
	hp=tp;			//hp points to node
	*count=*count+1;
}
void insert_at_spcified(int x,int num)
{
	
	struct data_node *pp,*tp;
	int count=1;
	pp=hp;
	while(count!=num-1)
	{
		pp=pp->next;
		count++;
	}
	tp=(struct data_node *)malloc(sizeof(struct data_node));
	tp->data=x;
	tp->next=pp->next;
	pp->next=tp;
}
void insert_at_end(int x)
{
	struct data_node *pp,*tp;
	pp=hp;
	while(pp->next!=NULL)
	{
		pp=pp->next;
	}
	tp->data=x;
	tp->next=NULL;
	pp->next=tp;
}
void display_sll()
{
	//create a temporary node
	struct data_node *tp;
	//hp points to node
	tp=hp;
	if(hp==NULL)
	{
		printf("\nLINKED LIST IS EMPTY\n");
		return;
	}
	while(tp!=NULL)
	{
		printf("%d->",tp->data);
		tp=tp->next;
		
	}
	printf("\n");
}
/*void count_sll(int *count)
{
	struct data_node *tp;
	tp=hp;
	while(tp!=NULL)
	{
		*count=*count+1;
		tp=tp->next;
	}
	printf("THE TOTAL NUMBER OF ELEMENTS IS : %d\n",*count);
}*/
int IsEmpty_sll(int *count)
{
	if(*count==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int IsFull_sll()
{
	struct data_node *tp;
	
	tp=(struct data_node *)malloc(sizeof(struct data_node));
	if(tp==NULL)
	{
		return 1;
	}
	else
	{
		free(tp);
		return 0;
	}	
}
int Delete_sll(int *count)
{
	struct data_node *tp;
	tp=hp;
	hp=tp->next;
	free(tp);
	*count=*count-1;
}
int Display_sll(int search)
{
	int position=1;
	struct data_node *tp;
	tp=hp;
	while(tp!=NULL)
	{
		if(tp->data==search)
		{
			return position;
			
		}
		else
		{
			tp=tp->next;
			position++;
		}
	}
	return -1;
}
int Destroy_sll()
{
	struct data_node *tp;
	while(hp!=NULL)
	{
		tp=hp;
		hp=tp->next;
		free(tp);
	}
}
