#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <random>
#include <cctype>
#include <queue>
#include <sstream>
using namespace std;


struct node{
	int pos;
	int val;
	int next;
};



int main(){
	int from, n, k;
	int pos = 0;

	scanf("%d %d %d", &from, &n, &k);

	map<int, node> Lists;
	
	vector<node> arry(n);

	for(int i = 0; i != n; ++i){
		node tmp;
		scanf("%d %d %d", &tmp.pos, &tmp.val, &tmp.next);
		Lists[tmp.pos] = tmp;
	}


	while(from != -1){
		arry[pos++] = Lists[from];
		from = Lists[from].next;
	}
	
	int cur_pos = 0;
	

	while(cur_pos + k <= pos){
		reverse(arry.begin() + cur_pos, arry.begin() + cur_pos + k);
		cur_pos += k;
	}

	for(int i = 0; i != pos-1; ++i){
		printf("%05d %d %05d\n", arry[i].pos, arry[i].val, arry[i+1].pos);
	}

	printf("%05d %d -1\n", arry[pos-1].pos, arry[pos-1].val);



	cin.get();

}
