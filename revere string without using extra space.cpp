#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;
void reverse(queue < string > & q) {
    if (q.empty()) {

        return;
    }

    // Store the front element in a variable.
    string element = q.front();
    q.pop();

    // Recursively call for the rest of the queue.
    reverse(q);

    // Push back the stored element.
    q.push(element);
}

void printQueue(queue<string> q)
{

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;

    string s;
    queue<string>q;

    for(int i=0;i<n;i++){
        cin>>s;
        q.push(s);
    }

    reverse(q);
    printQueue(q);
    /*

    stack<string>st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
        }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;*/

    return 0;




    

   

    


    

}