# Set
#### An Associate container in which element has to be unique.

### Some basic function associated with set
> - begin()
> 
> - end()
> 
> - size()
> 
> - max_size()
> 
> - insert()
> 
> - empty()

### Code
```cpp
#include<iostream>
#include<set>
#include<iterator>

using namespace std;

int main(){
set<int,greater<int> > s; //elements will be stored in descending order
s.insert(1);
s.insert(5);
s.insert(2);
s.insert(4);
s.insert(3);

set<int,greater<int> >::iterator itr;
cout<<" The elements of s are: "<<endl;
for(itr=s.begin();itr!=s.end();++itr){
cout<<*itr<<" ";
}
cout<<endl;

//assigning elements of set s into set s1
set<int> s1(s.begin(),s.end()); elements will be stored in ascending order

cout<<"The elemenst of s1 are: "<<endl;
for(itr=s1.begin();itr!=s1.end();++itr){
cout<<*itr<<" ";
}
cout<<endl;

//removing element with value equals to 3 from set s
s.erase(3);
cout<<"Elements of set s after removing 3 is: "<<endl;
for(itr=s.begin();itr!=s.end();++itr){
cout<<*itr<<" ";
}
cout<<endl;

return 0;
}
```
### Output
```
 The elements of s are: 
 5 4 3 2 1
 The elements of s1 are:
 1 2 3 4 5
 Elements of set s after removing 3 is: 
 1 2 4 5
 ```
 
 
 

