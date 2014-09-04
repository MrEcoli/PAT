
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <memory>
#include <map>

#define MAX 999999
using namespace std;


string doubled_num(string s){
	int len=s.size();
	int next=0;
	char cur=0;
	for(int i=(len-1); i>=0; --i){
		cur = ((s[i]-'0')*2+ next)%10+'0';
		next= ((s[i]-'0')*2+next)/10;
		s[i] =cur;
	}
	if(next!=0)
		s = string(1,next+'0') + s;
	return s;
}

bool isPermutation(string s1, string s2){
	if(s1.size()!=s2.size())
		return false;
	int len=s1.size();
	vector<int> digit_count_s1(10, 0);
	vector<int> digit_count_s2(10, 0);
	
	for(int i=0; i!=len; ++i){
		++digit_count_s1[s1[i]-'0'];
		++digit_count_s2[s2[i]-'0'];
	}
	
	return digit_count_s1==digit_count_s2;
}


int main(){

	string str1, str2;
	cin>>str1;
	str2 =doubled_num(str1);
	if(isPermutation(str1, str2))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	cout<<str2;


	cin.get();
	return 0;

}
