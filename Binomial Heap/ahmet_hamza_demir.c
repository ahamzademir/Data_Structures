#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ll{
	
	char PID[4];
	int e;
	int t;
	
	struct ll* next;
	
};

typedef struct ll ll;
ll *hdr;

int print(ll* node){
	
	while(node->next != NULL){
		
		printf(" %s %d %d ", node->PID, node->e, node->t);
		node=node->next;
	
	}
	
}

int readFile(char fileName[]){
	
	char ch;
	FILE *fp;
	
	fp = fopen(fileName, "r");
	
	char PID[4];
	int e;
	int t;

	while (!feof(fp)) {

        fscanf(fp, "%s", PID);
        fscanf(fp, "%d", &e);
        fscanf(fp, "%d", &t);
        
        insertll(&hdr, PID, e, t);
    }
	
	fclose(fp);

}

int insertll(struct ll **hdr, char PID[], int e, int t) {
	
	struct ll* newNode = (struct ll*)malloc(sizeof(struct ll));             
	struct ll *lastNode = *hdr;   
	
	strcpy(newNode->PID, PID);
	newNode->e=e;
	newNode->t=t;                                          
	
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

int getSize(ll* node) {

	int size = 0;
	
	while(node != NULL){
		
		int n= node->e;
		size += (n*(n+1))/2;
		
		node=node->next;
	}
	return size;
}

void deleteNode(ll **head_ref) { 
   // If linked list is empty 
   if (*head_ref == NULL) 
      return; 
    
   // Store head node 
   struct ll* temp = *head_ref; 
  
    // If head needs to be removed 
    if (temp->e <= 0) { 
        *head_ref = temp->next;   // Change head 
        free(temp);               // free old head 
        return; 
    } 
    //printf("%d", temp->next->e);
    // Find previous node of the node to be deleted 
    while (temp!=NULL && temp->next->e <= 0) 
         temp = temp->next; 
  
    // If position is more than number of nodes 
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    // Node temp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    struct ll *next = temp->next->next; 

}

int findMaxE(ll* node) {
	
	int max = 0;
	
	
	while(node != NULL){
		if(node->e > max){
			max = node->e;
		}
		node = node->next;
	}
	return max;
	
}

int findMinT(ll* node) {
	
	int minT = 999;
	
	while(node->next != NULL){
		if(node->t <= minT){
			minT = node->t;
		}
		node = node->next;
	}
	
	return minT;
}

int process(ll* node, int q) {
		
	int min = findMinT(node);
	
	while(node->t != min)
		node = node->next;
	
	printf("%s ", node->PID);
	
	node->t += q;
	node->e -= q;
	
	deleteNode(&hdr);
	process(hdr, q);
}

int main(){
	
	char fileName[10]="input.txt";
	readFile(fileName);

	int q;
	printf("enter q ");
	scanf("%d", &q);
	
	process(hdr,q);
	
	
}
