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
	int hgt;
	node(int x):val(x),left(nullptr), right(nullptr),hgt(0){}
};

typedef node* pNode;


int height(pNode root){
	if(root==nullptr)
		return -1;
	else
		return root->hgt;
}

pNode rightRotation(pNode k1){
	pNode k2=k1->left;
	k1->left=k2->right;
	k2->right=k1;
	k2->hgt= max(height(k2->left), height(k2->right)) +1;
	k1->hgt =max(height(k1->left), height(k1->right)) +1;
	return k2;
}

pNode leftRotation(pNode k1){
	pNode k2=k1->right;
	k1->right =k2->left;
	k2->left=k1;

	k2->hgt= max(height(k2->left), height(k2->right)) +1;
	k1->hgt =max(height(k1->left), height(k1->right)) +1;
	return k2;
}


pNode insert(pNode root, int cur){
	if(root==nullptr){
		root=new node(cur);
	}
	else if(root->val<cur)
	{
		root->right=insert(root->right, cur);
		if(height(root->right)-height(root->left) == 2)
			if(cur>root->right->val)
				root= leftRotation(root);
			else{
				root->right =rightRotation(root->right);
				root =leftRotation(root);
			}

	}
	else{
		root->left=insert(root->left, cur);
		if(height(root->left)- height(root->right) ==2)
			if(cur<root->left->val)
				root=rightRotation(root);
			else{
				root->left =leftRotation(root->left);
				root=rightRotation(root);
			}
	}

	root->hgt=max(height(root->left), height(root->right)) +1;
	return root;
}





int main(){

	int n, m;
	cin>>n;

	pNode root=nullptr;

	for(int i=0; i!=n; ++i){
		cin>>m;
		root=insert(root, m);
	}
	cout<<root->val<<endl;

	return 0;
}
