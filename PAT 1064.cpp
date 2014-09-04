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

struct node{
	int val;
	node* left;
	node* right;
	node(){}
	node(int x):left(nullptr),right(nullptr),val(x){}
};
typedef node* pNode;

pNode built(int ary[], int length){
	if(length==0)
		return nullptr;
	if(length==1){
		pNode root=new node(ary[0]);
		return root;
	}


	int n=0;

	while(pow(2.0,n)-1<length){
		++n;
	}
	int half=pow(2.0,n-1);
	int pos;

	if( length >= half + half/2-1){
		pos = half-1;
	}
	else{
		pos = length - half/2;
	}
	pNode root=new node(ary[pos]);

	root->left=built(ary, pos);
	root->right=built(ary+pos+1, length-pos-1);

	return root;
}

vector<int> queueTraverse(pNode root){
	
	queue<pNode> que;

	que.push(root);

	vector<int> result;
	while(!que.empty()){
		pNode temp=que.front();
		que.pop();
		if(temp!=nullptr){
			result.push_back(temp->val);
			que.push(temp->left);
			que.push(temp->right);
		}
	}
	return result;
}

int main(){

	int n;
	scanf("%d",&n);
	int ary[M];
	for(int i=0; i!=n; ++i)
		scanf("%d",&ary[i]);
	sort(ary, ary + n);

	pNode root=built(ary, n);
	vector<int> result = queueTraverse(root);

	for(int i=0; i!=result.size()-1; ++i)
		cout<<result[i]<<" ";

	cout<<result.back();


	return 0;
}
