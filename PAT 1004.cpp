#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <queue>

using namespace std;

#define M 100001
#define IFN 9999999

int max_team=0;

int min_dis= IFN;

int n, road, from, to;

int pathNum=0;

void dfs(vector<vector<int>> &adjMatrix, vector<int> &path, vector<int> &Teams, vector<bool> &visited, int cur){
	
	if(cur==to){
		int cur_dis=0, cur_team=Teams[from];
		for(int i=1; i!=path.size(); ++i){
			cur_dis += adjMatrix[path[i-1]][path[i]];
			cur_team += Teams[path[i]];
		}

		if(cur_dis < min_dis){
			min_dis=cur_dis;
			pathNum=1;
			max_team=cur_team;
		}
		else if(cur_dis == min_dis){
			++pathNum;
			if(cur_team>max_team)
				max_team=cur_team;
		}
		return;
	}
	for(int i=0; i!=n; ++i){
		if(!visited[i] && adjMatrix[cur][i]!= IFN){
			visited[i]=true;
			path.push_back(i);
			dfs(adjMatrix, path, Teams, visited, i);
			path.pop_back();
			visited[i] = false;
		}
	}

}


int main(){

	
	scanf("%d %d %d %d", &n, &road, &from, &to);

	vector<int> Teams(n);

	vector<vector<int>> adjMatrix(n, vector<int>(n, IFN));

	for(int i=0; i!= n; ++i){
		scanf("%d",&Teams[i]);
	}

	for(int i=0; i!=road; ++i){
		int m, n, cost;
		scanf("%d %d %d", &m, &n, &cost);
		adjMatrix[m][n]=cost;
		adjMatrix[n][m]=cost;
	}

	vector<bool> visited(n, false);
	vector<int> path;
	path.push_back(from);
	dfs(adjMatrix, path, Teams, visited, from);
	
	cout<<pathNum<<" "<<max_team<<endl;


	cin.get();
	return 0;
}
