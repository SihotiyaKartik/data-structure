### Logic
```js
Initialize the range as {INT_MIN .. INT_MAX}. The first node will definitely be in range, so create a root node. To construct the left subtree, 
set the range as {INT_MIN …root->data}. If a value is in the range {INT_MIN .. root->data}, the values are part of the left subtree. 
To construct the right subtree, set the range as {root->data..max .. INT_MAX}
```
### Code
```js
#include<iostream>
using namespace std;

stuct Node{
int data;
Node *right,*left;
};

Node* newNode(int val){
Node* temp = new Node();
temp->data = val;
temp->right = temp->left = NULL;
return temp;
}

Node* createTreeUtil(int pre[],int* preIndex,int key,int low,int high,int size){
if(*preIndex > =size){
return NULL;}
Node* root = NULL;
if(key>=min && key<=max){
root = newNode(key);
*preIndex++;
if(*preIndex < size){
root->left = createTreeUtil(pre,preIndex,pre[*preIndex],min,key,size);
}
if(*preIndex < size){
root->right = createTreeUtil(pre,preIndex,pre[*preIndex],key,high,size);
}
}
return root;
}

Node* createTree(int pre[], int size){
int preIndex = 0;
return createTreeUtil(pre,&preIndex,pre[0],INT_MIN,INT_MAX,size);
}

void inorder(Node* root){
if(!root)return;
inorder(root->left);
cout<<root->data<<" ";
inorder(root_>right);
}

int main(){
int pre[] = {10,5,1,7,40,50};
int size = sizeof(pre)/sizeof(pre[0]);
Node* root = createTree(pre,size);
inorder(root);
return 0;
}
```
### Output
```js
1 5 7 10 40 50
```

### Time complexity
```js
O(n)
```
