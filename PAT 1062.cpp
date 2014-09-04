#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <cctype>
#include <algorithm>


using namespace std;
#define MAX 100009


struct peop{
	int id;
	int talent;
	int virtue;
	bool operator<(const peop& rhs)const
	{
		if((virtue+talent)!=(rhs.talent+ rhs.virtue))
			return (virtue+talent)>(rhs.talent+ rhs.virtue);

		if(virtue==rhs.virtue)
			return id<rhs.id;

		else
			return virtue>rhs.virtue;
	}
};




int main(){

	int n, low, high;
	vector<vector<peop>> human(4);
	cin>>n>>low>>high;
	int m=n;
	while(n--){
		peop temp;
		scanf("%d %d %d", &temp.id, &temp.virtue, &temp.talent);
		if(temp.virtue<low || temp.talent<low){
			--m;
			continue;
		}
		else if(temp.virtue>=high && temp.talent>=high){
			human[0].push_back(temp);
		}
		else if(temp.talent<high &&temp.virtue>=high){
			human[1].push_back(temp);
		}
		else if(temp.virtue<high && temp.talent<high && temp.virtue>=temp.talent){
			human[2].push_back(temp);
		}
		else
			human[3].push_back(temp);
	}


	printf("%d\n",m);
	for(int i=0; i!=4; ++i){
		sort(human[i].begin(),human[i].end());
		for(int j=0; j!=human[i].size(); ++j){
			printf("%08d %d %d\n",human[i][j].id, human[i][j].virtue, human[i][j].talent);
		}
	}


	return 0;
}
