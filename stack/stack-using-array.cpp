//Stack is linear data structure where element is pushed and poped from only one side. Based on LIFO or FILO

#include<iostream>
using namespace std;
#define MAX 100005

class Stack{
int top;
public:
  int a[MAX];
  Stack(){top = -1;}
  bool push(int x);
  int pop();
  int peek();
  bool isEmpty();
};

//pushing an element
bool Stack::push(int x){
if(top >= MAX - 1){
cout<<"Stack Overflow";
return false;
}
else{
a[++top] = x;
cout<<x<<" is pushed in stack";
return true;
}
}

//poping an element
int Stack::pop(){
if(top < 0){
cout<<"Stack Underflow";
return 0;
}
else{
int x = a[top--];
return x;
}
}

//Returns top element of stack
int Stack::peek(){
if(top < 0){
cout<<"Stack is Empty";
return 0;
}
else{
int x = a[top];
return x;
}
}

//check if stack is empty or not
bool Stack::isEmpty(){
if(top < 0)return true;
else return false;
}

int main(){
class Stack s;
s.push(1);//1 is pushed in stack
s.push(2);//2 is pushed in stack
s.push(3);//3 is pushed in stack
s.pop();//3
while(!s.isEmpty()){
cout<<s.peek()<<" ";
s.pop();
}
return 0;
}

//implementation is not dynamic
