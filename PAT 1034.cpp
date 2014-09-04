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

#define M 1001
#define IFN 99999999


string investigate(vector<string>  &cur_gang, map<string, int> &call_time, int k){
	int max_time=0;
	string head;
	int total_time=0;
	for(auto i=cur_gang.begin(); i!=cur_gang.end(); ++i){
		total_time += call_time[*i];
		if(call_time[*i]> max_time){
			head = *i;
			max_time =call_time[*i];
		}else if(call_time[*i] == max_time && *i < head){
			head= *i;
		}
	}

	if(total_time > 2*k)
		return head;
	else
		return "";
}




int main(){
	int n, k;

	map<string, int> call_time;
	
	map<string, set<string>> phoneCalls;

	set<string> members;
	cin>>n>>k;

	for(int i=0; i!=n; ++i){
		string s1, s2;
		int time;
		cin>>s1>>s2>>time;

		call_time[s1] += time;
		call_time[s2] += time;
		phoneCalls[s1].insert(s2);
		phoneCalls[s2].insert(s1);
		
		members.insert(s1);
		members.insert(s2);
	}
	vector<pair<string, int>> result;

	int gang_nums=0;

	while(!members.empty()){
		string temp= *members.begin();
		members.erase(temp);
		vector<string> cur_gang;
		queue<string> cur;
		cur.push(temp);
		while(!cur.empty()){
			string one =cur.front();
			cur.pop();
			cur_gang.push_back(one);
			for(auto i=phoneCalls[one].begin(); i!=phoneCalls[one].end(); ++i){
				if(members.count(*i)){
					cur.push(*i);
					members.erase(*i);
				}
			}

		}
		if(cur_gang.size()<3)
			continue;
		else{
			int num=cur_gang.size();
			string head = investigate(cur_gang, call_time, k);
			if(head=="")
				continue;
			else{
				result.push_back(make_pair(head, num));
				++gang_nums;
			}
		}
	}
	cout<<gang_nums<<endl;
	sort(result.begin(), result.end(), [](const pair<string, int> &a, const pair<string, int> &b){return a.first < b.first ;});
	for(int i=0; i!=result.size(); ++i){
		cout<<result[i].first<<" "<<result[i].second<<endl;
	}



	cin.get();
	return 0;
}
