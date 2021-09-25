# Binary Search Tree
#### Binary Search Tree is a node-based binary tree data structure which has the following properties:
<li> The left subtree of a node contains only nodes with keys lesser than the node’s key </li>
<li> The right subtree of a node contains only nodes with keys greater than the node’s key. </li>
<li> The left and right subtree each must also be a binary search tree </li>

### Code
```cpp
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
### Deletion in binary search tree
<li> Deleting Leaf Node </li>
<li> Deleting Node with only one child </li>
<li> Deleting Node with two chil </li>

### Code
```cpp
#include<iostream>
using namespace std;

struct Node{
int data;
Node *right,*left;
};

struct Node* newNode(int val){
Node* temp = new Node();
temp->data = val;
temp->right = temp->left = NULL;
return temp;
}

void inorder(Node* root){
if(!root)return;
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}

Node* insert(Node* root, int val){
if(root==NULL)return newNode(val);
if(val<root->data){
root->left = insert(root->left,val);
}
else{
root->right = insert(root->right,val); 
}
return root;
}

Node* minNode(Node* root){
Node* curr = root;
while(curr && curr->left != NULL){curr = curr->left;}
return curr;
}

Node* deleteNode(Node* root, int val){
if(root==NULL)return root;
if(val < root->data){
root->left = deleteNode(root->left,val);
}
else if(root->data < val){
root->right = deleteNode(root->right,val);
}
else{
         if(root->left==NULL and root->right==NULL)
            return NULL;
       
        // node with only one child or no child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
}
return root;

}

int main(){
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    cout << "Inorder traversal of the given tree \n";
    inorder(root);
 
    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    cout << "\nDelete 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    cout << "\nDelete 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    return 0;


}
```

