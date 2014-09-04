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


int main(){

	map<string, vector<int>> Libirary[5];

	int n;
	cin>>n;
	for(int i=0; i!=n; ++i){
		int id;
		string title, author, word, publisher, year;
		cin>>id;
		getchar();
		getline(cin, title);
		getline(cin, author);
		getline(cin, word);
		getline(cin, publisher);
		getline(cin, year);
		Libirary[0][title].push_back(id);
		Libirary[1][author].push_back(id);
		Libirary[3][publisher].push_back(id);
		Libirary[4][year].push_back(id);
		istringstream istr(word);
		while(!istr.eof()){
			string s;
			istr>>s;
			Libirary[2][s].push_back(id);
		}

	}
	for(int i=0; i!=5; ++i){
		for(auto j= Libirary[i].begin(); j!=Libirary[i].end(); ++j){
			sort(j->second.begin(), j->second.end());
		}
	}


	int m;
	cin>>m;
	getchar();

	for(int i=0; i!=m; ++i){
		int type;
		string query;
		scanf("%d: ",&type);
		getline(cin, query);
		cout<<type<<": "<<query<<endl;
		if(!Libirary[type-1].count(query))
			cout<<"Not Found"<<endl;
		else{
			for(auto j= Libirary[type-1][query].begin(); j!=Libirary[type-1][query].end(); ++j){
				printf("%07d\n",*j);
			}
		}

	}

	cin.get();
	return 0;
}
