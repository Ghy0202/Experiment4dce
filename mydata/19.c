void DCEFunc0(void){};
void DCEFunc1(void){};
void DCEFunc2(void){};
void DCEFunc3(void){};
void DCEFunc4(void){};
void DCEFunc5(void){};
#include <stdio.h>
#define N 8

int count;

void display_outcome(char *answer){
DCEFunc0();

	int i;
	for(i=0;i<N;i++)
		printf("%c",answer[i]);
	printf("\n");
	count++;
}

void create_candidate(char *string,char *answer,int step,char *candidate,int *candidate_size){
DCEFunc1();

	int i;
	int hash[26]={};
	int sp=0;
	for(i=0;i<N;i++)
		hash[string[i]-'a']++;
	for(i=0;i<step;i++)
		hash[answer[i]-'a']--;
	for(i=0;i<26;i++)
		if(hash[i])
			candidate[sp++]=i+'a';
	*candidate_size=sp;
}

void backtrack(char *string,char *answer,int step){
DCEFunc2();

	if(step==N)
		display_outcome(answer);
	else{
DCEFunc3();

		char candidate[N];
		int candidate_size;
		create_candidate(string,answer,step,candidate,&candidate_size);
		int i;
		for(i=0;i<candidate_size;i++){
DCEFunc4();

			answer[step]=candidate[i];
			backtrack(string,answer,step+1);
		}
	}
}

int main(int argc, char const *argv[])
{
DCEFunc5();

	char *string="leechanx";
	char answer[N];
	backtrack(string,answer,0);
	printf("%d\n",count);
	return 0;
}