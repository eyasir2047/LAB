//deque->doubly ended queue
#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int>dq;
    dq.push_front(1);
    dq.push_back(2);
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;

    dq.pop_back();
    dq.pop_front();

    return 0;


}