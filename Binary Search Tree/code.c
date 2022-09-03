#include <stdio.h>
#include <stdlib.h>

/*
https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
*/

struct node{
	
	int key;
	struct node *left, *right;

};

struct LL{
	
	int key;
	
	struct LL *next;
};

typedef struct LL LL;
LL *hdr;

struct node *newNode(int item){ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
 
struct node* insert(struct node* node, int key){ 
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 

	/* return the (unchanged) node pointer */
	return node; 
} 

int insertLL(struct LL **hdr, int key){

	struct LL* newNode = (struct LL*)malloc(sizeof(struct LL));             
	struct LL *lastNode = *hdr;                                             
	
	newNode->key=key;	
	
	newNode->next = NULL;
	
	if(*hdr == NULL){                                                      
		*hdr = newNode;
		return;
	}
	
	while(lastNode->next != NULL)                                      
		lastNode = lastNode->next;
	
	lastNode->next = newNode;
	return;
}

int swap(LL *node1, LL *node2){
	
	int swap = node1->key;
	node1->key = node2->key;
	node2->key = swap;
}

int printLL(LL *node){
	
	while(node != NULL){
		printf("%d ", node->key);
		node=node->next;
	}
}

void inorder(struct node *root){ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d ", root->key); 
		inorder(root->right); 
	} 
} 

int isSimilar(struct node *root1, struct node *root2){
	
	if(root1->key == root2->key){
		if(isSimilar(root1->key, root2->key)){
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

int main(){
	
	struct node *root= NULL;
	struct node *root2=NULL;
	
	int input=1;
	
	printf("enter numbers\n");
	
	while (input != 0){
		scanf("%d", &input);
		root = insert(root, input);
		insertLL(&hdr,input);
	}
	inorder(root);
	printf("\n");
}



