#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <set>
using namespace std;

#define M 1001
#define IFN 99999999



int bfs(vector<vector<int>> &graph, int from, int n){
	int level=0;
	int last;
	queue<int> que;
	queue<int> next;
	vector<bool> visited(n, false);
	que.push(from);

	
	while(!que.empty() || !next.empty()){
		if(que.empty()){
			next.swap(que);
			++level;
		}
		while(!que.empty()){
			last= que.front();
			visited[last]=true;
			que.pop();
			for(int i=0; i!=graph[last].size(); ++i){
				if(!visited[graph[last][i]])
					next.push(graph[last][i]);
			}
		}
	}
	return level;
}



int main(){

	int n;
	int x,y;
	int compont=0;
	cin>>n;
	if(n==1){
		cout<<n;
		return 0;
	}

	vector<vector<int>> Graph(n);
	for(int i=0; i!=n-1; ++i){
		scanf("%d %d",&x, &y);
		Graph[x-1].push_back(y-1);
		Graph[y-1].push_back(x-1);
	}

	vector<int> candicate;
	bool is_connected;

	set<int> visited;
	for(int i=0; i!=n; ++i)
		visited.insert(i);

	queue<int> cur_que;



	while(!visited.empty()){
		if(cur_que.empty()){
			++compont;
			cur_que.push(*visited.begin());
		}
		while(!cur_que.empty()){
			int temp= cur_que.front();
			cur_que.pop();

			visited.erase(temp);

			if(Graph[temp].size()==1)
				candicate.push_back(temp);

			for(int i=0;i!=Graph[temp].size(); ++i){
				if(visited.count(Graph[temp][i]))
					cur_que.push(Graph[temp][i]);
			}
		}
	}

	if(compont!=1){
		cout<<"Error: "<<compont<<" components"<<endl;
		return 0;
	}
	int deepest=0;
	vector<int> resutl;
	for(int i=0; i!=candicate.size(); ++i){
		int cur = bfs(Graph, candicate[i], n);
		if(cur>deepest){
			deepest=cur;
			resutl.clear();
			resutl.push_back(candicate[i]);
		}else if(cur==deepest)
			resutl.push_back(candicate[i]);
	}

	sort(resutl.begin(), resutl.end());

	for(int i=0; i!=resutl.size(); ++i){
		cout<<resutl[i]+1<<endl;
	}


	cin.get();
	return 0;
}
