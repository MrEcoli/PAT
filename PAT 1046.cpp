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

int path[MAX];

int accumulate(int *start, int *end){
	int sum=0;
	while(start!=end){
		sum += *start;
		++start;
	}
	return sum;
}
int dis[MAX];
int main()
{	
	typedef pair<int, int> citys;
	int n;
	
	vector<citys> que;
	cin>>n;
	for(int i=0; i!=n; ++i){
		scanf("%d", &path[i]);
		dis[i]= i==0?path[i]: dis[i-1]+path[i];
	}



	int total_path= dis[n-1];
	int nums;
	cin>>nums;
	
	for(int i=0; i!=nums;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		if(x>y)
			swap(x,y);
		que.push_back(make_pair(x,y));
	}
	for(auto i=que.begin(); i!=que.end(); ++i){
		int start=i->first;
		int end=i->second;
		int roads;
		if(start==1)
			roads=dis[end-2];
		else
			roads= dis[end-2]-dis[start-2];

		roads= roads< (total_path-roads) ? roads: (total_path-roads);
		printf("%d\n",roads);
	}



	cin.get();
	return 0;
}
