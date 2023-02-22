#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*  next;
};

class Stack{
    struct Node* top;
public:
    //constructor
    Stack(){
        top= NULL;
       
    }

   void push(int value){
    Node* ptr=new Node;
    ptr->data= value;
    //ptr->next=NULL;
    //if(top!=NULL){
    //    ptr->next= top;

   // }
   ptr->next=top;
    top=ptr;

   

   }

   void pop(){
    Node* temp;
    if(top==NULL){
        cout<<"Empty Stack"<<endl;
        return;
    }

    temp=top;
    top=temp->next;//top->next
    cout<<"popped element "<<temp->data<<endl;
    delete temp;

   }
   
   void display(){
    Node* temp=top;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
   }

   bool isempty(){
    if(top==NULL) return true;

    return false;

   }

};

int main(){
    Stack s;
    int n;
    cin>>n;
    int ele;

    for(int i=0;i<n;i++){
        cin>>ele;
        s.push(ele);
    }
    s.display();

    for(int i=0;i<n;i++)
    s.pop();

    cout<<s.isempty()<<endl;

}