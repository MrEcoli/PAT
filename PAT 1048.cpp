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
	int n,pay;
	int coin[MAX];
	scanf("%d %d",&n,&pay);
	for(int i=0; i!=n; ++i){
		scanf("%d",&coin[i]);
	}
	sort(coin, coin+n);
	
	int *first=coin;
	int *last=coin+n-1;
	bool find=false;
	int cur;
	while(first<last){
		cur=*first+ *last;
		if(cur<pay)
			++first;
		else if(cur>pay)
			--last;
		else{
			find=true;
			break;
		}
	}
	if(!find){
		cout<<"No Solution"<<endl;
	}
	else{
		cout<<*first<<" "<<*last<<endl;
	}

	cin.get();
	return 0;
}
