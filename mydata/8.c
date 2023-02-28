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
void DCEFunc36(void){};
void DCEFunc37(void){};
void DCEFunc38(void){};
void DCEFunc39(void){};
void DCEFunc40(void){};
void DCEFunc41(void){};
#include <stdio.h>
#include <stdlib.h>
#define CUBE 3
#define HEAPSIZE 100


struct Node{


    int g;
    int f;
    int x;
    int y;
    int cube[CUBE][CUBE];
    struct Node *prev;
};

#define HEAPSIZE 100
struct Heap{


    int size;
    int capacity;
    struct Node **data;
};
int heap_empty(struct Heap *heap){
DCEFunc2();

    return heap->size==0;
}
void heap_swap(struct Heap *heap,int pos1,int pos2){
DCEFunc3();

    struct Node *tmp=heap->data[pos1];
    heap->data[pos1]=heap->data[pos2];
    heap->data[pos2]=tmp;
}
void heap_hold(struct Heap *heap,int pos){
DCEFunc4();

    int left=2*pos+1,right=2*pos+2;
    int minpos=pos;
    if(right<heap->size && heap->data[right]->f < heap->data[minpos]->f)
        minpos=right;
    if(left<heap->size &&  heap->data[left]->f < heap->data[minpos]->f)
        minpos=left;
    if(minpos!=pos){
DCEFunc5();

        heap_swap(heap,minpos,pos);
        heap_hold(heap,minpos);
    }
}
struct Heap *init_heap(void){
DCEFunc6();

    struct Heap *heap=malloc(sizeof(struct Heap));
    heap->size=0,heap->capacity=HEAPSIZE;
    heap->data=malloc(sizeof(struct Node*)*heap->capacity);
    return heap;
}

void insert_heap(struct Heap *heap,struct Node *new){
DCEFunc7();

    int currentpos=heap->size,parent;
    heap->data[heap->size++]=new;
    while((parent=(currentpos-1)/2)>=0){
DCEFunc8();

        if(heap->data[currentpos]->f >= heap->data[parent]->f)
            break;
        heap_swap(heap,currentpos,parent);
    }
}

struct Node *delete_min(struct Heap *heap){
DCEFunc9();

    if(heap_empty(heap))
        return NULL;
    struct Node *retval=heap->data[0];
    heap->data[0]=heap->data[--(heap->size)];
    heap_hold(heap,0);
    return retval;
}

int cube_equal(int (*m1)[CUBE],int (*m2)[CUBE]){
DCEFunc10();

    int i,j,ok=1;
    for(i=0;i<CUBE && ok;i++)
        for(j=0;j<CUBE && ok;j++)
            if(m1[i][j]!=m2[i][j])
                ok=0;
    return ok;
}

void cube_copy(int (*source)[CUBE],int (*dest)[CUBE]){
DCEFunc11();

    int i,j;
    for(i=0;i<CUBE;i++)
        for(j=0;j<CUBE;j++)
            dest[i][j]=source[i][j];
}

void cube_display(int (*m)[CUBE]){
DCEFunc12();

    int i,j;
    for(i=0;i<CUBE;i++){
DCEFunc13();

        for(j=0;j<CUBE;j++)
            printf("%d ",m[i][j]);
        printf("\n");
    }
}

void move_up(int (*m)[CUBE],int x,int y){
DCEFunc14();

    m[x][y]=m[x-1][y],m[x-1][y]=-1;
}

void move_down(int (*m)[CUBE],int x,int y){
DCEFunc15();

    m[x][y]=m[x+1][y],m[x+1][y]=-1;
}

void move_left(int (*m)[CUBE],int x,int y){
DCEFunc16();

    m[x][y]=m[x][y-1],m[x][y-1]=-1;
}

void move_right(int (*m)[CUBE],int x,int y){
DCEFunc17();

    m[x][y]=m[x][y+1],m[x][y+1]=-1;
}

int calc_weight(int (*target)[CUBE],int (*m)[CUBE]){
DCEFunc18();

    int weight=0,i,j;
    for(i=0;i<CUBE;i++)
        for(j=0;j<CUBE;j++){
DCEFunc19();

            if(m[i][j]==-1)
                continue;
            if(m[i][j]!=target[i][j])
                weight++;
        }
    return weight;
}

