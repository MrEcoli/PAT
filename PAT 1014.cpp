#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

#define M 1001


struct customer{
	int cost, id, start_time;
	customer():start_time(0){}
};


int main(){
	int n, m, k, q;

	scanf("%d %d %d %d", &n, &m, &k, &q);
	vector<customer> Customers(k);
	vector<int> Query(q);
	for(int i=0; i!=k; ++i){
		scanf("%d", &Customers[i].cost);
		Customers[i].id=i;
	}
	for(int i=0; i!=q; ++i){
		int temp;
		scanf("%d",&temp);
		Query[i]=temp-1;
	}

	vector<queue<customer>> BankQueue(n);

	int index=0;


	for(int i=0; i<m && index<k; ++i){
		for(int j=0; j<n && index<k; ++index, ++j){
			BankQueue[j].push(Customers[index]);
		}
	}

	bool is_empty=false;
	int cur_time=0;
	while(!is_empty){
		int min_que;
		int min_time=INT_MAX;
		is_empty=true;
		for(int i=0; i!=n; ++i){
			if(BankQueue[i].empty())
				continue;
			else if(BankQueue[i].front().cost <min_time ){
				is_empty=false;
				min_time= BankQueue[i].front().cost;
				min_que=i;
			}
		}
		cur_time +=min_time;

		for(int i=0; i!=n; ++i){
			if(!BankQueue[i].empty()){
				if(BankQueue[i].front().cost==min_time){
					BankQueue[i].pop();
					if(!BankQueue[i].empty()){
						Customers[BankQueue[i].front().id].start_time =cur_time;
					}
					if(index<k){
						BankQueue[i].push(Customers[index]);
						index++;
					}
				}
				else{
					BankQueue[i].front().cost -=min_time;
				}
			}
		}
	}
	

	for(int i=0; i!=q; ++i){
		if(Customers[Query[i]].start_time>= 540){
			cout<<"Sorry"<<endl;
			continue;
		}
		int time= Customers[Query[i]].cost + Customers[Query[i]].start_time;
		int hh = time / 60 +8;
		int	mm = time % 60;
		printf("%02d:%02d\n", hh, mm);
	}



	cin.get();
	return 0;
}
