//PAT 1006 Spell it Right
#include <iostream>
#include <string>
#define N 1000
using namespace std;

struct person
{
	string name;
	int sign_in;
	int sign_out;
	person():sign_in(9999999999),sign_out(0){}
};

person total[N];

string time_sign_in[N];
string time_sign_out[N];
int timetoint(string str)
{
	return ((str[0]-'0')*10+(str[1]-'0'))*3600+((str[3]-'0')*10+(str[4]-'0'))*60+((str[6]-'0')*10+(str[7]-'0'));
}



int main()
{
	int k;
	cin>>k;
	for(int i=0;i!=k;i++)
	{
		cin>>total[i].name;
		cin>>time_sign_in[i];
		cin>>time_sign_out[i];
		total[i].sign_in=timetoint(time_sign_in[i]);
		total[i].sign_out=timetoint(time_sign_out[i]);
	}
	int first=0,last=0;
	for(int i=1;i!=k;i++)
	{
		if(total[i].sign_in<total[first].sign_in)
			first=i;
		if(total[i].sign_out>total[first].sign_out)
			last=i;
	}

	cout<<total[first].name<<" "<<total[last].name;
    return 0;
}



