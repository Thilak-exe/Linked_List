#include<stdio.h>
#include<stdlib.h>
typedef struct llnode
{
	int data;
	struct llnode *link;
}node;
node *first; //global variable

insert_node(int x)
{
	node *temp=first;
	node *n=(node*)malloc(sizeof(node));
	
	n->data=x;
	n->link=NULL;
	
	if(temp==NULL)
	{
		first=n;
		return;
	}
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=n;
	
}

display_sll()
{
	node *temp=first;
	if(temp==NULL)
	{
		printf("Empty List !\n");return;
	}

	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}

search_node(int x)
{
	int pos=1;
	node *temp=first;
	if(temp==NULL)
	{
		printf("Empty List !\n");return;
	}
	while(temp!=NULL)
	{
		if(x==temp->data)
		{
			printf("Element %d Found ! Position : %d \n",temp->data,pos);
			return;
		}
		pos++;
		temp=temp->link;
	}
	if(temp==NULL)//end of list
	{
		printf("Element not Found !\n");
	}
}

delete_node(int x)
{
	node *temp=first,*prev=NULL;
	if(temp==NULL)
	{
		printf("Empty List !\n");return;
	}
	while(temp!=NULL)
	{
		if(temp==first && x==temp->data)
		{
			first=temp->link;
			temp->link=NULL;
			free(temp);
			return;
		}
		if(x==temp->data)
		{
			prev->link=temp->link;
			temp->link=NULL;
			free(temp);
			return;
		}
		prev=temp;
		temp=temp->link;
	}
	if(temp==NULL)//end of list
	{
		printf("Element not Found !\n");
	}
}

void main()
{
	int ch,x;

	
	do
	{	
	printf("\n>> 1.Insert | 2.Delete | 3.Display | 4.Search <<\n");
	printf("Enter choice :");
	scanf("%d",&ch);
	fflush(stdin);
	switch(ch)
	{
		case 1: printf("\nEnter an Element to Insert : ");fflush(stdin);scanf("%d",&x); insert_node(x); break;
		case 2: printf("\nEnter an Element to Delete : ");fflush(stdin);scanf("%d",&x); delete_node(x); break;
		case 3:display_sll();break;
		case 4:printf("\nEnter an Element to Search : ");fflush(stdin);scanf("%d",&x);search_node(x);break;
		default:printf("Invalid Choice !");exit(1);
	
	}
	}while(ch<5);
}
