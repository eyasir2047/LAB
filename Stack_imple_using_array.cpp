//array->static
//linkedlist->dynamic 
//reverse a string, undo operation, recursion/function calling
//check the balance parenthesis-->stack
//infix to postfix/prefix
//topological, dfs, tower of hanoii
//evaluation of postfix expression

//impementation of stack using array
//static memory allocation

//peek, empty, full, size, clear, search, display

#include<iostream>
using namespace std;

#define max 1000

class Stack{
    int top;

    public:

    int arr[max];
    Stack(){//constructor
            top=-1;
    }

    bool isempty(){
        if(top==-1) return true;
        return false;
    }
    bool isfull(){
        if(top==max-1) return true;

        return false;
    }

   bool push(int x){
        if(isfull()){
            cout<<"Stack Overflow"<<endl;
            return false;
        }
       
            top++;
            arr[top]=x;
            cout<<"pushed element "<<x<<endl;
            return true;
        
    }

    void pop(){
        if(isempty()){
            cout<<"Stack Underflow"<<endl;
            return;
            
        }
        int item=arr[top];
        top--;
        cout<<"popped element"<<item<<endl;
    }

    void peek(){
        if(isempty()){
            cout<<"Stack is empty"<<endl;
            return;
        }

        cout<<"peek:"<<arr[top]<<endl;
    }

    void clear(){
        while(top!=-1){
            top--;
        }
    }

};

int main(){
    class Stack s;

    s.push(10);
    s.push(100);
    s.push(1);
    s.push(23);
    s.push(33);
    //s.clear();

    s.peek();

    s.pop();
     s.pop();
     cout<<s.isempty()<<endl;
      s.pop();
       s.pop();
        s.pop();

       cout<< s.isempty()<<endl;
       cout<<s.isfull()<<endl;

}