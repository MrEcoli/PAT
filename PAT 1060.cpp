#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <vector>


using namespace std;
#define MAX 100009


string float_transform(string s, int n){
	if(s[0]=='0'){
		auto pos=s.find_first_not_of('0');
		if(pos==string::npos){
			return "0." + string(n,'0')+"*10^0";
		}
		else if(s[pos]=='.'){
			s=s.substr(pos+1);
			int no_zero= s.find_first_not_of('0');
			s=s.substr(no_zero);
			int len=s.size();

			if(len>=n)
				s = s.substr(0,n);
			else
				s= s+string(n-len,'0');
			return "0."+s+"*10^"+to_string(static_cast<long long>(-no_zero));
		}
		else
			s=s.substr(pos);
	}
	auto pointer=s.find_first_of('.');
	auto len=s.size();

	if(pointer==string::npos){
		if(len>=n)
			s=s.substr(0,n);
		else
			s=s+string(n-len, '0');
		return "0."+s+"*10^"+ to_string(static_cast<long long>(len));
	}
	else{
		s= s.substr(0,pointer)+s.substr(pointer+1);

		auto cur_len=s.size();

		if(cur_len>=n)
			s=s.substr(0,n);
		else
			s=s+string(n-len, '0');

		return "0."+s+"*10^"+ to_string(static_cast<long long>(pointer));

	}

}


int main(){

	int n;
	string str1, str2;
	
	cin>>n>>str1>>str2;

	str1= float_transform(str1, n);

	str2= float_transform(str2,n);


	if(str1==str2)
		cout<<"YES "<<str1<<endl;
	else
		cout<<"NO "<<str1<<" "<<str2<<endl;

	

	return 0;
}
