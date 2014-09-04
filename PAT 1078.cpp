#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <cctype>
#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <queue>

using namespace std;

#define M 1001


bool isPrimer(int x){
	if(x==2)
		return true;

	for(int i=2; i*i<=x; ++i){
		if(x%i==0)
			return false;
	}

	return true;
}
int nextprimer(int n){

	if(n<2)
		return 2;

	if(isPrimer(n))
		return n;


	while(!isPrimer(++n))
		;
	return n;
}

int hashfunc(int key, int i, int max_size){
	
	return (key%max_size + i*i) % max_size ;
}


int main(){

	int max_size, n;
	cin>>max_size>>n;

	max_size=nextprimer(max_size);

	vector<int> addr(n, -1);
	vector<int> hashtable(max_size, -1);
	int temp;
	int cur_addr;
	for(int i=0; i!=n; ++i){
		scanf("%d",&temp);
		for(int j=0; j!=max_size; ++j){
			cur_addr= hashfunc(temp, j, max_size);
			if(hashtable[cur_addr]==-1){
				hashtable[cur_addr]= temp;
				addr[i]= cur_addr;
				break;
			}
		}
	}

	for(int i=0; i!=n-1; i++){
		if(addr[i]!=-1){
			printf("%d ",addr[i]);
		}else
			printf("- ");
	}

	if(addr[n-1]==-1)
		printf("-");
	else
		printf("%d", addr[n-1]);

	cin.get();
	return 0;
}
