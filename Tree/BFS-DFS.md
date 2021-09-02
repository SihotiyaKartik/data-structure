# Breadth First Search

#### Level order traversal of a tree is breadth first traversal for the tree. 

<img src='https://media.geeksforgeeks.org/wp-content/cdn-uploads/level_order_traversal.png'>

#### Level order traversal of the above tree is 1 2 3 4 5 

## Code

```js
#include<iostream>
#include<queue>
using namespace std;

struct Node{
int data;
struct Node *left, *right;
};

void LevelOrder(Node* root){
if(root==NULL) return;
queue<Node*> q;
q.push(root);
while(!q.empty()){
Node* temp = q.front();
cout<<temp->data<<" ";
q.pop();
if(temp->left != NULL)q.push(temp->left);
if(temp->right != NULL)q.push(temp->right);
}
}

Node* newNode(int x){
Node* temp = new Node();
temp->data = x;
temp->left = temp->right = NULL;
return temp;
}

int main(){
Node* root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
LevelOrder(root);
return 0;
}
```
### Output

```js
1 2 3 4 5
```
 ```js
Time Complexity: O(n) where n is the number of nodes in the binary tree 
Space Complexity: O(n) where n is the number of nodes in the binary tree 
```
# Depth First Search

<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/2009/06/tree12.gif">

##### Depth First Traversals: 
##### (a) Inorder (Left, Root, Right) : 4 2 5 1 3 
##### (b) Preorder (Root, Left, Right) : 1 2 4 5 3 
##### (c) Postorder (Left, Right, Root) : 4 5 2 3 1
##### Breadth First or Level Order Traversal : 1 2 3 4 5 

## Code

```js
#incldue<iostream>
using namespace std;

struct Node{
int data;
struct Node *left,*right;
};

Node* createNode(int x){
Node* temp = new Node();
temp->data = x;
temp->left = temp->right = NULL;
return temp;
}

void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(node->left);
 
    // then recur on right subtree
    printPostorder(node->right);
 
    // now deal with the node
    cout << node->data << " ";
}
 
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout << node->data << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}
 
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first print data of node */
    cout << node->data << " ";
 
    /* then recur on left sutree */
    printPreorder(node->left);
 
    /* now recur on right subtree */
    printPreorder(node->right);
}

int main(){
    Node* root = createNode(1);
    root->left = createNode(1);
    root->right = createNode(1);
    root->left->left = createNode(1);
    root->left->right = createNode(1);
 
    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);
 
    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);
 
    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);
 
    return 0;
}
```

### Output

```js
Preorder traversal of binary tree is
1 2 4 5 3 
Inorder traversal of binary tree is
4 2 5 1 3 
Postorder traversal of binary tree is
4 5 2 3 1
```
