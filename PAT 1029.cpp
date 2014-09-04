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
using namespace std;

#define M 1000000

long int find_kth_num(long int a[], int len_a, long int b[], int len_b, int k){
	if(len_a < len_b)
		return find_kth_num(b, len_b, a, len_a, k);
	if(k==1)
		return a[0]<b[0]? a[0]: b[0];
	if(len_b==0)
		return a[k-1];

	int cut = len_b < k/2 ? len_b : k/2;

	if(b[cut-1] == a[k-cut-1])
		return b[cut-1];
	else
		if(b[cut-1] > a[k-cut-1])
			return find_kth_num(a+k-cut, len_a-(k -cut), b, len_b, cut);
		else
			return find_kth_num(a, len_a, b+cut, len_b-cut, k-cut);


}


int main(){
	int n, m;


	scanf("%d", &n);
	long *a= new long[n];
	for(int i=0; i!=n; ++i)
		scanf("%ld", &a[i]);

	scanf("%d", &m);

	long *b = new long[m];

	for(int i=0; i!=m; ++i)
		scanf("%ld", &b[i]);

	
	int result = find_kth_num(a, n, b, m, (n+m+1)/2);

	cout<<result<<endl;

	delete []a;
	delete []b;



	cin.get();
	return 0;
}
