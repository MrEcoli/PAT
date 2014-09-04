#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>


using namespace std;
#define MAX 100009


int bit[MAX];
int stack[MAX];
int sum(int idx){
	int result=0;
	while(idx>0){
		result += bit[idx];
		idx -= idx&-idx;
	}
	return result;
}

void update_bit(int idx, int val){

	while(idx<MAX){
		bit[idx] +=val;
		idx += (idx&-idx);
	}
}

int BITmedian(int first, int last, int pur){
	
	int mid, cur;

	while(first<last){
		mid=(first+last)/2;
		cur=sum(mid);
		if(cur>=pur)
			last=mid;
		else
			first=mid+1;
	}
	return first;

}


int main(){
	int n;
	scanf("%d",&n);

	char op[15];
	int cur_pos=0;
	int key;
	while(n--){
		scanf("%s",op);
		if(strcmp(op,"Push")==0)
		{
			scanf("%d",&key);
			update_bit(key, 1);
			stack[cur_pos++]=key;
		}
		else if(strcmp(op,"Pop")==0)
		{
			if(cur_pos==0)
				printf("Invalid\n");
			else{
				update_bit(stack[cur_pos-1],-1);
				printf("%d\n",stack[cur_pos-1]);
				--cur_pos;
			}
		}
		else if(strcmp(op,"PeekMedian")==0){
			if(cur_pos==0)
				printf("Invalid\n");
			else{
				int result=BITmedian(1,MAX-1,(cur_pos+1)/2);
				printf("%d\n",result);
			}
		}
		else
			printf("Invalid\n");
	}

	return 0;
}
