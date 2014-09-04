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

#define M 100001


unordered_map<int, pair<int, int>> retrailer;

int main(){

	int n, k, m;
	double price, rate;
	scanf("%d %lf %lf",&n, &price, &rate);
	vector<vector<int>> chain(n);

	rate= (100+rate)/100;
	for(int i=0; i!=n; ++i){
		scanf("%d", &k);
		if(k!=0){
			while(k--){
				scanf("%d", &m);
				chain[i].push_back(m);
			}
		}
		else {
			scanf("%d", &m);
			retrailer[i].first=m;
		}
	}
	

	queue<int> cur;
	queue<int> next;

	cur.push(0);
	int cur_level=0;

	while(!cur.empty()||!next.empty()){
		if(cur.empty()){
			cur.swap(next);
			++cur_level;
		}
		while(!cur.empty()){
			int temp=cur.front();
			cur.pop();
			if(chain[temp].empty()){
				retrailer[temp].second=cur_level;
			}else{
				for(int i=0; i!=chain[temp].size(); ++i){
					next.push(chain[temp][i]);
				}
			}
		}
	}
	double sum=0;
	for(auto i=retrailer.begin(); i!=retrailer.end(); ++i){
		sum += pow(rate, (i->second.second)) * price * i->second.first;
	}

	printf("%.1lf",sum);

	cin.get();
	return 0;
}
