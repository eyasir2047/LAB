#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//insertion,traversal, delele

class Node{
    public:
    int data;
    Node* next;//pointer

    //constructor-> must have the same name as class
    Node(int data){
        this-> data=data;
        this-> next=NULL;
    }

    ~Node(){//destructor
        int value= this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }




};

void print(Node* &head){

    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}

void insertionAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp-> next=head;
    head=temp;
    
}

void insertionAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
    temp->next=NULL;
}

void insertionAtPosition(Node* &tail,Node* &head,int position,int d){

        if(position==1){
            insertionAtHead(head,d);
            return;
        }

        Node* temp=head;
        int cnt=1;

        while(cnt<position-1){ 
            temp=temp->next;
            cnt++;
        }

        if(temp->next==NULL){//inserting at last positon
            insertionAtTail(tail,d);
            return;
        }

        Node* nodetoInsert= new Node(d);

        nodetoInsert->next= temp->next;
        temp->next=nodetoInsert;

}

void deleteNode(int position,Node* &tail,Node* &head){
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* prev=NULL;
        Node* curr=head;

        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
            
        }

        if(curr->next==NULL){//deletion of tail
           Node* temp2=tail;
           tail=prev;
            prev->next=NULL;
            delete temp2;
            return;
        }

        prev->next=curr->next;//prev->next=prev->next->next;
        curr->next=NULL;//prev->next->next=NULL
        delete curr;


    }
}

int length(Node* head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
       len++;
       temp=temp->next;
    }
    return len;
}

Node* kappend(Node* &head,int k){
    int len=0;
    Node* newHead;
    Node* newTail;

    Node* temp=head;
    

     len=length(head);
    k=k%len;//if (k>len)

    int count=1;

    while(temp->next!=NULL){
        if(count==(len-k)){
            newTail=temp;
        }
        if(count==(len-k+1)){
            newHead=temp;
        }
        temp=temp->next;
        count++;
    }
    newTail->next=NULL;
    temp->next= head;

    return newHead;



}

int main(){

    Node* head=NULL;
    Node* tail=NULL;
    int arr[]={6,5,4,3,2,1};

    for(int i=0;i<6;i++){
        insertionAtHead(head,arr[i]);
    }
    print(head);

    Node*  newHead=kappend(head,3);
    print(newHead);

    return 0;

    

    
}