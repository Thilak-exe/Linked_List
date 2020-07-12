#include<stdio.h>
#include<stdlib.h>

typedef struct dllnode
{
	int data;
	struct dllnode *bwd;
	struct dllnode *fwd;
}node;
node *first=NULL,*last=NULL;// Actually we shouldn't use Global Variable... as Anyone can access it... Leading to loss of Data Privacy

traverse_to_last()
{
	node *temp=first;
	while(temp->fwd!=NULL)
	{
		temp=temp->fwd;
	}
	last=temp;
}

void insert_node(int x)
{
	node *n=(node*)malloc(sizeof(node));
	node *temp=first,*prev=NULL;
	n->data=x;
	n->bwd=NULL;
	n->fwd=NULL;
	
	if(temp==NULL)
	{
		first=n;
		return;
	}
	
	if(temp->fwd==NULL && temp==first)
	{
		temp->fwd=n;
		n->bwd=temp;
		n->fwd=NULL;
	}
	
	while(temp->fwd!=NULL)
	{
		prev=temp;
		temp=temp->fwd;
		temp->bwd=prev;
	}
	temp->fwd=n;
	n->bwd=temp;
	n->fwd=NULL;
	traverse_to_last();
	
}

void display_dll_lr()
{
	node *temp=first;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->fwd;
	}
	printf("\n");
}

void display_dll_rl()
{
	node *temp=last;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->bwd;
	}
	printf("\n");
}
void search_node(int x)
{
	node *temp=first; int count=1;
	
	while(temp->fwd!=NULL)
	{
		if(temp->data==x)
		{
			printf("Element %d Found ! Position : %d\n",temp->data,count);
			return;
		}
		count++;
		temp=temp->fwd;
	}
	if(temp->fwd==NULL && temp->data==x)
	{
		printf("Element %d Found ! Position : %d\n",temp->data,count);
		return;
	}
	else
	{
		printf("Element not Found !\n");
		return;
	}
}
delete_dll_node(int x)
{
	node *prev=NULL,*next=NULL,*temp=first;
	if(temp==first && temp->data==x)
	{
		first=temp->fwd;
		free(temp);
		temp=first;
		temp->bwd=NULL;
		return;
	}
	while(temp->fwd!=NULL)
	{
		next=temp->fwd;
		
		if(temp->data==x)
		{
			prev->fwd=temp->fwd;
			next->bwd=temp->bwd;
			temp->bwd=temp->fwd=NULL;
			free(temp);
			return;
		}
		
		prev=temp;
		temp=temp->fwd;
	}
	
	if(temp==next && temp->data==x)//end of the list
	{
		last=temp->bwd;
		prev->fwd=NULL;
		temp->fwd=NULL;
		temp->bwd=NULL;
		free(temp);
		return;
	}
	else
	{
		printf("Element %d not Found in the List !!! \n",x);
		return;
	}
	
}

void main()
{
	int ch,x;
	
	do
	{	
	printf(" -----------------------------\n| 1.Insert                    |\n| 2.Delete                    | \n| 3.Display L-R               |\n| 4.Display R-L (Reversely)   | \n| 5.Search                    | \n -----------------------------\n");
	printf("Enter choice :");
	scanf("%d",&ch);
	fflush(stdin);
	switch(ch)
	{
		case 1: printf("\nEnter an Element to Insert : ");fflush(stdin);scanf("%d",&x); insert_node(x); break;
		case 2: printf("\nEnter an Element to Delete : ");fflush(stdin);scanf("%d",&x); delete_dll_node(x); break;
		case 3: display_dll_lr();break;
		case 4: display_dll_rl();break;
		case 5: printf("\nEnter an Element to Search : ");fflush(stdin);scanf("%d",&x);search_node(x);break;
		default:printf("Invalid Choice !");exit(1);
	
	}
	}while(ch<=5);
}
