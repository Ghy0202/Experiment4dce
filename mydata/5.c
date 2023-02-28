void DCEFunc0(void){};
void DCEFunc1(void){};
void DCEFunc2(void){};
void DCEFunc3(void){};
void DCEFunc4(void){};
void DCEFunc5(void){};
void DCEFunc6(void){};
void DCEFunc7(void){};
void DCEFunc8(void){};
void DCEFunc9(void){};
void DCEFunc10(void){};
void DCEFunc11(void){};
void DCEFunc12(void){};
void DCEFunc13(void){};
void DCEFunc14(void){};
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NODESIZE 13
#define SOURCE 0
#define DEST 12
#define QSIZE 100

struct Node{


	int id;
	int vertex;
	struct Node *next;
};

struct TNode{


	int cost;
	int id;
	struct TNode *prev;
};

struct TNode *stack[QSIZE];
int sp=-1;
void push(struct TNode *item){
DCEFunc2();

	stack[++sp]=item;
}
struct TNode *pop(void){


	return stack[sp--];
}
struct TNode *top(void){


	return stack[sp];
}
int empty(void){
DCEFunc5();

	return sp==-1;
}

void insertsort(struct TNode **data,int size){
DCEFunc6();

	struct TNode *pivot;
	int i,j;
	for(i=1;i<size;i++){
DCEFunc7();

		pivot=data[i];
		for(j=i-1;j>=0 && data[j]->cost < pivot->cost;j--)
			data[j+1]=data[j];
		data[j+1]=pivot;
	}
}

int min=INT_MAX;

void displayoutcome(struct TNode *node){
DCEFunc8();

	min=node->cost;
	while(node){
DCEFunc9();

		printf("%d<==",node->id);
		node=node->prev;
	}
	printf("cost=%d\n",min );
}

void branchbound(struct Node **map){
DCEFunc10();

	struct TNode *currentnode=malloc(sizeof(struct TNode));
	currentnode->id=SOURCE,currentnode->cost=0,currentnode->prev=NULL;
	push(currentnode);
	struct Node *neibor;
	struct TNode *nextnode, * neibors[NODESIZE];
	int neiborsize,i;
	while(!empty()){
DCEFunc11();

		currentnode=top();
		if(currentnode->id==DEST && currentnode->cost<min)
			displayoutcome(currentnode);
		pop();
		if(currentnode->cost>min)
			continue;
		neibor=map[currentnode->id];
		neiborsize=0;
		while(neibor){
DCEFunc12();

			nextnode=malloc(sizeof(struct TNode));
			nextnode->id=neibor->id,nextnode->prev=currentnode;
			nextnode->cost=currentnode->cost+neibor->vertex;
			neibors[neiborsize++]=nextnode;
			neibor=neibor->next;
		}
		insertsort(neibors,neiborsize);
		for(i=0;i<neiborsize;i++)
			push(neibors[i]);
	}
}

void insertedge(struct Node **map,int node1,int node2,int vertex){
DCEFunc13();

	struct Node *cur=map[node1];
	struct Node *new=malloc(sizeof(struct Node));
	new->id=node2,new->vertex=vertex,new->next=cur;
	map[node1]=new;
}

int main(int argc, char const *argv[]){
DCEFunc14();

	struct Node *map[NODESIZE]={};
	insertedge(map,SOURCE,1,2);
	insertedge(map,SOURCE,2,5);
	insertedge(map,SOURCE,3,1);
	insertedge(map,SOURCE,4,6);
	insertedge(map,1,5,1);
	insertedge(map,1,5,4);
	insertedge(map,2,5,9);
	insertedge(map,2,7,7);
	insertedge(map,3,5,3);
	insertedge(map,3,7,4);
	insertedge(map,4,6,7);
	insertedge(map,4,7,4);
	insertedge(map,5,8,6);
	insertedge(map,5,10,7);
	insertedge(map,6,8,4);
	insertedge(map,6,9,3);
	insertedge(map,6,11,5);
	insertedge(map,7,9,1);
	insertedge(map,7,10,4);
	insertedge(map,7,11,5);
	insertedge(map,8,DEST,3);
	insertedge(map,9,DEST,1);
	insertedge(map,10,DEST,2);
	insertedge(map,11,DEST,5);
	branchbound(map);
	return 0;
}
