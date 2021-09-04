# Binary Tree

<ul>
  <li>Non-linear data structure</li>
  <li>Used for storing information that naturally forms a hierarchy</li>
  <li>Information is easily searchable and used for multi-stage decision making</li>
</ul>

```js
  tree
      ----
       j    <-- root
     /   \
    f      k  
  /   \      \
 a     h      z    <-- leaves

```
### representing a tree node using structures
```js
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
```
### Code
```js
//using linked list
#include<iostream>
using namespace std;

struct Node{
int data;
struct Node* right;
struct Node* left;

Node(int val){
data = val;
right = left = NULL;
}
};
int main(){
struct Node* root  = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
return 0;
}

               1
            /     \
           2       3
          / \     / \
      NULL  NULL NULL NULL
     
```

```js
//using array
#include<iostream>
using namespace std;

char tree[100];

void root(char c){
if(tree[0] != '\0'){
cout<<"root already exist"<<endl;
return;
}
else tree[0] = c;
}

void set_left(char c, int parent){
if(tree[parent] == '\0'){cout<<"parent does not exist"<<endl;}
else{
tree[parent*2 + 1] = c;
}
}

void set_right(char c, int parent){
if(tree[parent] == '\0'){cout<<"parent does not exist"<<endl;}
else{
tree[parent*2 + 2] = c;
}
}

void print(){
for(int i = 0;i<101;i++){
if(tree[i] != '\0')cout<<tree[i]<<" ";
else{cout<<"-"<<" ";}
}

}

int main(){
root('A');
set_left('B',0);
set_right('C',0);
set_left('D',1);
set_right('E',1);
set_right('F',2);
print();
return 0;
}
```

## Properties

<ul>
  <li>The maximum number of nodes at level ‘l’ of a binary tree is 2^l. </li>
  <li>The Maximum number of nodes in a binary tree of height ‘h’ is 2^(h+1) – 1. (height of root is considered as 0)</li>
  <li>In a Binary Tree with N nodes, minimum possible height is Log2(N+1) - 1. (height of root node is considered as 0)</li>
</ul>

## Types of Binary Tree

<li>Complete Binary Tree</li>

```js
if all the levels are completely filled except possibly the last level and the last level has all
keys as left as possible 
               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40
     /  \   /
    8   7  9 
```

<li>Full Binary Tree</li>

```js
 A Binary Tree is a full binary tree if every node has 0 or 2 children.
             18
           /    \   
         15     20    
        /  \       
      40    50   
    /   \
   30   50
```

<li>Perfect Binary Tree</li>

```js
 Tree in which all the internal nodes have two children and all leaf nodes are at the same level. 
              18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40
 leaves Node = total internal nodes + 1     
```

<li>Balanced Binary Tree</li>

```js
A binary tree is balanced if the height of the tree is O(Log n) where n is the number of nodes.
Example:-AVL tree, Red-Black trees
```

<li>degenerate (or pathological) tree</li>

```js
A Tree where every internal node has one child. Such trees are performance-wise same as linked list. 
      10
      /
    20
     \
     30
      \
      40 
```
