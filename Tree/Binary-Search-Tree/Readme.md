# Binary Search Tree
#### Binary Search Tree is a node-based binary tree data structure which has the following properties:
<li> The left subtree of a node contains only nodes with keys lesser than the node’s key </li>
<li> The right subtree of a node contains only nodes with keys greater than the node’s key. </li>
<li> The left and right subtree each must also be a binary search tree </li>

### Code
```js
#include<iostream>
using namespace std;

class BST{
int data;
BST *left,*right;

public:

BST();

BST(int);

BST* insert(BST*,int);

void inorder(BST*);
}

BST::BST(){
data = 0;
right = left = NULL;
}

BST::BST(int val){
data = val;
right = left = NULL;
}

BST* BST::Insert(BST* root, int val){
if(root==NULL){
return new BST(val);
}
if(val > root->data){
root->right = Insert(root->right,val);
}
else{
root->left = Insert(root->left,val);
}
return root;
}

void BST::inorder(BST* root){
if(root==NULL)return;
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}

int main(){
BST b;
BST *root = NULL;
root = b.insert(root,1);
b.insert(root,9);
b.insert(root,3);
b.insert(root,7);
b.insert(root,5);
b.inorder(root);
return 0;

}
```
### Output
```js
1 3 5 7 9
```
