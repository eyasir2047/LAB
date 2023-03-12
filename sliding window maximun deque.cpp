//1 3 -1 -3 5 3 6 7
//k=3
//ans=3 3 5 5 6 7
//k= window size
#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int>ans;
    deque<int>dq;//storing index at deque

    for(int i=0;i<n;i++){
        if(!dq.empty() and dq.front()==i-k)
        dq.pop_front();
        while(!dq.empty() && a[dq.back()]<=a[i])
        dq.pop_back();

        dq.push_back(i);
        if(i>=k-1)ans.push_back(a[dq.front()]);
    }

    for(auto i:ans)
    cout<<i<<" ";


    return 0;


}
