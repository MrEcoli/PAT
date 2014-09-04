#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <random>
#include <cctype>
#include <queue>
using namespace std;

struct node;

typedef node* pNode;

struct node{
	pNode left;
	pNode right;
	int val;
};


void preOrderRecurse(pNode root){
	if(root == nullptr)
		return;
	stack<pNode> tstack;
	pNode tmp;
	tstack.push(root);
	
	while(!tstack.empty()){
		tmp = tstack.top();
		cout<<tmp->val<<" ";
		if(tmp != nullptr){
			tstack.push(tmp->right);
			tstack.push(tmp->left);
		}
	}
}

void inorderTraversal(pNode root){
	if(root == nullptr)
		return;
	pNode p = root;
	stack<pNode> tstack;
	while(p || !tstack.empty()){
		if(p){
			tstack.push(p);
			p = p->left;
		}else{
			p = tstack.top();
			tstack.pop();
			cout<<p->val<<" ";
			p=p->right;
		}
	}
}





int main(){
	
	string in, rev;

	int x, y, res = 0;
	int n;
	cin>>in;

	
	sort(in.begin(), in.end());

	if(in.size() == 4 && in[0] == in[3]){
		printf("%s - %s = 0000",in.c_str(), in.c_str());
		return 0;
	}
	if(in == string("0")){
		printf("0000 - 0000 = 0000");
		return 0;
	}

	while(res != 6174){

		n = 4 - in.size();
		if( n != 0){
			in = in + string(n, '0');
		}

		sort(in.begin(), in.end());
		rev = in;

		reverse(rev.begin(), rev.end());

		x = stoi(in);
		y = stoi(rev);

		res = y -x;
		printf("%04d - %04d = %04d\n", y, x, res);

		in = to_string(static_cast<long long>(res));
	}




	








	 
	cin.get();

}
