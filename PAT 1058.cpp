#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>


using namespace std;
#define MAX 100009


string strplus(string s1, string s2){
	int s1_1=s1.find_first_of('.');
	int s1_2=s1.find_last_of('.');
	int s2_1=s2.find_first_of('.');
	int s2_2=s2.find_last_of('.');

	int s1_ga= stoi(s1.substr(0,s1_1));
	int s1_si=stoi(s1.substr(s1_1+1,s1_2-s1_1-1));
	int s1_kn= stoi(s1.substr(s1_2+1));
	
	int s2_ga= stoi(s2.substr(0,s2_1));
	int s2_si=stoi(s2.substr(s2_1+1,s2_2-s2_1-1));
	int s2_kn= stoi(s2.substr(s2_2+1));

	int key,mid;

	key =(s1_kn+s2_kn) /29;
	s1_kn= (s1_kn+s2_kn) %29;

	mid= (s1_si+s2_si +key) /17;
	s1_si= (s1_si+s2_si +key) %17;

	key=mid;
	s1_ga = s1_ga+ s2_ga +key;

	string result= to_string(static_cast<long long>(s1_ga))+"."+to_string(static_cast<long long>(s1_si))+"."+to_string(static_cast<long long>(s1_kn));

	return result;

}

int main(){
	string str1,str2;

	cin>>str1>>str2;

	str1=strplus(str1,str2);
	cout<<str1<<endl;

	return 0;
}
