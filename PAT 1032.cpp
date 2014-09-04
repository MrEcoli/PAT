#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <unordered_map>
using namespace std;

#define N 501
#define IFN 99999999

struct node{
	int pos;
	char ch;
	int next;
	node(int a, char b, int c):pos(a), ch(b), next(c){}
	node(){}
};

unordered_map<int, node>  words;

int addr1, addr2, n;

int review(int x){
	int n = 0;
	while(x != -1){
		++n;
		x = words[x].next;
	}
	return n;
}

int main(){

	scanf("%d %d %d", &addr1, &addr2, &n);

	if(addr1 == -1 || addr2 == -1){
		printf("-1");
		return 0;
	}
	for(int i = 0; i != n; ++i){
		int cur, next;
		char ch;
		scanf("%d %c %d", &cur, &ch, &next);
		words[cur] = node(cur, ch, next);
	}

	int len1, len2;

	len1 = review(addr1);
	len2 = review(addr2);
	if(len2 > len1){
		swap(len2, len1);
		swap(addr1, addr2);
	}
	int diff = len1 - len2;

	while(diff--){
		addr1 = words[addr1].next;
	}
	
	while(addr1 != -1 && addr2 != -1){
		if(addr1 == addr2)
			break;
		addr1 = words[addr1].next;
		addr2 = words[addr2].next;
	}

	if(addr1 == -1)
		printf("-1");
	else
		printf("%05d",addr1);

	


	cin.get();
	return 0;

}
