#include<iostream>
#include<queue>
using namespace std;

void printQueue(queue<int> q){
while(!q.empty()){
cout<<q.front()<<" ";
  q.pop();
}
}

void reverseQueue(queue<int> &q){
if(q.empty())return;
  int data = q.front();
  q.pop();
  reverseQueue(q);
  q.push(data);
}

int main(){
queue<int> q;
  q.push(1);
  q.push(2);
  
  q.push(3);
  q.push(4);
  q.push(5);
  reverseQueue(q);
  printQueue(q);
  return 0;
  
}
