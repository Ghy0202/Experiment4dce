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
void DCEFunc15(void){};
void DCEFunc16(void){};
void DCEFunc17(void){};
void DCEFunc18(void){};
void DCEFunc19(void){};
void DCEFunc20(void){};
void DCEFunc21(void){};
void DCEFunc22(void){};
void DCEFunc23(void){};
void DCEFunc24(void){};
void DCEFunc25(void){};
void DCEFunc26(void){};
void DCEFunc27(void){};
void DCEFunc28(void){};
void DCEFunc29(void){};
void DCEFunc30(void){};
void DCEFunc31(void){};
void DCEFunc32(void){};
void DCEFunc33(void){};
void DCEFunc34(void){};
#include <stdio.h>
#include <stdlib.h>
#define NODESIZE 7
#define STARTNODE 0
#define QSIZE 1000

struct Node{

    int vertex;
    int height;
    struct Node *prev;
};

struct Node *queue[QSIZE];
int head,rear;
int qempty(void){
DCEFunc1();

    return head==rear;
}
int qfull(void){
DCEFunc2();

    return head==(rear+1)%QSIZE;
}
void enqueue(struct Node *item){
DCEFunc3();

    queue[rear]=item;
    rear=(rear+1)%QSIZE;
}
struct Node *dequeue(void){
DCEFunc4();

    struct Node *retval=queue[head];
    head=(head+1)%QSIZE;
    return retval;
}

int isneibor(int (*map)[NODESIZE],int node1,int node2){
DCEFunc5();

    return map[node1][node2];
}

void getneibors(int (*map)[NODESIZE],int node,int *neibors,int *size){
DCEFunc6();

    int counter=0,i;
    for(i=0;i<NODESIZE;i++)
        if(map[node][i])
            neibors[counter++]=i;
    *size=counter;
}

void displayoutcome(int *answer){
DCEFunc7();

    int i;
    for(i=0;i<NODESIZE;i++)
        printf("%d ", answer[i]);
    printf("%d\n",STARTNODE );
}

int inme(struct Node *node,int who){
DCEFunc8();

    int ok=0;
    while(node && !ok){
DCEFunc9();

        if(node->vertex==who)
            ok=1;
        node=node->prev;
    }
    return ok;
}

void displayout_come(struct Node *node){
DCEFunc10();

    printf("%d ",STARTNODE );
    while(node){
DCEFunc11();

        printf("%d ",node->vertex );
        node=node->prev;
    }
    printf("\n");
}

void bfs_search(int (*map)[NODESIZE]){
DCEFunc12();

    int i,step;
    struct Node *currentnode=malloc(sizeof(struct Node));
    currentnode->vertex=STARTNODE,currentnode->prev=NULL,currentnode->height=0;
    enqueue(currentnode);
    int neibors[NODESIZE],neiborsize;
    struct Node *node;
    while(!qempty()){
DCEFunc13();

        currentnode=dequeue();
        step=currentnode->height;
        if(step==NODESIZE-1 && isneibor(map,currentnode->vertex,STARTNODE)){
DCEFunc14();

            displayout_come(currentnode);
            //break;
        }
        getneibors(map,currentnode->vertex,neibors,&neiborsize);
        for(i=0;i<neiborsize;i++)
            if(!inme(currentnode,neibors[i])){
DCEFunc15();

                node=malloc(sizeof(struct Node));
                node->height=step+1,node->prev=currentnode,node->vertex=neibors[i];
                enqueue(node);
            }
    }
}
#define STACKSIZE 100
struct Node *stack[STACKSIZE];
int sp=-1;
int sempty(void){
DCEFunc16();

    return sp==-1;
}
void push(struct Node *item){
DCEFunc17();

    stack[++sp]=item;
}
struct Node *pop(void){
DCEFunc18();

    return stack[sp--];
}
struct Node *top(void){
DCEFunc19();

    return stack[sp];
}

void dfs_search(int (*map)[NODESIZE]){
DCEFunc20();

    struct Node *currentnode=malloc(sizeof(struct Node));
    currentnode->vertex=STARTNODE,currentnode->height=0,currentnode->prev=NULL;
    push(currentnode);
    int neiborsize,neibors[NODESIZE],i;
    struct Node *node;
    while(!sempty()){
DCEFunc21();

        currentnode=top();
        if(currentnode->height==NODESIZE-1 && isneibor(map,currentnode->vertex,STARTNODE)){
DCEFunc22();

            displayout_come(currentnode);
            //break;
        }
        pop();
        getneibors(map,currentnode->vertex,neibors,&neiborsize);
        for(i=0;i<neiborsize;i++)
            if(!inme(currentnode,neibors[i])){
DCEFunc23();

                node=malloc(sizeof(struct Node));
                node->vertex=neibors[i],node->height=currentnode->height+1,node->prev=currentnode;
                push(node);
            }
    }
}

void backtrace(int (*map)[NODESIZE],int *answer,int step,int *visited){
DCEFunc24();

    if(step==NODESIZE && isneibor(map,answer[step-1],STARTNODE)){
DCEFunc25();

        displayoutcome(answer);
        return;
    }
    int myneibor[NODESIZE],neiborsize,currentnode=answer[step-1],i;
    getneibors(map,currentnode,myneibor,&neiborsize);
    for(i=0;i<neiborsize;i++)
        if(!visited[myneibor[i]]){
DCEFunc26();

            answer[step]=myneibor[i];
            visited[myneibor[i]]=1;
            backtrace(map,answer,step+1,visited);
            visited[myneibor[i]]=0;
        }
}

int main(){
DCEFunc27();

    int map[NODESIZE][NODESIZE]={
        {

0,1,0,0,0,1,1},
        {

1,0,0,0,0,1,0},
        {

0,0,0,1,1,0,0},
        {

0,0,1,0,1,0,1},
        {

0,0,1,1,0,1,0},
        {

1,1,0,0,1,0,0},
        {

1,0,0,1,0,0,0}
    };
    int answer[NODESIZE];
    answer[0]=STARTNODE;
    int visited[NODESIZE]={};
    visited[STARTNODE]=1;
    printf("use backtrace:\n");
    backtrace(map,answer,1,visited);
    printf("use DFS:\n");
    dfs_search(map);
    printf("use BFS:\n");
    bfs_search(map);
}