#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int sum_kth_element(queue<int>q,int k){
    if(k<1) return 0;
    int result=0;
    int count=0;

    while(!q.empty()){
        int element=q.front();
        q.pop();
        if(count%k==0)
        result+=element;

        count++;
    }

    return result;
}
int main(){

    queue<int> q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout<<sum_kth_element(q,5)<<endl;


    return 0;
}