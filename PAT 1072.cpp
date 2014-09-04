#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <cctype>
#include <iostream>
#include <string>
#include <map>

#define INF 99999999
using namespace std;

#define M 1011

int adjMatrix[M][M];



int strtoint(char ch[], int n){
	if(ch[0]=='G')
		return atoi(ch+1) +n -1;
	else 
		return atoi(ch)-1;
}


void dijks(int distance[], int idx, int len){
	bool check[M];
	for(int i=0; i!=len; ++i){
		distance[i]=adjMatrix[idx][i];
		check[i]=false;
	}
	check[idx]=true;
	distance[idx]=INF;

	while(true){
		int min_vertex;
		int min_path=INF;
		for(int i=0; i!=len; ++i){
			if(!check[i] && distance[i]<min_path){
				min_vertex=i;
				min_path=distance[i];
			}
		}

		if(min_path==INF)
			break;

		check[min_vertex]=true;

		for(int i=0; i!=len; ++i){
			if(!check[i] && distance[i]> distance[min_vertex]+ adjMatrix[min_vertex][i]){
				distance[i]=distance[min_vertex] + adjMatrix[min_vertex][i];
			}
		}
	}
}


int main(){

	int n, m, k, max_ds;
	scanf("%d %d %d %d", &n, &m, &k, &max_ds);

	for(int i=0; i!=M; ++i)
		for(int j=0; j!=M; ++j)
			adjMatrix[i][j]=INF;

	char ch[10];
	for(int i=0; i!=k; ++i){
		int x,y;
		scanf("%s",ch);
		x=strtoint(ch, n);
		scanf("%s",ch);
		y=strtoint(ch,n);
		scanf("%d",&adjMatrix[x][y]);
		adjMatrix[y][x]=adjMatrix[x][y];
	}

	int distance[M];
	
	int cur_index=-1;
	double cur_sum=INF, cur_minimum=-1;

	

	for(int i=n; i!=n+m; ++i){
		dijks( distance, i, n+m);
		bool find=true;

		double minimun=INF;
		double sum=0;
		for(int j=0; j!=n && find; ++j){
			if(distance[j]>max_ds)
				find=false;
			if(distance[j]<minimun)
				minimun=distance[j];
			sum +=distance[j];
		}

		if(find){
			if(minimun>cur_minimum ||(minimun == cur_minimum && sum< cur_sum)){
				cur_minimum= minimun;
				cur_sum= sum;
				cur_index=i;
			}
		}
	}

	double cur_aver=cur_sum/n;

	if(cur_index==-1)
		printf("No Solution\n");
	else{
		printf("G%d\n",cur_index-n+1);
		printf("%.1lf %.1lf", cur_minimum, cur_aver);
	}


	return 0;
}
