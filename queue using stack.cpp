#include<iostream>
#include<stack>
using namespace std;
class queue{
    stack<int>s1;
    stack<int>s2;
    //push-> O(1)
    //pop-> O(n)


    public:
    void push(int x){
        s1.push(x);
    }

    int pop(){
        if(s1.empty() and s2.empty()){
           // cout<<"Queue empty"<<endl;
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        int peek=s2.top();
        s2.pop();
        return peek;
        
    }

    bool empty(){
           if(s1.empty() and s2.empty()){
            
            return true;
        }
        return false;
    }



};
class queue2{
    stack<int>s1;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty()){
            return -1;
        }
        int x=s1.top();
        s1.pop();
        //only for single element
        if(s1.empty()) return x;

        int item=pop();//recursive call
        s1.push(x);
        return  item;


    }
    bool empty(){
           if(s1.empty()){
            
            return true;
        }
        return false;
    }




};

int32_t main(){

    queue q;
    q.push(1);
     q.push(2);
      q.push(3);
       q.push(4);
       cout<<q.pop()<<endl;
        q.push(5);
         cout<<q.pop()<<endl;

         queue2 k;
    k.push(1);
     k.push(2);
      k.push(3);
       k.push(4);
       cout<<k.pop()<<endl;
        k.push(5);
         cout<<k.pop()<<endl;


return 0;

    
}