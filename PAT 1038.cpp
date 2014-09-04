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



int main()
{	
	int N;
	cin>>N;
	vector<string> strs;

	for(int i=0; i!=N;+ ++i){
		string temp;
		cin>>temp;
		strs.push_back(temp);
	}

	sort(strs.begin(), strs.end(), []( const string &a, const string &b){ return a+b < b+a; } );
	string result("");
	for(int i=0; i!=strs.size(); ++i){
		result =result+strs[i];
	}
	int pos=0;
	while(result[pos]=='0'&& pos!=result.size()){
		pos++;
	}
	if(pos == result.size()){
		cout<<0<<endl;
		return 0;
	}
	result=result.substr(pos);
	cout<<result<<endl;
	
	cin.get();
	return 0;
}
