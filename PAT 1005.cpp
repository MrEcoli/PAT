
//1016. Phone Bills (25)

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <map>
#include <list>

using namespace std;


bool isPrimer(int num){
	if(num==1)
		return false;
	for(int i=2; i*i<=num ;++i){
		if(num%i==0)
			return false;
	}
	return true;
}

bool isReversePrimer(int num, int radix){
	if(!isPrimer(num))
		return false;
	int x=0;
	while(num){
		x=x*radix+num%radix;
		num=num/radix;
	}


	return isPrimer(x);
}
void isReversePrimer(){
	int num, radix;
	while(cin>>num&&num>=0){
		cin>>radix;

		if(isReversePrimer(num ,radix))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}



int main(){

	
	isReversePrimer();

	cin.get();
	return 0;
}
