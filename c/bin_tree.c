#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define TRUE 1
#define ADDTREEELEMENTS 1
#define IN 2
#define PRE 3
#define POST 4
#define QUIT 5

typedef struct link_list
{
	char str[10];
	struct link_list *ll,*rl;
}node;

void addtree(node **root,char *str)
{
	if(*root==NULL)
	{
		*root=(node*)malloc(sizeof(node));
		(*root)->rl=NULL;(*root)->ll=NULL;
		strcpy((*root)->str,str);
		return;
	}
	else
	{
		if(strcmp((*root)->str,str)<0)
			addtree(&(*root)->rl,str);
		else
			addtree(&(*root)->ll,str);
	}
	return;
}

void inorder(node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->ll);
		printf("%s, ",temp->str);
		inorder(temp->rl);
	}
	else
		return;
}

void preorder(node *temp)
{
	if(temp!=NULL)
	{
		printf("%s, ",temp->str);
		preorder(temp->ll);
		preorder(temp->rl);
	}
	else
		return;
}
void postorder(node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->ll);
		postorder(temp->rl);
		printf("%s, ",temp->str);
	}
	else
		return;
}
void freenode(node *temp)
{
	if(temp!=NULL)
	{
		freenode(temp->ll);
		freenode(temp->rl);
		free(temp);
	}
	else
		return;
}

int main()
{
	char buff[2];
	int choice,loop=0,str[10];
	node *root=NULL;
	system("clear");
	printf("\n\'1\'		FOR ADDING ELEMENT TO TREE"\
		"\n\'2\'		FOR DIPLAYING IN INORDER"\
		"\n\'3\'		FOR DIPLAYING IN PREORDER"\
		"\n\'4\'		FOR DIPLAYING IN POSTORDER"\
		"\n\'5\'		FOR QUITING");
	while(TRUE)
	{
		printf("\n ENTER THE CHOICE	:",root);
		scanf("%s",buff);
		if(buff[1]!='\0')
			buff[0]='a';
		choice=atoi(buff);
		switch(choice)
		{
		case ADDTREEELEMENTS:
			{
				printf("\nENTER THE STRING TO ADD TO BINARY TREE	:");
				scanf("%s",str);
				addtree(&root,str);
				break;
			}
		case IN:
			{
				printf("\n");
				inorder(root);
				printf("\n");
				break;
			}
		case PRE:
			{
				printf("\n");
				preorder(root);
				printf("\n");
				break;
			}
		case POST:
			{
				printf("\n");
				postorder(root);
				printf("\n");
				break;
			}
		case QUIT:
			{
				freenode(root);
				exit(0);
			}
		default:
			printf("\nINVALID CHOICE");
		}
	}
	return 0;
}
