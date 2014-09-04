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

struct node{
	int addr;
	int val;
	int next;
	node(int x, int y, int z):addr(x), val(y), next(z) {}
	node(){};
} ListNode[MAX];

node result[MAX];
int main()
{	
	
	int n, start;
	cin>>n>>start;
	if(start==-1){			//条件-1
		cout<<0<<" "<<start<<endl;
		return 0;
	}

	for(int i=0; i!=n; ++i){
		int addr, val, next;
		scanf("%d %d %d",&addr, &val, &next);

		if(addr==-1)
			continue;
		ListNode[addr].addr=addr;
		ListNode[addr].val=val;
		ListNode[addr].next=next;
	}
	int index=0;
	int key=start;
	while(key !=-1){
		result[index++]=ListNode[key];
		key=ListNode[key].next;
	}
	sort(result, result+index,[](const node &a, const node &b){return a.val < b.val ;});

	printf("%d %05d\n",index,result[0].addr);

	for(int i=0; i!=index-1; ++i){
		printf("%05d %d %05d\n",result[i].addr, result[i].val, result[i+1].addr);
	}
	printf("%05d %d -1",result[index-1].addr, result[index-1].val);



	cin.get();
	return 0;
}
