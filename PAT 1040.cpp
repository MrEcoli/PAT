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
#define ONE 26
#define TWO 26*26
#define THR 26*26*26


int main()
{	
	string s;
	getline(cin,s);
	int len=s.size();
	vector<vector<bool>> matrix(len, vector<bool>(len, false));
	int maxlen=1;
	for(int i=0; i!=len; ++i){
		for(int j=i; j>=0; --j){
			if(j==i)
				matrix[i][j]=true;
			else if((i-j)==1 && s[i]==s[j])
				matrix[i][j]=true;
			else if(s[i]==s[j]&& matrix[i-1][j+1])
				matrix[i][j]=true;
			if(matrix[i][j]&&(i-j+1)>maxlen)
				maxlen=i-j+1;
		}
	}

	cout<<maxlen<<endl;
	cin.get();
	return 0;
}
