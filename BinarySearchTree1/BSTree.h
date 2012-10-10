#include <stdlib.h>
#include <iostream>
using namespace std;

struct BNode {
	int d;
	BNode* left;
	BNode* right;
};

typedef struct BNode* Node;

Node createBSTree(const char* expr,int& p,int length) {
	if(expr==NULL||length<=0)  return NULL;

	Node root = new struct BNode();
	int datum = 0; int i=p;
	while(p<length && expr[p]!='(' && expr[p]!=',' && expr[p]!=')') p++;
	for(;i<p;i++)
		datum = datum*10+expr[i]+(1-'1');
	root->d = datum;
	root->left = NULL;
	root->right = NULL;
	cout<<datum;

	if(expr[p]=='(') {
		cout<<'(';
		root->left = createBSTree(expr,++p,length);
		cout<<',';
		if(expr[p]==')') p++;
		root->right = createBSTree(expr,++p,length);
		cout<<')';
	}
	
	else if(expr[p]==','||expr[p]==')'||p>=length-1)
		return root;
}
