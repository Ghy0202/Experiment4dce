void DCEFunc0(void){};
void DCEFunc1(void){};
void DCEFunc2(void){};
void DCEFunc3(void){};
void DCEFunc4(void){};
void DCEFunc5(void){};
void DCEFunc6(void){};
void DCEFunc7(void){};
#include <stdio.h>
#define SIZE 8

int count;

void display_outcome(int *answer){
DCEFunc0();

	int i;
	for(i=0;i<SIZE;i++)
		printf("%d ",answer[i]);
	printf("\n");
	count++;
}

int inDiagonal(int x1,int y1,int x2,int y2){
DCEFunc1();

	if(y1-y2==x1-x2 || y1-y2==x2-x1)
		return 1;
	return 0;
}

int condition(int *answer,int step,int select){
DCEFunc2();

	int i;
	for(i=0;i<step;i++)
		if(answer[i]==select || inDiagonal(i,answer[i],step,select))
			return 0;
	return 1;
}

void backtrack(){
DCEFunc3();

	int step=0;
	int record[SIZE];
	record[step]=-1;
	int answer[SIZE];
	while(step>=0){
DCEFunc4();

		record[step]++;
		while(record[step]<SIZE && !condition(answer,step,record[step]))
			record[step]++;
		if(record[step]>SIZE-1)
			step--;
		else if(step==SIZE-1){
DCEFunc5();

			answer[step]=record[step];
			display_outcome(answer);
		}else{
DCEFunc6();

			answer[step]=record[step];
			step++;
			record[step]=-1;
		}
	}
}

int main(int argc, char const *argv[])
{
DCEFunc7();

	backtrack();
	printf("count=%d\n", count);
	return 0;
}