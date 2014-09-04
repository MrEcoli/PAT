#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <limits.h>

#define MAX 100005
using namespace std;

char ch[MAX];

int main()
{	
	bool check[256];
	fill_n(check, 256, true);

	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int len2=str2.size();
	int len1= str1.size();
	for(int i=0;i!=len2;++i){
		check[static_cast<int>(str2[i])]=false;
	}
	int index=0;
	for(int i=0; i!=len1; ++i){
		if(check[static_cast<int>(str1[i])])
			ch[index++]=str1[i];
	}
	ch[index]='\0';

	printf("%s",ch);

	cin.get();
	return 0;
}
