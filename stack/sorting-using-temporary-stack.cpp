#include<iostream>
#include<stack>
using namespace std;

//function which returns a stack and take a input which is stack
stack<int> S(stack<int> &inputStack){
stack<int> temp;
while(!S.empty()){
int tmp = S.top();
S.pop();
while(!temp.empty() && temp.top() > tmp){
S.push(temp.top());
temp.pop();
}
temp.push(tmp);
}
return temp;

}

int main(){
stack<int> s;
s.push(10);
s.push(5);
s.push(20);
s.push(1);
s.push(15);
stack<int> res = S(s);

while(!res.empty()){
cout<<res.top()<<" ";
res.pop();
}
cout<<endl;

}

/*Dry run:-
input:[10,5,20,1,15]

element remove 15
inputStack:[10,5,20,1]
temp:[15]

element remove 1
inputStack:[10,5,20,15]
temp:[1]

element remove 15
inputStack:[10,5,20]
temp:[1,15]

element remove 20
inputStack:[10,5]
temp:[1,15,20]

element remove 5
inputStack:[10,20,15]
temp:[1,5]

element remove 15
inputStack:[10,20]
temp:[1,5,15]

element remove 20
inputStack:[10]
temp:[1,5,15,20]

element remove 10
inputStack:[20,15]
temp:[1,5,10]

element remove  15
inputStack:[20]
temp:[1,5,10,15]

element remove 20
temp:[1,5,10,15,20].....sorted

*/
