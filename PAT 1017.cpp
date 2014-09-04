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

struct customer{
	int arrive_time;
	int process_time;
	bool operator<(const customer &a) const{
		return arrive_time>a.arrive_time;
	}
};

struct window{
	int time;
	bool operator<(const window &rhs)const{
		return time> rhs.time;
	}
};

int main(){
	int n, k;
	cin>>n>>k;
	priority_queue<window> Windows;
	priority_queue<customer> Customers;

	for(int i=0; i!=n; ++i){
		int hh, mm, ss, time, process;
		scanf("%d:%d:%d %d",&hh, &mm, &ss, &process);
		time =3600 *hh +mm*60+ ss;
		if(process>60)
			process=60;
		customer temp;
		temp.process_time=process*60;
		temp.arrive_time =time;
		Customers.push(temp);
	}

	while(k--){
		window w;
		w.time= 8*3600;
		Windows.push(w);
	}
	int num=0;
	double total_time=0;
	while(!Customers.empty()){
		customer cu= Customers.top();
		Customers.pop();

		window w= Windows.top();
		Windows.pop();
		if(cu.arrive_time >17*3600)
			break;
		++num;

		if(cu.arrive_time < w.time){
			total_time += (w.time - cu.arrive_time);
			w.time += cu.process_time;
		}
		else{
			w.time = cu.arrive_time +cu.process_time;
		}
		Windows.push(w);
	}
	printf("%.1lf", (total_time/num)/60);

	cin.get();
	return 0;
}
