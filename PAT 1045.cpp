#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <limits.h>

#define MAX 100005
using namespace std;

int fav[205];
int lowest[10001];
int stripe[10001];


int main()
{	
	unordered_map<int, int> transmap;
	int n, m, k;
	cin>>n>>m;
	for(int i=0; i!=m;++i){
		fav[i]=i+1;
		int temp;
		cin>>temp;
		transmap[temp]=fav[i];
	}
	cin>>k;
	int cut=0;
	for(int i=0; i!=k; ++i){
		int temp;
		cin>>temp;
		if(transmap.count(temp))
			stripe[i-cut]=transmap[temp];
		else
			++cut;
	}
	k=k-cut;
	int max=0;
	int index=0;
	lowest[0]=stripe[0];
	index++;
	for(int i=index; i!=k;++i){
		if(stripe[i]>=lowest[max]){
			++max;
			lowest[max]=stripe[i];
		}
		else{
			auto pos=upper_bound(lowest,lowest+1+max,stripe[i]);
			*pos=stripe[i];
		}
	}
	cout<<max+1<<endl;

	cin.get();
	return 0;
}
