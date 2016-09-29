#include<bits/stdc++.h>

using namespace std;
struct node{
int data;
struct node* left;
struct node* right;

node( int a){
data = a;
left = NULL;
right = NULL;
}
};

void kthlargest(node* root, int &k){
if(root == NULL)
	return;

kthlargest(root->right, k);
k = k-1;
if(k==0){
	cout<<root->data<<endl;
	return;
}

//if(k > 1)
	kthlargest(root->left, k);
//}
}

int main(){
int v = 7;
node* root = new node(50);
root->left = new node(20);
root->left->right = new node(40);
root->left->right->left = new node(30);
root->right = new node(70);
root->right->right = new node(80);

int a = 6;
kthlargest(root, a);
return 0;
}
