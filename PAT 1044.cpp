#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <limits.h>
using namespace std;
#define MAX 100005

int diamond[MAX];


int accumulate(int *start, int *end){
	int sum=0;
	while(end!=start){
		sum += *start;
		start++;
	}
	return sum;
}
int main()
{	
	typedef pair<int, int> area;
	int n, pay;
	vector<int> start;
	vector<int> end;
	cin>>n>>pay;
	
	for(int j=0; j!=n; ++j){
		scanf("%d",&diamond[j]);
	}
	size_t max_diff=99999999;

	int sum=diamond[0];
	int i=0;
	int j=0;
	int diff=INT_MAX;
	while(i<n){
		if(sum<pay){
			++j;
			if(j==n)
				break;
			sum += diamond[j];
		}
		else if(sum>=pay){
			if(sum-pay<diff){
				diff=sum-pay;
				start.clear();
				end.clear();
				start.push_back(i);
				end.push_back(j);
			}
			else if(sum-pay==diff){
				start.push_back(i);
				end.push_back(j);
			}
			sum -= diamond[i];
			++i;
		}
	}


	for(int i=0; i!=start.size(); ++i){
		printf("%d-%d\n",start[i]+1,end[i]+1);
	}

	cin.get();
	return 0;
}
