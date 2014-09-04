#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <vector>


using namespace std;
#define MAX 100009




int main(){
	long int n;
	cin>>n;

	long int input=n;

	long int index=2;
	vector<long int> result;

	while(index*index<= n){
		long int i;
		for(i=index; i*i<=n; ++i){
			if(n%i==0){
				result.push_back(i);
				n /=i;
				break;
			}
		}
		index=i;
	}

	result.push_back(n);

	cout<<input<<"=";
	for(size_t k=0; k!=result.size(); ++k){
		int num=1;
		while(k<result.size()-1 && result[k]==result[k+1]){
			++num;
			++k;
		}
		cout<<result[k];
		if(num!=1)
			cout<<'^'<<num;
		if(k!=result.size()-1)
			cout<<'*';	
	}

	return 0;
}
