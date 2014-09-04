#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <limits.h>
using namespace std;

#define M 1001

struct stu{
	int rank;
	int comp, math, engl, id, aver;
	stu(){}
};


int main(){
	int n, m;
	cin>>n>>m;
	vector<shared_ptr<stu>> Students;
	vector<int> query(m);
	for(int i=0; i!=n; ++i){
		shared_ptr<stu> temp=make_shared<stu>();
		scanf("%d %d %d %d",&temp->id, &temp->comp, &temp->math, &temp->engl);
		temp->aver =  (temp->comp + temp->math + temp->engl)/3;
		Students.push_back(temp);
	}
	for(int i=0; i!=m; ++i){
		scanf("%d", &query[i]);
	}


	unordered_map<int, vector<int>> Ranks;

	sort(Students.begin(), Students.end(), [](const shared_ptr<stu> &a, const shared_ptr<stu> &b){ return a->aver > b->aver; });
	for(int i=0; i!=n; ++i){
		int idx=i;
		Ranks[Students[i]->id].push_back(idx+1);
		while(i!=n-1 && Students[i]->aver == Students[i+1]->aver){
			Ranks[Students[i+1]->id].push_back(idx+1);
			++i;
		}
	}

	sort(Students.begin(), Students.end(), [](const shared_ptr<stu> &a, const shared_ptr<stu> &b){ return a->comp > b->comp; });
	for(int i=0; i!=n; ++i){
		int idx=i;
		Ranks[Students[i]->id].push_back(idx+1);
		while(i!=n-1 && Students[i]->comp == Students[i+1]->comp){
			Ranks[Students[i+1]->id].push_back(idx+1);
			++i;
		}
	}

	sort(Students.begin(), Students.end(), [](const shared_ptr<stu> &a, const shared_ptr<stu> &b){ return a->math > b->math; });
	for(int i=0; i!=n; ++i){
		int idx=i;
		Ranks[Students[i]->id].push_back(idx+1);
		while(i!=n-1 && Students[i]->math == Students[i+1]->math){
			Ranks[Students[i+1]->id].push_back(idx+1);
			++i;
		}
	}

	sort(Students.begin(), Students.end(), [](const shared_ptr<stu> &a, const shared_ptr<stu> &b){ return a->engl > b->engl; });
	for(int i=0; i!=n; ++i){
		int idx=i;
		Ranks[Students[i]->id].push_back(idx+1);
		while(i!=n-1 && Students[i]->engl == Students[i+1]->engl){
			Ranks[Students[i+1]->id].push_back(idx+1);
			++i;
		}
	}

	char course[]={'A', 'C', 'M', 'E'};
	for(int i=0; i!=m; ++i){
		int cur=query[i];
		if(!Ranks.count(cur))
			cout<<"N/A"<<endl;
		else{
			vector<int> temp=Ranks[query[i]];
			int idx, min_idx;
			int min_rank=INT_MAX;
			for(idx=0; idx!=4; ++idx){
				if(temp[idx]<min_rank){
					min_idx=idx;
					min_rank= temp[idx];
				}
			}

			cout<<min_rank<<" "<<course[min_idx]<<endl;
		}
	}


	cin.get();
	return 0;
}
