#include<iostream>
using namespace std;

struct DequeNode{
int data;
DequeNode* next;
DequeNode* prev;
};

class Deque{
DequeNode* head;
DequeNode* tail;
public:
Deque(){
head = tail = NULL;
}
bool isEmpty(){
if(head==NULL)return true;
return false;
}
int size(){
if(!isEmpty()){
DequeNode* temp = head;
int len = 0;
while(temp!=NULL){
len++;
temp = temp->next;
}
return len;
}
return 0;
}
void insert_first(int x){
DequeNode* temp = new DequeNode();
temp->data = x;
if(head==NULL){
head = tail = temp;
temp->next = temp->prev = NULL;
}else{
head->prev = temp;
temp->next = head;
temp->prev = NULL;
head = temp;
}
}
void insert_last(int x){
DequeNode* temp = new DequeNode();
temp->data = x;
if(head==NULL){
head = tail = temp;
temp->next = temp->prev = NULL;
}
else{
tail->next = temp;
temp->prev = tail;
temp->next = NULL;
tail = temp;
}
}
void remove_first(){
if(!isEmpty()){
DequeNode* temp = head;
head = head->next;
if(head)head->prev = NULL;
delete temp;
if(head==NULL)tail=NULL;
return;
}
cout<<"List is empty"<<endl;
}
void remove_last(){
if(!isEmpty()){
DequeNode* temp = tail;
tail = tail->prev;
if(tail)tail->next = NULL;
delete temp;
if(tail==NULL)head=NULL;
return;
}
cout<<"List is empty"<<endl;
}
void display(){
if(!isEmpty()){
DequeNode* temp = head;
while(temp!=NULL){
cout<<temp->data<<" ";
temp = temp->next;
}
cout<<endl;
return;
}
cout<<"List is empty"<<endl;
}
};

class Queue: public Deque{
public:
void enqueue(int x){
insert_last(x);
}
void dequeue(){
remove_first();
}

};

int main(){
Queue q;
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
q.enqueue(4);
q.display();
cout<<"Size: "<<q.size()<<endl;
q.dequeue();
q.display();
cout<<"Size: "<<q.size()<<endl;
return 0;
}
