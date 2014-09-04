#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define M 100001
#define IFN 9999999


int main(){
	int n;
	int ary[M];
	scanf("%d", &n);

	for(int i=0; i!=n; ++i){
		scanf("%d", &ary[i]);
	}
	
	int max_first=0, cur_first=0, max_last=0, cur_last=0;
	int cur_sum=0, max_sum=0;
	bool zero=false;
	int pos;

	for(int i=0; i!=n; ++i){
		if(ary[i]>=0 && !zero){
			zero=true;
			pos=i;
		}
		cur_sum +=ary[i];
		cur_last=i;
		if(cur_sum<0){
			if(i==n-1)
				break;
			cur_first=i+1;
			cur_sum=0;
		}else if(cur_sum>max_sum){
			max_sum=cur_sum;
			max_first=cur_first;
			max_last=cur_last;
		}
	}
	
	if(max_sum!=0){
		cout<<max_sum<<" "<<ary[max_first]<<" "<<ary[max_last]<<endl;
	}else if(!zero){
		cout<<max_sum<<" "<<ary[0]<<" "<<ary[n-1]<<endl;
	}else{
		cout<<0<<" "<<0<<" "<<0<<endl;
	}
	
	
	cin.get();
	return 0;
}
