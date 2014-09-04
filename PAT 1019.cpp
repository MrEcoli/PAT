#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

#define M 1001
#define IFN 99999999




int main(){

	long long n, base;
	cin>>n>>base;

	int r[100];
	int cur=n;
	int index=0;
	fill_n(r, 100, 0);

	while(cur){
		r[index++] = cur % base;
		cur /=base;
	}

	if(index==1)
		cout<<"Yes"<<endl;
	else if(n==0){
		++index;
		cout<<"Yes"<<endl;
	}
	else{
		int first=0, last= index-1;
		while(first<last && r[first]== r[last]){
			++first;
			--last;
		}
		if(first<last)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	for(int i=index-1; i>0; --i){
		cout<<r[i]<<" ";
	}
	cout<<r[0]<<endl;



	cin.get();
	return 0;
}
