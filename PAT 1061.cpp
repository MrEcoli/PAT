#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <cctype>


using namespace std;
#define MAX 100009




int main(){

	string weeks[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

	string str1, str2, str3, str4;
	int index[3]={0};
	int cur=0;
	cin>>str1>>str2>>str3>>str4;


	for(size_t i=0; i<str1.size()&&i<str2.size()&&cur!=2; ++i){
		if(str1[i]==str2[i]){
			if(cur==0 && str1[i]>='A' && str1[i] <='G')
				index[cur++]=i;
			else if(cur==1 && ((str1[i]<='9'&& str1[i]>='0') ||(str1[i]>='A' && str1[i]<='N')))
				index[cur++]=i;
				
		}
	}

	for(size_t j=0; j<str3.size() && j<str4.size(); ++j){
		if(str3[j]==str4[j]&& isalpha(str3[j])){
			index[cur]=j;
			break;
		}
	}
	
	string day= weeks[str1[index[0]]-'A'];
	int hour;
	if(isalpha(str1[index[1]]))
		hour= str1[index[1]]-'A'+10;
	else
		hour = str1[index[1]]-'0';
	int min=index[2];

	cout<<day<<" ";

	printf("%02d:%02d\n",hour,min);


	return 0;
}
