#include<stdio.h>
#include<stdlib.h>
#define SIZE 65
void push(int[],int *,int[]);
int pop(int[],int *);
int Top(int[],int *);
int IsEmpty(int[],int *);
int IsFull(int [],int *);
int Count(int *);
int size();
int display();
int main()
{
	int stack[SIZE],top=0,x,ch[i],a,i,n,t[100];
	printf("enter total number of elements");
	scanf("%d",&n);
	printf("enter the elements");
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&ch[i]);
		push(stack,&top,ch);
		t[i]=pop(stack,&top);
	}
	for(i=0;i<=n-1;i++)
	{
		printf("%d\t",t[i]);
	}
	
	
}
void push(int stack[],int *top,int ch[])
{
			int x[100],n,i;
			*top=*top+1;
		    stack[*top]=ch;
		    //printf("\nYour integer is added to the stack\n");   
}
int pop(int stack[],int *top)
	{
		 int poped;
         poped=stack[*top];
         *top=*top-1;
         
         
	}
int Top(int stack[], int *top)
{
   		printf("The Stack of top is %d",stack[*top]);
	
}
int IsFull(int stack[],int *top)
{
	if(*top==SIZE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int IsEmpty(int stack[],int *top)
{
	if(*top==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Count(int *top)
{
	return *top;
}
int size()
{
	return SIZE;
}
int display(int *top,int stack[])
{
	int i,fact=1;
	for(i=*top;i>0;--i)
	{
		printf("%d\n",stack[i]);
		
	}
	for(i=*top;i>0;--i)
	{
	fact=fact*stack[i];
	}
	printf("\nfactorial : %d\n",fact);
}
