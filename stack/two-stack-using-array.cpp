#include<iostream>
using namespace std;

class twostack{
int* arr;
int size;
int top1,top2;
  
public:
twostack(int n){
arr = new int[n];
size = n;
top1 = -1;
top2 = size;  
}
  
void push1(int x){
if(top1<top2-1){
top1++;
arr[top1] = x;
  
}
  else{
  cout<<"Stack overflow"<<endl;
  }
}
void push2(int x){
if(top1<top2-1){
top2--;
  arr[top2] = x;
}
  else{
  cout<<"Stack overflow"<<endl;
  }
}  
  void pop1(){
  if(top1>=0){
  cout<<"element removed"<<arr[top1]<<endl;
    top1--;
  }
    else{
    cout<<"Stack underflow"<<endl;
    }
  }
  void pop2(){
  if(top2<size){
  cout<<"element removed"<<arr[top2]<<endl;
    top2++;
  }
    else{
    cout<<"stack underflow"<<endl;}
  }
};

int main(){
twostack s(5);
  s.push1(1);
  s.push2(2);
  s.push1(3);
  s.push2(4);
  s.push1(5);
  //This is how array looks:-  1 3 5 4 2
  return 0;
  
}

//time complexity for push & pop :- O(1)
//space complexity:- O(n)
