#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

#define M 1001
#define IFN 99999999

int c_max, n, sp, m;
int min_sent=IFN, min_back=IFN;
int min_dis;

vector<int> choice;

pair<int, int> bike_in_out(vector<int> path, vector<int> stations, int cap){
	int perf=cap>>1;
	int bike_sent = 0;
	int cur_bike = 0;
	for(int i=1; i!=path.size(); ++i){
		if(stations[path[i]]+cur_bike >=perf){
			cur_bike = stations[path[i]]+cur_bike - perf;
		}else{
			bike_sent += perf-(stations[path[i]] + cur_bike);
			cur_bike = 0;
		}
	}
	return make_pair(bike_sent, cur_bike);
}

void dfs(vector<vector<int>> &adjMatrix, vector<int> &path, vector<int> &stations, vector<bool> &checked, int cur_stat, int to,int cur_dis, int n){
	
	if(cur_dis> min_dis)
		return;
	if(cur_stat==to){
		if(cur_dis== min_dis){
			int bike_sent = bike_in_out(path, stations, c_max).first;
			int bike_back = bike_in_out(path, stations, c_max).second;
			if(bike_sent < min_sent){
				min_sent= bike_sent;
				min_back =bike_back;
				choice=path;
			}else if(bike_sent== min_sent && bike_back< min_back){
				min_sent= bike_sent;
				min_back =bike_back;
				choice=path;
			}
		}
		return;
	}
	for(int i=0; i!=n; ++i){
		if(!checked[i] && adjMatrix[cur_stat][i]!=IFN){
			checked[i]=true;
			path.push_back(i);
			dfs(adjMatrix, path, stations, checked, i, to, cur_dis +adjMatrix[cur_stat][i], n);
			checked[i]=false;
			path.pop_back();
		}
	}
}


int djka(vector<vector<int>> &adjMatrix, int n, int from, int to){
	vector<bool> visited(n, false);
	visited[from]=true;
	vector<int> dis(adjMatrix[from]);

	while(true){
		int min_dis=IFN;
		int min_stat;
		for(int i=0; i!=n; ++i){
			if(!visited[i] && dis[i] < min_dis){
				min_dis= dis[i];
				min_stat= i;
			}
		}
		if(min_dis==IFN)
			break;

		visited[min_stat]=true;

		for(int j=0; j!=n; ++j){
			if(!visited[j] && dis[j] > dis[min_stat] + adjMatrix[min_stat][j])
				dis[j] = dis[min_stat] + adjMatrix[min_stat][j];
		}
	}

	return dis[to];
}

int main(){
	cin>>c_max>>n>>sp>>m;
	vector<vector<int>> adjMatrix(n+1, vector<int>(n+1,IFN));
	vector<int> Station(n+1);
	for(int i=1; i!=n+1; ++i)
		scanf("%d",&Station[i]);

	for(int i=0; i!=m; ++i){
		int x, y, val;
		scanf("%d %d %d",&x, &y, &val);
		adjMatrix[y][x]=adjMatrix[x][y]=val;
	}

	min_dis= djka(adjMatrix, n+1, 0, sp);

	vector<int> path;
	path.push_back(0);
	vector<bool> checked(n+1, false);
	checked[0]=true;

	dfs(adjMatrix, path, Station, checked, 0, sp, 0, n+1);

	cout<<min_sent<<" ";
	for(int i=0;i!=choice.size()-1; ++i)
		cout<<choice[i]<<"->";
	cout<<choice.back()<<" "<<min_back;

	cin.get();
	return 0;
}
