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
#include <stdio.h>
#include <stdlib.h>
#define LIMIT 20
#define BUCKETSIZE 10
#define MAP(x) (x/2)

struct List{


	int item;
	struct List *next;
};

struct Listhead{


	struct List *head;
};

void bucket_init(struct Listhead **buckets,int bucketsize){
DCEFunc2();

	int i;
	for(i=0;i<bucketsize;i++){
DCEFunc3();

		buckets[i]=malloc(sizeof(struct Listhead));
		buckets[i]->head=NULL;
	}
}

void list_add(struct Listhead **buckets,int item,int position){
DCEFunc4();

	printf("%d save in %d\n",item,position );
	struct Listhead *list=buckets[position];
	struct List *new=malloc(sizeof(struct List));
	new->item=item;
	new->next=NULL;
	if(list->head){
DCEFunc5();

		struct List *current=list->head,*prev=NULL;
		while(current){
DCEFunc6();

			if(current->item>=item){
DCEFunc7();

				new->next=current;
				if(prev){
DCEFunc8();

					prev->next=new;
				}else{
DCEFunc9();

					list->head=new;
				}
				break;
			}
			prev=current;
			current=current->next;
		}
		if(prev)
			prev->next=new;
	}else
		list->head=new;
}

void bucket_add(struct Listhead **buckets,int item){
DCEFunc10();

	list_add(buckets,item,MAP(item));
}

void bucket_scan(struct Listhead **buckets,int *data,int bucketsize){
DCEFunc11();

	int sp=-1,i,nowvalue;
	struct List *list;
	for(i=0;i<bucketsize;i++){
DCEFunc12();

		list=buckets[i]->head;
		while(list){
DCEFunc13();

			nowvalue=list->item;
			printf("nowvalue=%d\n",nowvalue);
			data[++sp]=nowvalue;
			list=list->next;
		}
	}
}

void bucketsort(int *data,int size){
DCEFunc14();

	struct Listhead *buckets[BUCKETSIZE];
	bucket_init(buckets,BUCKETSIZE);
	int i;
	for(i=0;i<size;i++){
DCEFunc15();

		printf("add %d\n",data[i] );
		bucket_add(buckets,data[i]);
	}
	bucket_scan(buckets,data,BUCKETSIZE);
}

void displayoutcome(int *data,int size){
DCEFunc16();

	int i;
	for(i=0;i<size;i++)
		printf("%d ", *(data+i));
	printf("\n");
}

int main(){
DCEFunc17();

	/*
	时间复杂度:O(n)
	空间复杂度:O()
	适用于属于一定范围内的数的排序。
	思路:。
	*/
	int data[]={5,4,3,19,3,9,16,15,0,
		0,9,12,9,10,10,4,19,15,12,16,
		0,0,1,1,3,4,14,3,6,12,1,3,14,
		4,15,4,4,7,11,13,2,1,15,13,1,
		12,9,17,13,16,};
	int size=sizeof(data)/sizeof(int);
	bucketsort(data,size);
	displayoutcome(data,size);
	return 0;
}