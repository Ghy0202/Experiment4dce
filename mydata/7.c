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
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 6
#define K 18

void displayoutcome(int *set,int *answer,int size){
DCEFunc0();

	int i;
	for(i=0;i<size;i++)
		if(answer[i])
			printf("%d ",set[i] );
	printf("\n");
}

int sum(int *set,int *answer,int size){
DCEFunc1();

	int summary=0,i;
	for(i=0;i<size;i++)
		if(answer[i])
			summary+=set[i];
	return summary;
}

void BFS_search(int *set,int *answer,int step){
DCEFunc2();

	int summary=sum(set,answer,step);
	if(step==SIZE ){
DCEFunc3();

		if(summary==K)
			displayoutcome(set,answer,step);
		return ;
	}
	int sel;
	for(sel=0;sel<2;sel++){
DCEFunc4();

		answer[step]=sel;
		BFS_search(set,answer,step+1);
	}
}

void branchbound(int *set,int *answer,int step){
DCEFunc5();

	int summary=sum(set,answer,step);
	if(summary>K){
DCEFunc6();

		printf("Drop branch.\n");
		return ;
	}
	if(step==SIZE){
DCEFunc7();

		if(summary==K)
			displayoutcome(set,answer,step);
		return ;
	}
	int sel;
	for(sel=0;sel<2;sel++){
DCEFunc8();

		answer[step]=sel;
		branchbound(set,answer,step+1);
	}
}

int main(int argc, char const *argv[])
{
DCEFunc9();

	int set[SIZE]={7,4,6,13,20,8};
	int answer[SIZE];
	printf("use DFS:\n");
	BFS_search(set,answer,0);
	printf("use Branch and Bound:\n");
	branchbound(set,answer,0);
	return 0;
}