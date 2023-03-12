#include<iostream>
using namespace std;



class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
        
    }

};

class queue{
    node* front;
    node* back;

    public:
    queue(){
        front=back=NULL;
    }


    void enqueue(int x){
        node* n=new node(x);

        if(front==NULL){//first element
        back=front=n;
        back->next=front;
        return;
        }

        back-> next=n;
        back=n;
        back->next=front;
        
    }

    void dequeue(){

         if(front==NULL && back==NULL){
            cout<<"Queue underflow"<<endl;
            return;
        }

         node* todelete=front;

        if(front==back){//last element
        front=back=NULL;

        }
        else{
             front = front->next;
             back->next=front;

        }
        cout<<todelete->data<<endl;

       delete todelete;
    }

    int peek(){
        if(front==NULL && back==NULL){
            cout<<"queue empty"<<endl;
            return -1;
        }
        
        return front->data;
        
    }

    void display(){
        node* temp=front;
        if(front==NULL && back==NULL)
        cout<<"queue empty"<<endl;
        else{
            while(temp->next!=front){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<temp->data<<endl;
        }
    }


};
int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
     q.display();
    q.dequeue();
   q.display();
   q.dequeue();
   //cout<<q.isEmpty()<<endl;

    return 0;
}