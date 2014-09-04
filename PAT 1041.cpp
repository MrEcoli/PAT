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


int main()
{	
	int N;
	cin>>N;
	map<int,int> check;
	vector<int> ary;
	while(N--){
		int key;
		cin>>key;
		++check[key];
		ary.push_back(key);
	}
	int i;
	for(i=0; i!=ary.size(); ++i){
		if(check[ary[i]]==1)
			break;
	}
	if(i==ary.size())
		cout<<"None"<<endl;
	else 
		cout<<ary[i]<<endl;




	cin.get();
	return 0;
}
