# Map
#### Maps are associate container that store elements in <key,value> form and no two value can have the same key.

### some functions:-
>  - begin()
> 
>  - end()
> 
>  - size()
> 
>  - max_size()
> 
>  - pair insert(key,value)
> 
>  - empty()
> 
>  - clear()

### Code
```cpp
#include<iostream>
#include<iterator>
#include<map>

using namespace std;

int main(){
map<int,int> mp;
mp.insert(pair<int,int>(10,20));
mp.insert(pair<int,int>(20,30));
mp.insert(pair<int,int>(30,40));
mp.insert(pair<int,int>(40,50));
mp.insert(pair<int,int>(50,60));

map<int,int>::iterator itr;
cout<<"Key value pair of mp is: "<<endl;
for(itr=mp.begin();itr!=mp.end();++itr){
cout<<itr->first<<" "<<itr->second<<endl;
}

//assigning elements of mp to mp1
map<int,int> mp1(mp.begin(),mp.end());
cout<<"Key value pair of mp1 is: "<<endl;
for(itr=mp1.begin();itr!=mp1.end();++itr){
cout<<itr->first<<" "<<itr->second<<endl;
}

//Erasing all elements with key = 20
mp.erase(20);
cout<<"Key value pair of mp after removing key=20 is: "<<endl;
for(itr=mp.begin();itr!=mp.end();++itr){
cout<<itr->first<<" "<<itr->second<<endl; 
}

return 0;
}
```
### Output

```
Key value pair of mp is: 
10 20
20 30
30 40
40 50
50 60

Key value pair of mp1 is: 
10 20
20 30
30 40
40 50 
50 60

Key value pair of mp after removing key=20 is: 
10 20
30 40
40 50 
50 60
```

### some different way to insert and print elements

```cpp
map<int,int> mp;
mp[10] = 20;
mp[20] = 30;
mp[30] = 40;
mp[40] = 50;
mp[50] = 60;

for(auto x:mp){
cout<<x.first<<" "<<x.second<<endl; 
}
```
  
