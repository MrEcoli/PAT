#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

struct mooncake{
	double inven;
	double wealth;
	double price;

	bool operator<(const mooncake &rhs)const{
		return price> rhs.price;
	}
};

int main(){
	int n;
	double need;
	scanf("%d %lf", &n, &need);
	
	vector<mooncake> total(n);

	for(int i=0; i!=n; ++i){
		scanf("%lf", &total[i].inven);
	}

	for(int i=0; i!=n; ++i){
		scanf("%lf", &total[i].wealth);
		total[i].price = total[i].wealth / total[i].inven;
	}
	sort(total.begin(), total.end());
	
	int num=total.size();

	double profit=0;
	for(int i=0; i!=num && need != 0; ++i){
		if(total[i].inven > need){
			profit += need * total[i].price;
			break;
		}
		else{
			profit += total[i].wealth;
			need -= total[i].inven;
		}

	}

	printf("%.2lf\n", profit);


}
