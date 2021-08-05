#include<iostream>
using namespace std;

class Stack{
public:
  int data;
  Stack* next;
};

int isEmpty(Stack* head){
return !head;
}

void push(Stack** head, int data){
Stack* temp = new Stack();
temp->data = data;
temp->next = *head;
*head = temp;
cout<<data<<" is pushed to stack";  
}

int pop(Stack** head){
if(isEmpty(*head))return INT_MIN;
Stack* temp = *head;
*head = *head->next;
int x = temp->data;
free(temp);
return x;
}

int peek(Stack* head){
if(isEmpty(head))return INT_MIN;
return head->data;  
}

int main(){
Stack* head = NULL;
  push(&head,1);//1 is pushed to stack
  push(&head,2);//2 is pushed to stack
  push(&head,3);//3 is pushed to stack
  
  pop(&head);//3
  while(!isEmpty(head)){
  cout<<peek(head)<<" ";
  pop(&head);
  }
  return 0;
  
}

//the size of stack can be changed during runtime
//time complexity for push, pop, peek and isEmpty is O(1) 
