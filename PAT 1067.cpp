#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <cctype>
#include <algorithm>
#include <queue>


using namespace std;
#define M 100001

int another_set(int ary[], int begin, int n){
	int i;
	for(i=begin; i!=n; i++){
		if(ary[i]!=i)
			break;
	}
	if(i==n)
		return 0;
	else
		return i;
}



int main(){
	int ary[M];
	
	int n;
	cin>>n;
	int num=0;

	for(int i=0; i!=n; ++i){
		scanf("%d", &ary[i]);
	}

	int first=another_set(ary,1, n);
	int count=0;

	while(first){
		if(ary[0]==0){
			ary[0]=ary[first];
			ary[first]=0;
			count++;
		}

		while(ary[0]!=0){
			int tem=ary[0];
			ary[0] =ary[tem];
			ary[tem]=tem;

			++count;
		}
		first=another_set(ary,first, n);
	}

	cout<<count<<endl;
	
	return 0;
}
