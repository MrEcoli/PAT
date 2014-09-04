
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#define MAX 999999
using namespace std;


struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int x): val(x),left(nullptr),right(nullptr){}
};

typedef Node* pNode;

pNode treeRebuilt(int postorder[], int inorder[], int n){
	if(n==0)
		return nullptr;
	pNode root= new Node(postorder[n-1]);
	if(n==1)
		return root;

	int value= postorder[n-1];
	int i;
	for(i=0; i!=n;++i){
		if(inorder[i]==value)
			break;
	}
	root->left=treeRebuilt(postorder,inorder,i);
	root->right= treeRebuilt(postorder+i, inorder+i+1, n-i-1);
	return root;
}

void printTree(pNode root){
	if(root!=nullptr){
		printTree(root->left);
		cout<<root->val<<" ";
		printTree(root->right);
	}
}

vector<int> levelTraverse(pNode root){
	queue<pNode> node_queue;
	node_queue.push(root);
	vector<int> result;
	while(!node_queue.empty()){
		pNode cur= node_queue.front();
		node_queue.pop();
		result.push_back(cur->val);
		if(cur->left!=nullptr)
			node_queue.push(cur->left);
		if(cur->right!=nullptr)
			node_queue.push(cur->right);
	}
	return result;
}


int main(){
	int num;
	int inorder[31];
	int postorder[31];
	cin>>num;
	if(num<=0)
		return -1;
	int a,b;
	for(int i=0; i!=num; ++i){
		cin>>a;
		postorder[i]=a;
	}
	for(int i=0; i!=num; ++i){
		cin>>b;
		inorder[i]=b;
	}

	pNode root=treeRebuilt(postorder, inorder, num);
	vector<int> result;
	result=levelTraverse(root);
	for(int i=0; i!=result.size(); ++i){
		cout<<result[i];
		if(i!=result.size()-1)
			cout<<" ";
	}

	cin.get();
	return 0;

}
