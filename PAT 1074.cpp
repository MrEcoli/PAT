#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <cctype>
#include <iostream>
#include <string>
#include <map>
#include <cstring>

#define INF 99999999
using namespace std;

#define M 100010

void strapp(char dest[], char source[], int n){
	for(int i=0; i!=n; ++i)
		dest[i]=source[i];
}



int main(){


	
	char ch[M];


	scanf("%s", ch);
	char output[M];

	char *esult=output;
	int len= strlen(ch);

	int pos=len-1;
	char sign1=ch[0];
	while(isdigit(ch[pos]))
		--pos;
	char sign2=ch[pos];
	int exp=atoi(ch+pos+1);
	

	if(sign1=='-')
		printf("-");
	if(exp==0){
		ch[pos-1]='\0';
		printf("%s\n",ch+1);


	}else if(sign2=='+'){
		printf("%c",ch[1]);
		if(exp<pos-4){
			char *x=ch+3;
			int i=0;
			while(exp--){
				printf("%c",x[i++]);
			}
			printf(".");
			while(x[i]!='E')
				printf("%c",x[i++]);
		}
		else{
			pos=pos-3;
			exp=exp-pos+1;
			char *x=ch+3;
			while(*x!='E'){
				printf("%c", *x);
				++x;
			}
			while(exp--){
				printf("0");
			}
		}

	}else{
		printf("0.");
		exp=exp-1;

		while(exp--){
			printf("0");
		};

		printf("%c", ch[1]);

		char *x=ch+3;
		while(*x!='E'){
			printf("%c",*x);
			x++;
		}
	}

	
	

	return 0;
}
