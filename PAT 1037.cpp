#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <set>
#include <memory>
#include <sstream>
#include <unordered_map>
#include <queue>
using namespace std;

#define M 1000000
#define IFN 99999999


int main(){

	priority_queue<int, vector<int>, less<int>> maxCoupon, maxProd;

	priority_queue<int ,vector<int>, greater<int>> minCoupon, minProd;

	int n, m, sum = 0;
	int cp, pro;

	scanf("%d", &n);


	for(int i = 0; i != n;++i){
		int tmp;
		scanf("%d", &tmp);
		if(tmp > 0)
			maxCoupon.push(tmp);
		else if (tmp < 0)
			minCoupon.push(tmp);
	}

	scanf("%d", &m);
	for(int i = 0; i != m; ++i){
		int tmp;
		scanf("%d", &tmp);
		if(tmp > 0)
			maxProd.push(tmp);
		else if (tmp < 0)
			minProd.push(tmp);
	}


	while(!(maxCoupon.empty() || maxProd.empty())){
		cp = maxCoupon.top();
		pro = maxProd.top();
		sum += (cp * pro);
		maxCoupon.pop();
		maxProd.pop();
	}

	while(!(minCoupon.empty() || minProd.empty())){
		cp = minCoupon.top();
		pro = minProd.top();
		sum += (cp * pro);
		minCoupon.pop();
		minProd.pop();
	}
	
	cout<<sum<<endl;


	cin.get();
	return 0;
}
