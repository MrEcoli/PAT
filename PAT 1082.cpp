#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <cctype>
#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <queue>

using namespace std;

#define M 100001

int main(){

	string s, str1, str2, str3;
	cin>>s;
	vector<string> pinying;
	string digit[]={"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	string digit2[]={"Shi", "Bai", "Qian"};
	if(s[0]=='-'){
		pinying.push_back("Fu");
		s=s.substr(1);
	}
	if(s.size()>8){
		str1 = s.substr(0, 1);
		str2 = s.substr(1, 4);
		str3 = s.substr(5, 4);
	}
	if(s.size()>4 && s.size()<=8){
		str3= s.substr(s.size()-4);
		str2= s.substr(0, s.size()-4);
	}
	if(s.size()<=4){
		str3=s;
	}
	if(!str1.empty()){
		pinying.push_back(digit[str1[0]-'0']);
		pinying.push_back("Yi");
	}
	if(!str2.empty()){
		
		int pos= str2.find_first_not_of('0');
		if(pos!=string::npos){
			if(!str1.empty() && str2[0]=='0')
				pinying.push_back("ling");
			while(pos!=str2.size()){
				if(str2[pos]!='0'){
					pinying.push_back(digit[str2[pos]-'0']);
					if(pos!=str2.size()-1){
						pinying.push_back(digit2[str2.size()-2-pos]);
					}
					pos++;
				}
				else{
					int no_zero= str2.find_first_not_of('0',pos);
					if(no_zero==string::npos)
						break;
					else{
						pinying.push_back("ling");
						pos=no_zero;
					}

				}

			}
			pinying.push_back("Wan");
		}

	}
	if(!str3.empty()){
		int pos=str3.find_first_not_of('0');
		if(pos==string::npos){
			if(str2.empty()){
				pinying.clear();
				pinying.push_back("ling");
			}
		}
		else{
			if(!str2.empty() && str3[0]=='0' && pos != string::npos){
				pinying.push_back("ling");
			}
			while(pos!=str3.size()){
				if(str3[pos]!='0'){
					pinying.push_back(digit[str3[pos]-'0']);
					if(pos!=str3.size()-1){
						pinying.push_back(digit2[str3.size()-2-pos]);
					}
					++pos;
				}
				else{
					int no_zero=str3.find_first_not_of('0', pos);
					if(no_zero==string::npos)
						break;
					else{
						pinying.push_back("ling");
						pos=no_zero;
					}
				}
			}

		}

		for(int i=0; i!=pinying.size()-1; ++i){
			cout<<pinying[i]<<" ";
		}
		cout<<pinying.back()<<endl;

	}

	
	
	cin.get();
	return 0;
}
