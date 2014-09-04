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

struct grad{
	int rank;
	int ge;
	int gi;
	int final;
	int id;
	vector<int> choice;
	bool operator<(const grad &a)const{
		if(final!=a.final)
			return final > a.final;
		
		return ge> a.ge;
	}

};

struct school{
	vector<int> students;
	int capacity;
	int cur;
	int id;
	school():cur(0){};
};



int main(){

	int n, s, k, choice;
	scanf("%d %d %d",&n, &s, &k);

	vector<school> Schools(s);
	vector<grad> Grads(n);
	for(int i=0; i!=s; ++i){
		scanf("%d", &Schools[i].capacity);
		Schools[i].id=i;
	}

	for(int i=0; i!=n; ++i){
		Grads[i].id=i;
		scanf("%d %d",&Grads[i].ge, &Grads[i].gi);
		Grads[i].final=(Grads[i].ge + Grads[i].gi)/2;
		for(int j=0; j!=k; ++j){
			scanf("%d",&choice);
			Grads[i].choice.push_back(choice);
		}
	}

	sort(Grads.begin(), Grads.end());

	for(int i=0; i!=Grads.size(); ++i){
		int idx=i;
		Grads[i].rank=idx;
		while(i!= Grads.size()-1 && Grads[i].final == Grads[i+1].final && Grads[i].ge == Grads[i+1].ge){
			Grads[i+1].rank=idx;
			i++;
		}
	}

	for(int i=0; i!=Grads.size(); ++i){
		vector<int> incr(s, 0);
		for(auto j=Grads[i].choice.begin(); j!=Grads[i].choice.end(); ++j){
			if(Schools[*j].cur<Schools[*j].capacity){
				++incr[*j];
				Schools[*j].students.push_back(Grads[i].id);
				break;
			}
		}
		while(i!=Grads.size()-1 && Grads[i].rank==Grads[i+1].rank){
			auto temp=Grads[i+1];
			for(auto k=temp.choice.begin(); k!=temp.choice.end(); ++k){
				if(Schools[*k].cur<Schools[*k].capacity){
					++incr[*k];
					Schools[*k].students.push_back(temp.id);
					break;
				}
			}
			++i;
		}

		for(auto p=0; p!=Schools.size(); ++p){
			Schools[p].cur += incr[p];
		}
	}

	for(auto q=0; q!=Schools.size(); ++q){
		if(!Schools[q].students.empty()){
			sort(Schools[q].students.begin(), Schools[q].students.end());
			for(int i=0; i!=Schools[q].students.size()-1; ++i){
				printf("%d ",Schools[q].students[i]);
			}
			printf("%d\n",Schools[q].students.back());
		}
		else{
			printf("\n");
		}
	
	}




	cin.get();
	return 0;
}
