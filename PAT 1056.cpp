#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define MAX 1001

using namespace std;


void re_rank(vector<int> &rank, int max_pos){
	int n=rank.size();
	vector<int> cur(n,0);
	for(int i=0; i!=n; ++i){
		int cur_rank=1;
		for(int j=0; j!=n; ++j){
			if(rank[i]<rank[j]){
				++cur_rank;
			}
		}
		cur[i]=cur_rank;
	}
	rank.swap(cur);
}

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> weight(n);
	vector<int> seq(n);

	for(int i=0; i!=n; ++i){
		scanf("%d", &weight[i]);
	}

	for(int i=0; i!=n; ++i){
		scanf("%d", &seq[i]);
	}
	int max_pos;
	vector<int> cur(seq);
	vector<int> next;
	vector<int> rank(n,-10);
	bool visited[MAX];
	int cur_rank=1;
	while(!cur.empty()){
		fill_n(visited, n, false);
		if(cur.size()<=k){
			sort(cur.begin(),cur.end(), [&](const int &a, const int &b){return weight[a]<weight[b]; });
			for(int i=0; i!=cur.size()-1; ++i){
				rank[cur[i]]=cur_rank;
			}
			++cur_rank;
			rank[cur.back()]=cur_rank;
			max_pos=cur.back();
			cur.clear();
		}

		for(int i=0; i!=cur.size();){
			int max_w = -1;
			int max_pos = i;
			for(int j=0;j!=k&& i< cur.size();++j,++i){
				if(weight[cur[i]]>max_w){
					max_w=weight[cur[i]];
					max_pos=i;
				}
				visited[cur[i]]=true;
			}
			next.push_back(cur[max_pos]);
			visited[cur[max_pos]]=false;
		}
		for(int i=0; i!=n; ++i){
			if(visited[i])
				rank[i]=cur_rank;
		}
		++cur_rank;
		cur.swap(next);
		next.clear();
	}
	re_rank(rank, max_pos);
	
	for(int i=0; i!=rank.size()-1; ++i){
		cout<<rank[i]<<" ";
	}
	cout<<rank.back();

	cin.get();
	return 0;
}
