# Insertion in level order

### Code

```js
#include<iostream>
#include<queue>
using namespace std;

struct Node{
int data;
struct Node* right;
struct Node* left;
};

Node* createNode(int ele){
  Node* newNode = new Node();
  newNode->data = ele;
  newNode->left = newNode->right = NULL;
  return newNode;
}

Node* insertNode(Node* root, int ele){
if(root==NULL){
  root = createNode(ele);
  return root;
}
queue<Node*> q;
q.push(root);
    while(!q.empty()){
    Node* temp = q.front();
    q.pop();
    if(temp->left!=NULL){
      q.push(temp->left);
    }
    else{
      temp->left = createNode(ele);
      return root;
    }
    if(temp->right!=NULL){
      q.push(temp->right);
    }
    else{
      temp->right = createNode(ele);
      return root;
    }
  }
}

void inorder(Node* root){
if(root==NULL){
return;
}
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}

int main(){
    Node* root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);
    inorder(root);
    root = insertNode(root,12);
    inorder(root);
    return 0;
}
```
<img src='https://media.geeksforgeeks.org/wp-content/uploads/binary-tree-insertion.png' height='300' width='800'>

# Deletion in Binary Tree
##### The deleted Node will pe replaced by bottom-most and rightmost node.
### Algorithm
```js
1) Starting at the root, find the deepest and rightmost node in binary tree and node which we want to delete. 
2) Replace the deepest rightmost node’s data with the node to be deleted.
3) Then delete the deepest rightmost node.
```
### Code
```js
#include<iostream>
#include<queue>
using namespace std;

struct Node(){
int data;
struct Node* right;
struct Node* left;
};

struct Node* newNode(int ele){
struct Node* temp = new Node();
temp->data = ele;
temp->right = temp->left = NULL;
return temp;
}

void inorder(Node* root){
if(root==NULL)return;
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}

//deep is deepest and rightmost node
void deleteDeepest(Node* root, Node* deep){
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
  Node* temp = q.front();
  q.pop();
  if(temp == deep){
  temp = NULL;
  delete deep;
  return;
  }
  if(temp->right){
  if(temp->right == deep){
  temp->right = NULL;
  delete deep;
  return;
  }
  else{q.push(temp->right);}
  }
  if(temp->left){
  if(temp->left == deep){
  temp->left = NULL;
  delete deep;
  return;
  }
  else q.push(temp->left);
  }
  }
}

Node* deletion(struct Node* root, int key){
if(root == NULL)return NULL;
if(root->left==NULL && root->right==NULL){
if(root->data==key){
return NULL;
}
else return root;
}
queue<Node*> q;
q.push(root);
Node* key_Node = NULL;
while(!q.empty()){
Node* temp = q.front();
q.pop();
if(temp->data == key)key_Node = temp;
if(temp->left)q.push(temp->left);
if(temp->right)q.push(temp->right);
}
//temp points to deepest and rightmost node
if(key_Node != NULL){
int x = temp->data;
deleteDeepest(root,temp);
key_Node->data = x;
}
return root;  
}
