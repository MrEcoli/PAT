
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX 505
using namespace std;
typedef pair<int, int> dis_cost;



void bfs(vector<vector<int>> &all_path, vector<int> &path, vector<vector<int>> &prev_city,int start){
	if(path.back()==start){
		all_path.push_back(path);
		return;
	}
	int last=path.back();
	for(int i=0; i!=prev_city[last].size(); ++i){
		path.push_back(prev_city[last][i]);
		bfs(all_path, path, prev_city,start);
		path.pop_back();
	}

}


int main(){
	int N, M, start, end;

	scanf("%d%d%d%d",&N,&M,&start,&end);
	auto max_data= make_pair(MAX,MAX);

	vector<vector<dis_cost>> adjMatrix(N,vector<dis_cost>(N, max_data));

	for(int i=0; i!=M; ++i){
		int city1, city2, distance, cost;
		scanf("%d%d%d%d",&city1, &city2, &distance, &cost);
		adjMatrix[city1][city2]=make_pair(distance,cost);
		adjMatrix[city2][city1]=make_pair(distance,cost);
	}
	
	bool visited[MAX]={false};

	int dis[MAX];
	visited[start]=true;
	vector<vector<int>> prev_city(N);
	for(int i=0;i!=N; ++i){
		dis[i]= adjMatrix[start][i].first;
		if(adjMatrix[start][i].first<MAX)
			prev_city[i].push_back(start);
	}
	
	while(true){
		int min_dis=MAX;
		int min_city;
		for(int i=0; i!=N;++i){
			if(!visited[i] && dis[i]<min_dis){
				min_dis=dis[i];
				min_city=i;
			}
		}
		if(min_dis == MAX)
			break;

		visited[min_city]= true;

		for(int i=0; i!=N; ++i){
			if(!visited[i]){
				if(dis[i] > dis[min_city] + adjMatrix[min_city][i].first ){
					prev_city[i].clear();
					dis[i]= dis[min_city] + adjMatrix[min_city][i].first;
					prev_city[i].push_back(min_city);
				}
				else if( dis[i] == dis[min_city] + adjMatrix[min_city][i].first )
					prev_city[i].push_back(min_city);
			}
		}
	}
	
	
	vector<vector<int>> all_paths;
	vector<int> path;
	path.push_back(end);
	
	bfs(all_paths, path, prev_city, start);

	for_each(all_paths.begin(), all_paths.end(), [](vector<int> &a){
		reverse(a.begin(), a.end());
		return;
	});

	auto comp=[&](const vector<int> &a, const vector<int> &b)->bool{
		int sum_a =0;
		int sum_b=0;
		for(int i=0; i!= (a.size()-1); ++i){
			sum_a +=adjMatrix[a[i]][a[i+1]].second;
		}
		for(int i=0; i!= (b.size()-1); ++i){
			sum_b +=adjMatrix[b[i]][b[i+1]].second;
		}
		return sum_a<sum_b;
	};
	
	sort(all_paths.begin(), all_paths.end(), comp);
	vector<int> result=all_paths.front();

	int total_dis=0;
	int total_cost=0;
	for(int i=0; i!=(result.size()-1); ++i){
		total_dis += adjMatrix[result[i]][result[i+1]].first;
		total_cost += adjMatrix[result[i]][result[i+1]].second;
		printf("%d ",result[i]);
	}

	printf("%d %d %d",result.back(), total_dis, total_cost);
	cin.get();
	return 0;
}
