#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ADD 1
#define PREORDER 2
#define POSTORDER 3
#define INORDER 4
#define FREE 5
#define DELETE 6
typedef struct b_tree {
	int num;
	struct b_tree *lt;
	struct b_tree *rt;
}B_TREE;
void add_tree(B_TREE **root, int num)
{
	if(*root==NULL)
	{
		*root=(B_TREE*)malloc(sizeof(B_TREE));
		(*root)->rt=NULL;(*root)->lt=NULL;
		(*root)->num =num;
		return;
	}
	else
	{
		if((*root)->num < num)
			add_tree(&(*root)->rt,num);
		else
			add_tree(&(*root)->lt,num);
	}
	return;
}
void addtree(B_TREE**rt)
{
	int num;
	printf("Enter no to add to tree:");
	scanf("%d",&num);
	add_tree(rt,num);
#if 0
	B_TREE *tmp = NULL,*add;
	tmp = (B_TREE*)malloc(sizeof(B_TREE));
	if(!tmp){
		printf("memory allocation Failure!!\n");
		return;
	}
	tmp->lt = NULL;
	tmp->rt	= NULL;
	printf("Enter no to add to tree:");
	scanf("%d",&tmp->num);
	if(!*rt)
		*rt = tmp;
	else{
		for(add = *rt;(*rt)->lt || (*rt)->rt;
			tmp->num > (*rt)->num ? (*rt)->rt ? 
			add =(*rt)->rt 
			: (*rt)->rt = tmp : 
		(*rt)->lt ? add = (*rt)->lt :
			(*rt)->lt = tmp);
	}
#endif

}
void inorder(B_TREE *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->lt);
		printf("%d - ",temp->num);
		inorder(temp->rt);
	}
	else
		return;
}

void preorder(B_TREE *temp)
{
	if(temp!=NULL)
	{
		printf("%d - ",temp->num);
		preorder(temp->lt);
		preorder(temp->rt);
	}
	else
		return;
}
void postorder(B_TREE *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->lt);
		postorder(temp->rt);
		printf("%d - ",temp->num);
	}
	else
		return;
}
void freenode(B_TREE *temp)
{
	if(temp!=NULL)
	{
		freenode(temp->lt);
		freenode(temp->rt);
		free(temp);
	}
	else
		return;
}
void delete_node (B_TREE *root, int num)
{
	B_TREE *parent = NULL,*nd_todel,*tmp;
	for(;root && root->num != num;parent = root,root = 	root->num > num ? root->lt : root->rt);
	if(!root){
		printf("no not found in tree\n");
		return;
	}
	nd_todel = root;
	printf("deleting %d\n",nd_todel->num);
	if(nd_todel->lt && nd_todel->rt){
		for(tmp = nd_todel->lt; tmp->rt; tmp = tmp->rt);
		if(parent->num < num)
			parent->rt = nd_todel->lt;
		else
			parent->lt = nd_todel->lt;
		tmp->rt	= nd_todel->rt;
		printf("parent %d left %d right %d\n",parent->num,parent->lt->num,parent->rt->num);
		free(nd_todel);
		nd_todel = NULL;
	}
}
int main()
{
	int choice,quit = 0,num;
	B_TREE *rt = NULL;
	system("cls");
	while(!quit){
		printf("ENTER chioce :");
		scanf("%d",&choice);
		switch(choice){
		case ADD:
			addtree(&rt);
			break;
#if 1
		case PREORDER:
			preorder(rt);
			printf("\n");
			break;
		case POSTORDER:
			postorder(rt);
			printf("\n");
			break;
		case INORDER:
			inorder(rt);
			printf("\n");
			break;
		case FREE:
			freenode(rt);
			rt =NULL;
			quit =1;
			break;
		case DELETE:
			printf("ENTER no to be deleted:");
			scanf("%d",&num);
			delete_node(rt,num);
			break;
#endif
		}
	}
	return 0;
}


	#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ADD 1
