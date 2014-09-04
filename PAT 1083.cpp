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


struct stu{
	char name[11];
	char id[11];
	int grade;

	bool operator<(const stu &rhs)const{
		return grade> rhs.grade;
	}
};

int lower(const vector<stu> &Stus, int low){
	auto first=Stus.begin();
	auto last=Stus.end();
	auto mid = first;

	while(first!=last){
		mid=first+ (last-first)/2;
		if(mid->grade >=low)
			first= mid+1;
		else
			last=mid;
	}

	return first-Stus.begin();
}

int higher(const vector<stu> &Stus, int high){
	auto first= Stus.begin();
	auto last= Stus.end();
	auto mid=first;

	while(first!=last){
		mid=first + (last -first)/2;
		if(mid->grade >high)
			first =mid+1;
		else
			last=mid;
	}
	return first-Stus.begin();
}




int main(){

	int n, low, high;
	scanf("%d",&n);
	vector<stu> all_stu(n);
	for(int i=0; i!=n; ++i){
		scanf("%s %s %d",all_stu[i].name, all_stu[i].id, &all_stu[i].grade);
	}
	scanf("%d %d", &low, &high);

	sort(all_stu.begin(), all_stu.end());

	auto first= higher(all_stu, high);
	auto last= lower(all_stu, low);

	if(first==last)
		cout<<"NONE"<<endl;
	else{
		for(int i=first; i!=last; ++i){
			printf("%s %s\n",all_stu[i].name, all_stu[i].id);
		}
	}
	

	cin.get();
	return 0;
}
