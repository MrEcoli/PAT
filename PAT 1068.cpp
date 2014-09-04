#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <cctype>
#include <algorithm>
#include <queue>


using namespace std;
#define M 10001





int main(){
	
	int n, pay;

	scanf("%d %d",&n, &pay);
	int coin[M];
	

	for(int i=0; i!=n; ++i)
		scanf("%d",&coin[i]);
	
	sort(coin, coin+n, [](const int &a, const int &b){return a>b; });

	n=upper_bound(coin, coin+n, pay)-coin;
	
	vector<vector<bool>> dp(n, vector<bool>(pay+1, false));
	vector<vector<bool>> choice(n,vector<bool>(pay+1, false));

	for(int i=0; i!=n; ++i){
		for(int j=0; j!=(pay+1); ++j){
			if(j==coin[i]){
				dp[i][j]=true;
				choice[i][j]=true;
			}
			else if(coin[i]>j){
				if(i==0)
					dp[i][j]=false;
				else
					dp[i][j]=dp[i-1][j];
			}
			else if(i>0){
				dp[i][j]= dp[i-1][j] || dp[i-1][j-coin[i]];
				if(dp[i-1][j-coin[i]])
					choice[i][j]=true;
			}
		}
	}
	
	if(!dp[n-1][pay])
		cout<<"No Solution"<<endl;
	else{
		vector<int> result;
		int m=pay;
		int row=n-1;
		while(m){
			while(!choice[row][m])
				--row;
			result.push_back(coin[row]);
			m -=coin[row];
			--row;
		}

		for(int i=0; i!=result.size()-1; ++i)
			cout<<result[i]<<" ";
		cout<<result.back();
	}
	

	return 0;
}
