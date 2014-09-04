#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <set>
#include <memory>
#include <sstream>
#include <unordered_map>
using namespace std;

#define M 1001
#define IFN 99999999

struct stu{
	string id;
	int score;
	int local_num;
	int local_rank;
	int final_rank;
	bool operator<(const stu &rhs)const{
		if(score != rhs.score)
			return score > rhs.score;
		return
			id< rhs.id;

	}
};


int main(){
	int n, m;
	cin>>n;
	vector<stu> all_stu;
	for(int i=0; i!=n; ++i){
		cin>>m;
		vector<stu> local(m);
		for(int j=0; j!=m; ++j){
			cin>>local[j].id>>local[j].score;
			local[j].local_num =i+1;
		}
		sort(local.begin(), local.end());
		for(int k=0; k!=m; ++k){
			int cur_rank=k+1;
			local[k].local_rank = cur_rank;
			while(k!=m-1 && local[k].score == local[k+1].score){
				local[k+1].local_rank = cur_rank;
				++k;
			}
		}
		for(int j=0; j!=m; ++j){
			all_stu.push_back(local[j]);
		}
	}
	int len = all_stu.size();
	sort(all_stu.begin(), all_stu.end());

	for(int k=0; k!=len; ++k){
		int rank=k+1;
		all_stu[k].final_rank = rank;
		while(k != len-1 && all_stu[k].score == all_stu[k+1].score){
			all_stu[k+1].final_rank = rank;
			++k;
		}
	}

	cout<<len<<endl;
	for(int i=0; i!=len; ++i){
		cout<<all_stu[i].id<<" "<<all_stu[i].final_rank<<" "<<all_stu[i].local_num<<" "<<all_stu[i].local_rank<<endl;

	}



	cin.get();
	return 0;
}
