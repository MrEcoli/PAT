#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <cctype>
#include <algorithm>


using namespace std;
#define M 10001

struct mset{
	int ary[M];
	int length;
};

int unique_count(int ary[], int length){
	int num=0;
	for(int i=0; i!=length; ++i){
		if(i!=(length-1) && ary[i]==ary[i+1])
			num++;
	}

	return length-num;

}

void similarity(const mset &a, const mset &b){
	int nc=0;

	for(int i=0,j=0; i<a.length && j<b.length;){
		if(a.ary[i]<b.ary[j])
			++i;
		else if(a.ary[i]>b.ary[j])
			++j;
		else{
			++i;
			++nc;
		}
	}
	double nt=a.length+b.length-nc;
	double percent=nc/nt*100;

	printf("%.1lf%%\n",percent);
	return;
}


int main(){

	int n,m;
	scanf("%d",&n);
	vector<mset> sets(50);
	for(int i=0; i!=n; ++i){
		int k;
		scanf("%d",&k);
		for(int j=0; j!=k; ++j){
			scanf("%d",&sets[i].ary[j]);
		}
		sort(sets[i].ary, sets[i].ary+k);
		auto pos=unique(sets[i].ary, sets[i].ary+k);
		sets[i].length= pos-sets[i].ary;
	}
	int first, second;
	scanf("%d",&m);
	while(m--){
		scanf("%d %d",&first,&second);
		similarity(sets[first-1], sets[second-1]);
	}
	
	return 0;
}
