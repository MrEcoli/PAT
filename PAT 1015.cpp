#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

#define M 1001

bool isPrimer(int val){

	if(val<2)
		return false;
	for(int i=2; i*i<=val; ++i)
		if(val%i==0)
			return false;
	return true;
}

int toRadix(int x, int radix){
	int result = 0;
	while(x){
		result = result*radix +x%radix;
		x /=radix;
	}
	return result;
}


int main(){
	int n, radix;

	while(cin>>n ){
		if(n<0)
			break;

		cin>>radix;
		
		int temp =toRadix(n, radix);

		if(isPrimer(n) && isPrimer(temp))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

	cin.get();
	return 0;
}
