#include<iostream>
#include<deque>
#include<unordered_map>
using namespace std;

class LRUcache{
deque<int> dq;
unordered_map<int,deque<int>::iterator> m;
int SIZE;
public:
LRUcache(int n){SIZE = n;}
void refer(int n){
if(m.find(n) == m.end()){//checking for presence of cache
if(dq.size()==SIZE){//cache is full
int ele = dq.back();
dq.pop_back();
m.erase(ele);
}
}
else{
dq.erase(m[n]);//erasing refrence if cache is present
}
dq.push_front(n);
m[n] = dq.begin();

}
void display(){
for(auto it = dq.begin();it!=dq.end();it++){
cout<<(*it)<<" ";
}
cout<<endl;
}
};

int main(){
LRUcache l(4);
l.refer(1);
l.refer(2);
l.refer(3);
l.refer(1);
l.refer(4);
l.refer(5);
l.display();
return 0;
}
