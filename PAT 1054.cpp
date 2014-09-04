#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <limits.h>

#define MAX 500005
using namespace std;


int ary[MAX];


int main()
{	
	int m, n, index=0;
	
	cin>>m>>n;
	for(int i=0; i!=n; ++i){
		for(int j=0; j!=m; ++j){
			scanf("%d",&ary[index++]);
		}
	}
	int *first=ary;
	int *last=ary+index;
	int half=(index-1)/2;
	int *pos=nullptr;
	while(true){
		int temp= (*(first + ((last-first)>>2))+*first + *(last-1))/3;
		pos=partition(first, last, [&](const int &a){ return a<temp; });
		if(pos-ary==half)
			break;
		else if(pos-ary>half)
			last=pos-1;
		else
			first=pos+1;
	}
	cout<<*pos<<endl;
	
	


	cin.get();
	return 0;
}
