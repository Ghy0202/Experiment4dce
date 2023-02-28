void DCEFunc0(void){};
void DCEFunc1(void){};
void DCEFunc2(void){};
void DCEFunc3(void){};
void DCEFunc4(void){};
void DCEFunc5(void){};
void DCEFunc6(void){};
void DCEFunc7(void){};
#include <stdio.h>
#define N 5
#define M 20

int maxvalue;
int weighted;

void display_outcome(int *answer,int *weight,int *value){
DCEFunc0();

	int i;
	int myvalue=0,myweight=0;
	for(i=0;i<N;i++)
		if(answer[i]){
DCEFunc1();

			myvalue+=value[i];
			myweight+=weight[i];
		}
	if(myvalue>maxvalue){
DCEFunc2();

		maxvalue=myvalue;
		weighted=myweight;
		for(int i=0;i<N;i++)
			printf("%d",answer[i]);
		printf("\n");
	}
}

int condition(int *weight,int *answer,int step,int select){
DCEFunc3();

	int i;
	int myweight=0;
	for(i=0;i<step;i++)
		if(answer[i])
			myweight+=weight[i];
	if(select)
		myweight+=weight[step];
	return myweight<=M;
}

void backtrack(int *weight,int *value,int *answer,int step){
DCEFunc4();

	if(step==N)
		display_outcome(answer,weight,value);
	else{
DCEFunc5();

		int i;
		for(i=0;i<2;i++)
			if(condition(weight,answer,step,i)){
DCEFunc6();

				answer[step]=i;
				backtrack(weight,value,answer,step+1);
			}
	}
}

int main(int argc, char const *argv[])
{
DCEFunc7();

	int weight[N]={3,4,5,6,7};
	int value[N]={5,4,3,2,10};
	int answer[N];
	backtrack(weight,value,answer,0);
	printf("maxvalue=%d\n",maxvalue);
	printf("weighted=%d\n",weighted);
	return 0;
}