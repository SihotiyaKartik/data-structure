#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void reverse(Node** head){
if(*head==NULL)return;
Node* prev = *head;
Node* curr = *head;
Node* temp;
curr = curr->next;
prev->next = NULL;
while(curr!=NULL){
temp = curr->next;
curr->next = prev;

prev = curr;
curr = temp;
}
*head = prev;
}

void push(Node**head,int data){
Node* T = new Node();
T->data = data;
T->next = *head;
*head = T;
}

void print(Node* head){
if(head==NULL)return;
Node* T = head;
while(T!=NULL){
cout<<T->data<<" ";
T = T->next;
}
cout<<endl;

}

int main(){
Node* head = NULL;
push(&head,1);
push(&head,2);
push(&head,3);
push(&head,4);
print(head);
reverse(&head);
print(head);
return 0;

}
//time complexity:O(n)
//space complexity:O(1)
