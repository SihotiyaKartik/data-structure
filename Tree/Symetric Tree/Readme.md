# Symmetric Tree
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

bool isSymmetric(Node* root1, Node* root2){
  if (root1 == NULL && root2 == NULL)
        return true;
  
  if(root1&&root2&&root1->data==root2->data){
  return isSymmetric(root1->left,root2->right) && isSymmetric(root1->right,roo2->left);
  }
  return false;
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);
    if(isSymmetric(root,root))cout<<"Symmetric";
    else cout<<"Not Symmetric";
    return 0;
}
```
#### Output
```js
Symmetric
```
