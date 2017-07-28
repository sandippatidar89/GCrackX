#include<stdio.h>
#include<stdlib.h>

struct Hash
{
	int key;
	int value;
	struct Hash *left,*right;
	int height;
};
struct Hash *map = NULL;
int height(struct Hash *root)
{
	if(root)
		return root->height;
	return -1;
}
int max(int a, int b)
{
	return a>b?a:b;
}
void setHeight(struct Hash *root)
{
	root->height=max(height(root->left),height(root->right))+1;
}
struct Hash * rotateLeft(struct Hash *root)
{
	struct Hash *newroot = root->left;
	root->left=newroot->right;
	newroot->right=root;
	setHeight(newroot);
	setHeight(root);
	return newroot;
}
struct Hash * rotateRight(struct Hash *root)
{
	struct Hash *newroot=root->right;
	root->right=newroot->left;
	newroot->left=root;
	setHeight(newroot);
	setHeight(root);
	return newroot;
}
struct Hash * doubleRotateLeft(struct Hash *root)
{
	root->left = rotateRight(root->left);
	return rotateLeft(root);
}
struct Hash * doubleRotateRight(struct Hash *root)
{
	root->right =rotateLeft(root->right);
	return rotateRight(root);
}
struct Hash *newNode(int value,int key)
{
	struct Hash *temp = (struct Hash*)malloc(sizeof(struct Hash));
	temp->value=value;
	temp->key=key;
	temp->left=temp->right=NULL;
	temp->height=0;
	return temp;
}
struct Hash * insert(struct Hash *root, int value, int key)
{
	if(root == NULL)
	{
		root = newNode(value,key);
	}
	else if(key<root->key)
	{
		root->left= insert(root->left,value,key);
		if(height(root->left)-height(root->right)==2)
		{
			if(value<root->left->value)
				root =  rotateLeft(root);
			else
				root = doubleRotateLeft(root);
		}
	}
	else if(key > root->key)
	{
		root->right= insert(root->right,value,key);
		if(height(root->right)-height(root->left)==2)
		{
			if(value > root->right->value)
				root = rotateRight(root);
			else
				root = doubleRotateRight(root);
		}
	}
	else
	{
		root->value=value;
	}
	setHeight(root);
	return root;
}
void inOrder(struct  Hash *root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		printf("key = %d : value = %d\n",root->key,root->value);
		inOrder(root->right);
		
	}
}
struct Hash * search(struct Hash *root,int key)
{
	if(root == NULL) 
		return root;
	else if(root->key == key) 
		return root;
	struct Hash *found = search(root->left,key);
	if(found) 
		return found;
	search(root->right,key);
}

void get(int key)
{
	struct Hash * temp = search(map,key);
	if(temp)
		printf("\nKey : %d value : %d",key,temp->value);
	else
		printf("\nException Occured :P");
}
void put(int key,int value)
{
	map = insert(map,value,key);
}
void hasKey(int key)
{
	struct Hash * temp = search(map,key);
	if(temp)
		printf("\nKey:%d Found",key);
	else
		printf("\nkey:%d Not Found",key);
}
void printMap()
{
	inOrder(map);
}

int main()
{
	 put(60,600);
	 put(80,800);
	 put(65,650);
	 put(90,900);
	 put(100,1000);
	 put(80,8);
	 put(70,700);
	 put(20,200);
	 put(30,300);
	 put(60,6);
	 printf("\t***HASH MAP***\n");
	 printMap();
	 hasKey(70);
	 hasKey(35);
	 get(80);
	 get(85);
	 printf("\n");
	 
	 return 0;
}
