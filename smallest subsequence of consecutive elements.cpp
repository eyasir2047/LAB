#include<vector>
#include<queue>
#include<iostream>
using namespace std;

vector<int> findSubsequence(queue<int> q, int x){
    int n = q.size();
    int sum = 0;
    vector<int> res;
    int len = INT_MAX;
    queue<int> temp;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        sum += front;
        temp.push(front);
        
        while(sum >= x){
            if(temp.size() < len){
                len = temp.size();
               /* for(int i=0;i<res.size();i++)
                cout<<res[i]<<" ";
                cout<<endl;*/

                res.clear();
                queue<int> copy = temp;
                for(int i=0; i<len; i++){
                    res.push_back(copy.front());
                    copy.pop();
                }
            }
            sum -= temp.front();
          //  cout<<"tempfront: "<<temp.front()<<endl;
            temp.pop();
        }

    }
    return res;
}

int main(){
    queue<int> q;
    int x = 7;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    //q.push(2);

    vector<int> res = findSubsequence(q, x);

    if(res.size()==0)
        cout<<"No subsequence found!"<<endl;
    else{
        cout<<"Smallest subsequence: ";
        for(int i=0; i<res.size(); i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
