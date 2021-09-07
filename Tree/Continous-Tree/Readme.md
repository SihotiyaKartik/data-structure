# Continous Tree
<p> A tree is a Continuous tree if in each root to leaf path, the absolute difference between keys of two adjacent is 1</p>

### Code

```js
#include<iostream>
using namespace std;

struct Node{
int data;
Node *left,*right;
};

Node* newNode(int data){
Node* temp = new Node();
temp->data = data;
temp->right = temp->left = NULL;
return temp;
}

bool isContinous(Node* root){
if(root==NULL)return true;
if(root->right==NULL && root->left==NULL)return  NULL;
if(root->left==NULL){
return (abs(root->data,root->right->data)==1) && isContinous(root->right);
}
if(root->right==NULL){
return (abs(root->data,root->left->data)==1) && isContinous(root->left);
}
return abs(root->data,root->left->data)==1 && abs(root->data,root->right->data)==1 && 
isContinous(root->left) && isContinous(root->right);
}

int main(){
   Node* root = newNode(7);
   root->left= newNode(5);
   root->right = newNode(8);
   root->left->left  = newNode(6);
   root->left->right = newNode(4);
   root->right->right = newNode(10);
   isContinous(root) ? "Yes" : "No";
   return 0;
}
```

### Output
```js
No
```
