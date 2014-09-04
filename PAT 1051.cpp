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


int main()
{	
	
	int cap, n, k;
	cin>>cap>>n>>k;
	vector<int> ary(n);
	while(k--){
		vector<bool> check(n,false);
		bool correct=true;
		for(int i=0; i!=n; ++i){
			scanf("%d",&ary[i]);	
		}
		for(int i=0;i!=n && correct;++i){
			if(check[i])
				continue;
			else{
				if(ary[i]>cap+i){
					correct=false;
					break;
				}else{
					int index=i+1;
					int limit=ary[i];
					for(;index!=n;++index){
						int count=1;
						if(ary[index]<ary[i]){
							++count;
							if(ary[index]>limit){
								correct=false;
								break;
							}else {
								limit=ary[index];
								check[index]=true;
							}
						}
						if(count>cap)
							correct=false;
					}
				}

			}
		}
		if(correct)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}



	cin.get();
	return 0;
}
