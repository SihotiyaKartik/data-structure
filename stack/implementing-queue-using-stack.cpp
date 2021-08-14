#include<iostream>
#include<stack>
using namespace std;

class queue{
stack<int> s1,s2;
public:

void enqueue(int x){
//moving all elements from s1 to s2  
while(!s1.empty()){
s2.push(s1.top());
s1.pop();
}
//pushing into s1  
s1.push(x);

//moving all elements back to s1 from s2  
while(!s2.empty()){
s1.push(s2.top());
s2.pop();
}
}
//removing element from s1
void dequeue(){
if(s1.empty())cout<<"empty"<<endl;
int x = s1.top();
s1.pop();
cout<<x<<" is removed"<<endl;

}
};

int main(){
//Write your code here
queue q;
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
q.dequeue();
return 0;
}
