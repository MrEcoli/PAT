#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <cctype>
#include <algorithm>
#include <queue>


using namespace std;
#define M 2001



int main(){

	int n;
	cin>>n;

	for(int i=0; i!=n ;++i){
		long long int a, b, c;
		cin>>a>>b>>c;
		long long int temp= a+b; 

		bool flag;

		if(a>0 && b>0 && temp<=0)
			flag=true;
		else if(a<0 && b<0 && temp>=0)
			flag=false;
		else
			flag = (temp>c);
		cout<<"Case #"<<i+1<<": "<<(flag?"true":"false")<<endl;
	}

	cin>>n;


	

	return 0;
}
