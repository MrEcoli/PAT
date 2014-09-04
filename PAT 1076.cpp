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
#include <queue>

using namespace std;

#define M 1001


bool adjMatrix[M][M];

int fowardcount(int idx, int level, int n){
	int count=0;
	int cur_level=0;
	queue<int> cur;
	cur.push(idx);
	queue<int> next;
	bool check[M];

	fill_n(check, n+1, false);

	check[idx]=true;
	while(!cur.empty() || !next.empty()){
		if(cur.empty()){
			cur.swap(next);
			cur_level++;
		}
		if(cur_level==level)
			break;
		while(!cur.empty()){
			int temp=cur.front();
			cur.pop();

			for(int i=0; i!=n; ++i ){
				if(!check[i] && adjMatrix[temp][i]){
					++count;
					next.push(i);
					check[i]=true;
				}
			}
		}
	}
	return count;
}



int main(){

	int n, level, k, m;
	scanf("%d %d",&n, &level);

	for(int j=0; j!=n; ++j){
		int i;
		scanf("%d", &k);
		while(k--){
			scanf("%d",&i);
			adjMatrix[i-1][j]=true;
		}
	}

	scanf("%d", &m);
	int idx;
	while(m--){
		scanf("%d", &idx);
		--idx;
		idx=fowardcount(idx, level,n);
		printf("%d\n",idx);
	}
	


	cin.get();
	return 0;
}
