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
void DCEFunc35(void){};
#include <stdio.h>
#include <stdlib.h>
#define CUBE 3

int cube_equal(int (*m1)[CUBE],int (*m2)[CUBE]){
DCEFunc0();

    int i,j,ok=1;
    for(i=0;i<CUBE && ok;i++)
        for(j=0;j<CUBE && ok;j++)
            if(m1[i][j]!=m2[i][j])
                ok=0;
    return ok;
}

void cube_copy(int (*source)[CUBE],int (*dest)[CUBE]){
DCEFunc1();

    int i,j;
    for(i=0;i<CUBE;i++)
        for(j=0;j<CUBE;j++)
            dest[i][j]=source[i][j];
}

void cube_display(int (*m)[CUBE]){
DCEFunc2();

    int i,j;
    for(i=0;i<CUBE;i++){
DCEFunc3();

        for(j=0;j<CUBE;j++)
            printf("%d ",m[i][j]);
        printf("\n");
    }
}

void move_up(int (*m)[CUBE],int x,int y){
DCEFunc4();

    m[x][y]=m[x-1][y],m[x-1][y]=-1;
}

void move_down(int (*m)[CUBE],int x,int y){
DCEFunc5();

    m[x][y]=m[x+1][y],m[x+1][y]=-1;
}

void move_left(int (*m)[CUBE],int x,int y){
DCEFunc6();

    m[x][y]=m[x][y-1],m[x][y-1]=-1;
}

void move_right(int (*m)[CUBE],int x,int y){
DCEFunc7();

    m[x][y]=m[x][y+1],m[x][y+1]=-1;
}

struct Node{


    int cube[CUBE][CUBE];
    int x;
    int y;
    struct Node *prev;
};

void displayoutcome(struct Node *node){
DCEFunc9();

    while(node){
DCEFunc10();

        cube_display(node->cube);
        printf("^\n");
        printf("^\n");
        printf("^\n");
        node=node->prev;
    }
}

int inme(struct Node *node,int (*m)[CUBE]){
DCEFunc11();

    int ok=0;
    while(node && !ok){
DCEFunc12();

        if(cube_equal(node->cube,m))
            ok=1;
        node=node->prev;
    }
    return ok;
}

#define QSIZE 10000
struct Node *queue[QSIZE];
int head,rear;
int queue_empty(void){
DCEFunc13();

    return head==rear;
}
int full(void){
DCEFunc14();

    return head==(rear+1)%QSIZE;
}
void enqueue(struct Node *item){
DCEFunc15();

    queue[rear]=item;
    rear=(rear+1)%QSIZE;
}
struct Node *dequeue(void){
DCEFunc16();

    struct Node *retval=queue[head];
    head=(head+1)%QSIZE;
    return retval;
}
struct Node *queue_top(void){
DCEFunc17();

    return queue[head];
}

void bfs_search(int (*cube)[CUBE],int x,int y,int (*target)[CUBE]){
DCEFunc18();

     struct Node *currentnode=malloc(sizeof(struct Node));
    currentnode->x=x,currentnode->y=y,currentnode->prev=NULL;
    cube_copy(cube,currentnode->cube);
    enqueue(currentnode);
    struct Node *node;
    int tmpcube[CUBE][CUBE];
    int counter=0;
    while(!queue_empty()){
DCEFunc19();

        currentnode=queue_top();
        if(cube_equal(currentnode->cube,target)){
DCEFunc20();

            printf("One method .....\n");
            displayoutcome(currentnode);
            counter+=1;
            //break;
        }
        dequeue();
        //up
        cube_copy(currentnode->cube,tmpcube);
        if(currentnode->x > 0){
DCEFunc21();

            move_up(tmpcube,currentnode->x,currentnode->y);
            if(!inme(currentnode,tmpcube)){
DCEFunc22();

             //   printf("UP!\n");
                node=malloc(sizeof(struct Node));
                cube_copy(tmpcube,node->cube);
                node->x=currentnode->x-1,node->y=currentnode->y;
                node->prev=currentnode;
                enqueue(node);
            }
        }
        //down
        cube_copy(currentnode->cube,tmpcube);
        if(currentnode->x <CUBE-1){
DCEFunc23();

            move_down(tmpcube,currentnode->x,currentnode->y);
            if(!inme(currentnode,tmpcube)){
DCEFunc24();

                //printf("DOWN!\n");
                node=malloc(sizeof(struct Node));
                cube_copy(tmpcube,node->cube);
                node->x=currentnode->x+1,node->y=currentnode->y;
                node->prev=currentnode;
                enqueue(node);
            }
        }
        //left
        cube_copy(currentnode->cube,tmpcube);
        if(currentnode->y > 0){
DCEFunc25();

           move_left(tmpcube,currentnode->x,currentnode->y);
            if(!inme(currentnode,tmpcube)){
DCEFunc26();

               // printf("LEFT\n");
                node=malloc(sizeof(struct Node));
                cube_copy(tmpcube,node->cube);
                node->x=currentnode->x,node->y=currentnode->y-1;
                node->prev=currentnode;
                enqueue(node);
            }
        }
        //right
        cube_copy(currentnode->cube,tmpcube);
        if(currentnode->y < CUBE-1){
DCEFunc27();

            move_right(tmpcube,currentnode->x,currentnode->y);
            if(!inme(currentnode,tmpcube)){
DCEFunc28();

               // printf("RIGHT\n");
                node=malloc(sizeof(struct Node));
                cube_copy(tmpcube,node->cube);
                node->x=currentnode->x,node->y=currentnode->y+1;
                node->prev=currentnode;
                enqueue(node);
            }
        }
    }
    printf("Total %d methods\n",counter);
}

int main(int argc, char const *argv[]){
DCEFunc29();

    int origin[CUBE][CUBE]={{

2,3,-1},{

1,8,5},{

7,4,6}};
    int x=0,y=2;
    int target[CUBE][CUBE]={{

1,2,3},{

8,-1,4},{

7,6,5}};
    bfs_search(origin,x,y,target);
    return 0;
}