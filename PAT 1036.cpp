#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define M 999999

struct stu{
	string name;
	string ID;
	int grade;
	stu(){}
	stu(string x, string y, int z):name(x), ID(y), grade(z) {}
};



int main()
{	
	int N;
	cin>>N;
	vector<stu> females;
	vector<stu> male;
	for(int i=0; i!=N; ++i){
		string x,y, sex;
		int score;
		cin>>x>>sex>>y>>score;

		if(sex=="M")
			male.push_back(stu(x,y,score));
		else
			females.push_back(stu(x,y,score));
	}
	int female_score;
	int male_score;
	if(!females.empty()){
		sort(females.begin(), females.end(), [](const stu& a, const stu &b) {return a.grade> b.grade;});
		female_score=females.front().grade;
		cout<<females.front().name<<" "<<females.front().ID<<endl;
	}
	else{
		cout<<"Absent"<<endl;
	}

	if(!male.empty()){
		sort(male.begin(), male.end(),  [](const stu& a, const stu &b) {return a.grade < b.grade;});
		male_score=male.front().grade;
		cout<<male.front().name<<" "<<male.front().ID<<endl;
	}
	else{
		cout<<"Absent"<<endl;
	}

	if(male.empty() || females.empty()){
		cout<<"NA"<<endl;
	}
	else{
		cout<<female_score-male_score<<endl;
	}

	cin.get();
	return 0;
}
