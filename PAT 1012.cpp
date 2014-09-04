#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;



int chartoint(char ch){
	if(isalpha(ch))
		return ch-'a'+10;
	return ch-'0';
}

long long int strtoint(char s[], long long r){
	int n=strlen(s);
	long long int result=0;
	for(int i=0; i!=n; ++i){
		result =result*r + chartoint(s[i]);
		if(result<0)
			return -1;
	}
	return result;
}

int min_radix(char s[]){
	int radix=1;
	int n= strlen(s);
	for(int i=0; i!=n; ++i){
		if(chartoint(s[i])>radix)
			radix=chartoint(s[i]);
	}

	return radix+1;
}



int main(){
	long long int n, radix;
	long long int x, y;
	char str1[100], str2[100], str3[100];

	scanf("%s %s %d %lld",str1, str2, &n, &radix);

	if(n==2){
		strcpy(str3, str1);
		strcpy(str1, str2);
		strcpy(str2, str3);
	}

	x=strtoint(str1, radix);

	long long int last=x+1;
	long long int first= min_radix(str2);

	bool find=false;
	long long int mid;

	while(first<=last){
		mid=(first+ last)/2;

		long long int temp =strtoint(str2, mid);
		if(temp>x || temp<0)
			last=mid-1;
		else if(temp<x)
			first=mid+1;
		else{
			find=true;
			break;
		}
	}


	if(!find)
		cout<<"Impossible"<<endl;
	else
		cout<<mid<<endl;






	cin.get();
	return 0;
}
