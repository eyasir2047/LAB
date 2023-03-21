//ordered set ->implemented using balanced BST
#include<set>
#include<iostream>
#include<unordered_set>

using namespace std;
int main(){
    set<int>s;
    s.insert(1);
     s.insert(2);
      s.insert(3);
       s.insert(3);

       for(auto i: s)
       cout<<i<<" ";
       cout<<endl;

       for(auto i=s.begin();i!=s.end();i++)
       cout<<*i<<" ";

       cout<<endl;

       for(auto i=s.rbegin();i!=s.rend();i++ )
       cout<<*i<<" ";
       cout<<endl;

       cout<<s.size()<<endl;

       //lower bound and upper bound
       cout<<*s.lower_bound(2)<<endl;
       cout<<*s.lower_bound(3)<<endl;

       cout<<*s.upper_bound(3)<<endl;

       s.erase(2);
       s.erase(s.begin());

       //mutliset-> contain duplicates
       multiset<int>s2;
       s2.insert(1);
     s2.insert(2);
      s2.insert(3);
       s2.insert(3);
       s2.erase(3);//all the threes will delete

       //unordered set-> not sorted order
       //implemented through hashing 
       //no lower and upper bound as the elements are not sorted 






       

       


    return 0;
}