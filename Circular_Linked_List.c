/*Circular Singly Linked List - Last Node in sll have link = NULL, the node may or maynot be linked properly, So we use Circular Linked list, Thats the Main Advantage of CSLL */
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
	n->link=first;
	
	if(temp==NULL)//inserting in an empty list
	{
		first=n;
		n->link=first;
		return;
	}
	while(temp->link!=first)
	{
		temp=temp->link;
	}
	temp->link=n;
	
}

display_csll()
{
	node *temp=first;
	if(temp==NULL)
	{
		printf("Empty List !\n");return;
	}

	while(temp->link!=first)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	if(temp->link==first)
		printf("%d ",temp->data);
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
	while(temp->link!=first)
	{
		if(x==temp->data)
		{
			printf("Element %d Found ! Position : %d \n",temp->data,pos);
			return;
		}
		pos++;
		temp=temp->link;
	}
	if(temp->link==first && temp->data==x){
		printf("Element %d Found ! Position : %d \n",temp->data,pos);return;}
	else//end of list
	{
		printf("Element not Found !\n");
	}
}

delete_node(int x)
{
	node *temp=first,*prev=NULL,*temp_2=NULL;
	if(temp==NULL)
	{
		printf("Empty List !\n");return;
	}
	/*while(temp!=first)//pointing *prev node to last
	{
		prev=temp;
		temp=temp->link;
	}*/
	while(temp->link!=first)
	{
		if(temp==first && x==temp->data)
		{
			first=temp->link;
			temp->link=NULL;
			
			{//to change the last node's link to the new first node of the list. BLOCK{} to differentiate from other functions
				temp_2=first;
				while(temp_2->link!=temp)
				{
					temp_2=temp_2->link;
				}
				temp_2->link=first;
			}
			
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
	if(temp->link==first && x==temp->data && prev!=NULL)
	{
		prev->link=first;
		temp->link=NULL;
		free(temp);
		return;
	}
	else
	{
		first=NULL;
		temp->link=NULL;
		free(temp);
		return;
	}
	if(temp->link==first)//end of list
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
		case 3:display_csll();break;
		case 4:printf("\nEnter an Element to Search : ");fflush(stdin);scanf("%d",&x);search_node(x);break;
		default:printf("Invalid Choice !");exit(1);
	
	}
	}while(ch<5);
}