void displayoutcome(struct Node *node){
DCEFunc20();

    while(node){
DCEFunc21();

        cube_display(node->cube);
        printf("^\n");
        printf("^\n");
        printf("^\n");
        node=node->prev;
    }
}

int inme(struct Node *node,int (*m)[CUBE]){
DCEFunc22();

    int ok=0;
    while(node && !ok){
DCEFunc23();

        if(cube_equal(node->cube,m))
            ok=1;
        node=node->prev;
    }
    return ok;
}

void astar(int (*cube)[CUBE],int x,int y,int (*target)[CUBE]){
DCEFunc24();

    struct Node *currentnode=malloc(sizeof(struct Node)),*node;
    currentnode->x=x,currentnode->y=y,currentnode->prev=NULL;
    currentnode->g=0,currentnode->f=0;
    cube_copy(cube,currentnode->cube);
    struct Heap *heap=init_heap();
    insert_heap(heap,currentnode);
    
    int tmpcube[CUBE][CUBE];
    int counter=0,h;
    while(!heap_empty(heap)){
DCEFunc25();

        counter+=1;
        currentnode=delete_min(heap);
      
        if(cube_equal(currentnode->cube,target)){
DCEFunc26();

            displayoutcome(currentnode);
            break;
        }
        //up
        cube_copy(currentnode->cube,tmpcube);
        if(currentnode->x > 0){
DCEFunc27();

            move_up(tmpcube,currentnode->x,currentnode->y);
            if(!inme(currentnode,tmpcube)){
DCEFunc28();

             //   printf("UP!\n");
                node=malloc(sizeof(struct Node));
                cube_copy(tmpcube,node->cube);
                node->x=currentnode->x-1,node->y=currentnode->y;
                node->prev=currentnode;
                node->g=currentnode->g+1;
                h=calc_weight(target,node->cube);
                node->f=node->g+h;
                insert_heap(heap,node);
            }
        }
        //down
        cube_copy(currentnode->cube,tmpcube);
        if(currentnode->x <CUBE-1){
DCEFunc29();

            move_down(tmpcube,currentnode->x,currentnode->y);
            if(!inme(currentnode,tmpcube)){
DCEFunc30();

                //printf("DOWN!\n");
                node=malloc(sizeof(struct Node));
                cube_copy(tmpcube,node->cube);
                node->x=currentnode->x+1,node->y=currentnode->y;
                node->prev=currentnode;
                node->g=currentnode->g+1;
                h=calc_weight(target,node->cube);
                node->f=node->g+h;
                insert_heap(heap,node);
            }
        }
        //left
        cube_copy(currentnode->cube,tmpcube);
        if(currentnode->y > 0){
DCEFunc31();

           move_left(tmpcube,currentnode->x,currentnode->y);
            if(!inme(currentnode,tmpcube)){
DCEFunc32();

                node=malloc(sizeof(struct Node));
                cube_copy(tmpcube,node->cube);
                node->x=currentnode->x,node->y=currentnode->y-1;
                node->prev=currentnode;
                node->g=currentnode->g+1;
                h=calc_weight(target,node->cube);
                node->f=node->g+h;
                insert_heap(heap,node);
            }
        }
        //right
        cube_copy(currentnode->cube,tmpcube);
        if(currentnode->y < CUBE-1){
DCEFunc33();

            move_right(tmpcube,currentnode->x,currentnode->y);
            if(!inme(currentnode,tmpcube)){
DCEFunc34();

               // printf("RIGHT\n");
                node=malloc(sizeof(struct Node));
                cube_copy(tmpcube,node->cube);
                node->x=currentnode->x,node->y=currentnode->y+1;
                node->prev=currentnode;
                node->g=currentnode->g+1;
                h=calc_weight(target,node->cube);
                node->f=node->g+h;
                insert_heap(heap,node);
            }
        }
    }
}

int main(int argc, char const *argv[]){
DCEFunc35();

    int origin[CUBE][CUBE]={{

2,3,-1},{

1,8,5},{

7,4,6}};
    int x=0,y=2;
    int target[CUBE][CUBE]={{

1,2,3},{

8,-1,4},{

7,6,5}};
    astar(origin,x,y,target);
    return 0;
}