#define PREORDER 2
#define POSTORDER 3
#define INORDER 4
#define FREE 5
#define DELETE 6
typedef struct b_tree {
	int num;
	struct b_tree *lt;
	struct b_tree *rt;
}B_TREE;
void add_tree(B_TREE **root, int num)
{
	if(*root==NULL)
	{
		*root=(B_TREE*)malloc(sizeof(B_TREE));
		(*root)->rt=NULL;(*root)->lt=NULL;
		(*root)->num =num;
		return;
	}
	else
	{
		if((*root)->num < num)
			add_tree(&(*root)->rt,num);
		else
			add_tree(&(*root)->lt,num);
	}
	return;
}
void addtree(B_TREE**rt)
{
	int num;
	printf("Enter no to add to tree:");
	scanf("%d",&num);
	add_tree(rt,num);
#if 0
	B_TREE *tmp = NULL,*add;
	tmp = (B_TREE*)malloc(sizeof(B_TREE));
	if(!tmp){
		printf("memory allocation Failure!!\n");
		return;
	}
	tmp->lt = NULL;
	tmp->rt	= NULL;
	printf("Enter no to add to tree:");
	scanf("%d",&tmp->num);
	if(!*rt)
		*rt = tmp;
	else{
		for(add = *rt;(*rt)->lt || (*rt)->rt;
			tmp->num > (*rt)->num ? (*rt)->rt ? 
			add =(*rt)->rt 
			: (*rt)->rt = tmp : 
		(*rt)->lt ? add = (*rt)->lt :
			(*rt)->lt = tmp);
	}
#endif

}
void inorder(B_TREE *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->lt);
		printf("%d - ",temp->num);
		inorder(temp->rt);
	}
	else
		return;
}

void preorder(B_TREE *temp)
{
	if(temp!=NULL)
	{
		printf("%d - ",temp->num);
		preorder(temp->lt);
		preorder(temp->rt);
	}
	else
		return;
}
void postorder(B_TREE *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->lt);
		postorder(temp->rt);
		printf("%d - ",temp->num);
	}
	else
		return;
}
void freenode(B_TREE *temp)
{
	if(temp!=NULL)
	{
		freenode(temp->lt);
		freenode(temp->rt);
		free(temp);
	}
	else
		return;
}
void delete_node (B_TREE *root, int num)
{
	B_TREE *parent = NULL,*nd_todel,*tmp;
	for(;root && root->num != num;parent = root,root = 	root->num > num ? root->lt : root->rt);
	if(!root){
		printf("no not found in tree\n");
		return;
	}
	nd_todel = root;
	printf("deleting %d\n",nd_todel->num);
	if(nd_todel->lt && nd_todel->rt){
		for(tmp = nd_todel->lt; tmp->rt; tmp = tmp->rt);
		if(parent->num < num)
			parent->rt = nd_todel->lt;
		else
			parent->lt = nd_todel->lt;
		tmp->rt	= nd_todel->rt;
		printf("parent %d left %d right %d\n",parent->num,parent->lt->num,parent->rt->num);
		free(nd_todel);
		nd_todel = NULL;
	}
	else if (nd_todel->lt){
		for(tmp = nd_todel->lt; tmp->rt; tmp = tmp->rt);
		if(parent->num < num)
			parent->rt = nd_todel->lt;
		else
			parent->lt = nd_todel->lt;
		printf("parent %d left %d right %d\n",parent->num,parent->lt->num,parent->rt->num);
		free(nd_todel);
		nd_todel = NULL;
	}
	else if (nd_todel->rt){
		if(parent->num < num)
			parent->rt = nd_todel->rt;
		else
			parent->lt = nd_todel->rt;
		printf("parent %d left %d right %d\n",parent->num,parent->lt->num,parent->rt->num);
		free(nd_todel);
		nd_todel = NULL;
	}
	else{
		if(parent->num < num)
			parent->rt = NULL;
		else
			parent->lt = NULL;
		free(nd_todel);
		nd_todel = NULL;
	}
}
int main()
{
	int choice,quit = 0,num;
	B_TREE *rt = NULL;
	system("cls");
	while(!quit){
		printf("ENTER chioce :");
		scanf("%d",&choice);
		switch(choice){
		case ADD:
			addtree(&rt);
			break;
#if 1
		case PREORDER:
			preorder(rt);
			printf("\n");
			break;
		case POSTORDER:
			postorder(rt);
			printf("\n");
			break;
		case INORDER:
			inorder(rt);
			printf("\n");
			break;
		case FREE:
			freenode(rt);
			rt =NULL;
			quit =1;
			break;
		case DELETE:
			printf("ENTER no to be deleted:");
			scanf("%d",&num);
			delete_node(rt,num);
			break;
#endif
		}
	}
	return 0;
}


	