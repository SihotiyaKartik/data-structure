# [Trie](https://www.javatpoint.com/trie-data-structure)
 - derived from the word "retrieval" and used for searching key in O(m) time where m is length of key(string).
 - also known as digital tree or prefix tree
 - root node is always null
 - each child node is sorted alphabetically
 
 ## Basic operation
 - insertion
 - deletion 
 - searching

```cpp

#include<iostream>
using namespcae std;
const int A_SIZE = 26;

struct Trie(){

struct Trie *children[A_SIZE];

bool isEnd;

}

struct Trie *createNode(){
struct Trie *newNode = new Trie();
newNode->isEnd = false;
for(int i=0;i<A_SIZE;i++){
newNode->children[i] = NULL:
}
return newNode;

}

void insert(struct Trie *root, string s){
struct Trie *temp = root;
for(int i=0;i<s.length();i++){

int index = s[i] - 'a';

if(!temp->children[index]){
temp->children[index] = createNode();
}
temp = temp->children[index];
}
temp->isEnd = true;

}

//return true if key is present in trie
bool search(struct Trie *root, string s){
struct Trie *temp = root;

for(int i=0;i<s.length();i++){

int index = s[i] - 'a';
if(!temp->children[index]){
return false;
}
temp = temp->children[index];

}

return (temp->isEnd);

}

int main(){

string keys[] = {the", "a", "there", "answer", "any", "by", "bye", "their"};
int n = sizeof(keys)/sizeof(keys[0]);

struct Trie *root = createNode();

for(int i=0;i<n;i++){
insesrt(root,keys[i]);
}

search(root, "the")? cout << "Yes\n" : cout << "No\n";
search(root, "these")? cout << "Yes\n" : cout << "No\n";
return 0;

}

```

