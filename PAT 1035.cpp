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



struct account{
	string name;
	string password;
	account(){};
	account(string x, string y):name(x), password(y){};
};



int main()
{	
	int N;
	cin>>N;
	vector<account> Accounts;
	string before("10lO");
	string after("@%Lo");
	for(int i=0;i!=N ; ++i){
		string u,v;
		cin>>u>>v;
		bool is_change=false;
		for(int j=0; j!=v.size(); ++j){
			auto index=before.find(v[j]);
			if(index!=string::npos){
				is_change=true;
				v[j]=after[index];
			}
		}
		if(is_change)
			Accounts.push_back(account(u,v));
	}

	if( N==1)
		cout<<"There is 1 account and no account is modified";
	else if(Accounts.empty())
		cout<<"There are "<<N<<" accounts and no account is modified";
	else{
		cout<<Accounts.size()<<endl;
		for(auto i=Accounts.begin(); i!=Accounts.end(); ++i){
			cout<<i->name<<" "<<i->password<<endl;
		}
	}


	cin.get();
	return 0;
}
