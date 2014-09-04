#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define MAX 1001

int ary[MAX];

struct Node{
	int val;
	Node* left;
	Node* right;
	Node(){}
	Node(int x):val(x),left(nullptr),right(nullptr){}
};

typedef Node* pNode;

bool is_Binary(int ary[], int num){
	if(num==1 || num==0)
		return true;
	int pos;
	for(pos=1; pos!=num; ++pos){
		if(ary[pos]>=ary[0])
			break;
	}
	for(int i=pos; i!=num; ++i){
		if(ary[i]<ary[0])
			return false;
	}
	return is_Binary(ary+1, pos-1) &&is_Binary(ary+pos, num-pos);
}

bool is_mirror(int ary[], int num){
	if(num==1 || num==0)
		return true;
	int pos;
	for(pos=1; pos!=num; ++pos){
		if(ary[pos]<ary[0])
			break;
	}
	for(int i=pos; i!=num; ++i){
		if(ary[i]>=ary[0])
			return false;
	}
	return is_mirror(ary+1, pos-1) && is_mirror(ary+pos, num-pos);
}

pNode built(int ary[],int num){
	if(num==0)
		return nullptr;
	if(num==1){
		pNode root= new Node(ary[0]);
		return root;
	}
	int pos=0;
	for(pos=1; pos!=num; ++pos){
		if(ary[pos]>=ary[0])
			break;
	}
	pNode root=new Node(ary[0]);
	root->left =built(ary+1, pos-1);
	root->right=built(ary+pos,num-pos);

	return root;
}

pNode built_mirror(int ary[], int num){
	if(num==0)
		return nullptr;
	if(num==1){
		pNode root= new Node(ary[0]);
		return root;
	}
	int pos;
	for(pos=1; pos!=num; ++pos){
		if(ary[pos]<ary[0])
			break;
	}
	pNode root=new Node(ary[0]);
	root->left =built_mirror(ary+1, pos-1);
	root->right=built_mirror(ary+pos,num-pos);
	
	return root;
	
}


void postOrder(vector<int> &result, pNode root){
	if(root!=nullptr){
		postOrder(result,root->left);
		postOrder(result, root->right);
		result.push_back(root->val);
	}
}

void print(vector<int> &result){
	cout<<"YES"<<endl;
	for(int i=0;i!=result.size(); ++i){
		cout<<result[i];
		if(i!=result.size()-1)
			cout<<" ";
	}

}

int main()
{	
	int n;
	cin>>n;
	for(int i=0; i!=n; ++i){
		cin>>ary[i];
	}
	vector<int> result;
	pNode root=nullptr;
	if(is_Binary(ary, n)){
		root=built(ary,n);
		postOrder(result, root);
		print(result);
	}else if(is_mirror(ary, n)){
		root=built_mirror(ary,n);
		postOrder(result, root);
		print(result);
	}else
		cout<<"NO"<<endl;




	cin.get();
	return 0;
}
