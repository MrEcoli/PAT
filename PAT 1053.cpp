#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <limits.h>

#define MAX 100005
using namespace std;

struct node{
	int val;
	vector<int> next;
} tree[100];


void dfs(vector<vector<int>> &result, vector<int> &path, int pay, int sum, int cur){
	sum += tree[cur].val;
	if(tree[cur].next.empty()){
		if(sum==pay){
			path.push_back(tree[cur].val);
			result.push_back(path);
			path.pop_back();
			return;
		}
		else
			return;
	}

	for(int i=0; i!=tree[cur].next.size(); ++i){
		path.push_back(tree[cur].val);
		dfs(result, path, pay, sum,tree[cur].next[i]);
		path.pop_back();
	}
}


int main()
{	
	int n, m, pay;
	cin>>n>>m>>pay;
	for(int i=0 ;i!=n; ++i){
		cin>>tree[i].val;
	}
	for(int j=0; j!=m; ++j){
		int cur, k, child;
		cin>>cur>>k;
		while(k--){
			cin>>child;
			tree[cur].next.push_back(child);
		}
	}
	
	vector<vector<int>> result;
	vector<int> path;

	dfs(result, path, pay, 0, 0);

	sort(result.begin(), result.end(),[](const vector<int> &a, const vector<int> &b){ return a>b; });
	for(int i=0; i!=result.size();++i){
		for(int j=0; j!=result[i].size()-1;++j){
			cout<<result[i][j]<<" ";
			
		}
		cout<<result[i].back()<<endl;
	}

		
	cin.get();
	return 0;
}
