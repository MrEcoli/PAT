#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define M 999999

void shuffle(int ary[], vector<string> &puke){
	vector<string> candicate(54);
	for(int i=0; i!=54; ++i){
		candicate[ary[i]-1]=puke[i];
	}
	puke.swap(candicate);
}


int main()
{	
	int ary[54];
	vector<string> puke;
	string charcter("SHCDJ");
	for(int j=0; j!=5;++j){
		for(int i=0;i!=13;++i){
			if(j==4&&i==3)
				break;
			string temp=string(1,charcter[j])+to_string(static_cast<long long>(i+1));
			puke.push_back(temp);
		}
	}
	
	int time;
	cin>>time;
	for(int i=0; i!=54; i++){
		cin>>ary[i];
	}
	while(time--){
		shuffle(ary, puke);
	}
	for(int i=0; i!=54; i++){
		cout<<puke[i];
		if(i!=53)
			cout<<" ";
	}


	cin.get();
	return 0;
}
