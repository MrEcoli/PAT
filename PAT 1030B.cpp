#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <unordered_map>
using namespace std;

#define N 501
#define IFN 99999999

int n, m, from, to;

int dismatrix[N][N];
int costmatrix[N][N];
bool visited[N];
int dis[N];
int cost[N];
int path[N];

void dijska(){
	memset(visited, false, N);
	visited[from] = true;

	for(int i =0; i != n; ++i){
		dis[i] = dismatrix[from][i];
		cost[i] = costmatrix[from][i];
		if(dismatrix[from][i] != IFN)
			path[i] = from;
		else
			path[i] = IFN;
	}
	while(1){
		int min_node, min_path = IFN;
		for(int i = 0; i != n; ++i){
			if(!visited[i] && dis[i] < min_path){
				min_node = i;
				min_path = dis[i];
			}
		}
		if(min_path == IFN)
			break;

		visited[min_node] = true;

		for(int i = 0; i != n; ++i){
			if(!visited[i]){
				if(dis[i] > dis[min_node] + dismatrix[min_node][i]){
					dis[i] = dis[min_node] + dismatrix[min_node][i];
					cost[i] = cost[min_node] + costmatrix[min_node][i];
					path[i] = min_node;
				}
				else if(dis[i]== dis[min_node] + dismatrix[min_node][i] && cost[i] > cost[min_node] + costmatrix[min_node][i]){
					cost[i] = cost[min_node] + costmatrix[min_node][i];
					path[i] = min_node;
				}
			}

		}
	}

}

int main(){

	scanf("%d %d %d %d",&n, &m, &from, &to);

	for(int i = 0; i != n; ++i){
		for(int j = 0; j <=i; ++j){
			dismatrix[i][j] = dismatrix[j][i] = IFN;
			costmatrix[i][j] = costmatrix[j][i] = IFN;
		}
	}

	for(int i = 0; i != m; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		scanf("%d %d", &dismatrix[x][y], &costmatrix[x][y]);
		dismatrix[y][x] = dismatrix[x][y];
		costmatrix[y][x] = costmatrix[x][y];
	}
	dijska();
	
	vector<int> final;

	int last =to;
	while(last != from){
		final.push_back(last);
		last = path[last];
	}
	final.push_back(from);
	reverse(final.begin(), final.end());

	for(auto k = final.begin(); k != final.end(); ++k){
		cout<<*k<<" ";
	}
	printf("%d %d",dis[to], cost[to]);


	cin.get();
	return 0;

}
