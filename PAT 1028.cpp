#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <unordered_map>

using namespace std;

#define M 1000000
#define IFN 99999999

struct stu{
	int id;
	char name[10];
	int grade;
};



int main(){

	int n, type;

	scanf("%d %d",&n, &type);
	vector<stu> Students(n);
	for(int i = 0; i != n; ++i){
		scanf("%d %s %d",&Students[i].id, Students[i].name, &Students[i].grade);
	}

	if(type == 1)
		sort(Students.begin(), Students.end(), [](const stu &a, const stu &b)->bool{ return a.id < b.id;});
	else if (type == 2)
		sort(Students.begin(), Students.end(), [](const stu &a, const stu &b)->bool{ if(strcmp(a.name, b.name) == 0 ) return a.id < b.id; else return strcmp(a.name, b.name) < 0;});
	else
		sort(Students.begin(), Students.end(), [](const stu &a, const stu &b)->bool{ if(a.grade == b.grade) return a.id < b.id; else return a.grade< b.grade;});

	for(auto i = Students.begin(); i != Students.end(); ++i){
		printf("%06d %s %d\n",i->id, i->name, i->grade);
	}


	cin.get();
	return 0;

}
