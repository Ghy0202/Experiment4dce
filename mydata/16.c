void DCEFunc0(void){};
void DCEFunc1(void){};
void DCEFunc2(void){};
void DCEFunc3(void){};
void DCEFunc4(void){};
void DCEFunc5(void){};
#include <stdio.h>

void swap(int *data,int pos1,int pos2){
DCEFunc0();

	int tmp=*(data+pos1);
	*(data+pos1)=*(data+pos2);
	*(data+pos2)=tmp;
}

void displayoutcome(int *data,int size){
DCEFunc1();

	int i;
	for(i=0;i<size;i++)
		printf("%d ", *(data+i));
	printf("\n");
}

void bubblesort(int *data,int size){
DCEFunc2();

	int flag=1;
	int i;
	int k=size;
	while(flag){
DCEFunc3();

		k--;
		flag=0;
		for(i=0;i<k;i++)
			if(data[i]>data[i+1]){
DCEFunc4();

				swap(data,i,i+1);
				flag=1;
			}
	}
}

int main(){
DCEFunc5();

	/*
	时间复杂度:O(n^2)
	空间复杂度:O(1)
	思路:对于每个位置，找到最小元素；一次循环后对应位置的数一定是当前最小的。
	这个改进办法可以保证最优时间
	*/
	int data[]={60,2,97,78,0,84,68,23,48,22,63,31,43,42,82,9,
		57,21,42,62,83,98,64,72,96,31,76,13,70,49,10,60,72,36,
		26,4,56,54,13,9,98,45,61,90,88,80,30,50,77,83,};
	int size=sizeof(data)/sizeof(int);
	bubblesort(data,size);
	displayoutcome(data,size);
	return 0;
}