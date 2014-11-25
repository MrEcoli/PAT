#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b;
    cin>>a>>b;
    a = a + b;
    int sign=1;
    if(a==0){
        cout<<a<<endl;
        return 0;
    }else if(a<0)
        sign=-1;
    string str;
    str = to_string(static_cast<long long>(a*sign));
    reverse(str.begin(), str.end());
    int i = 0, limit = (str.size()-1)/3;

    while(i<limit){
        int pos = (i+1)*3 + i;
        str.insert(pos, 1, ',');
        ++i;
    }
    reverse(str.begin(), str.end());
    if(sign == -1)
        str.insert(0 ,1, '-');
    cout<<str<<endl;
    return 0;
}
