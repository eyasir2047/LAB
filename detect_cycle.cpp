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

void makeCycle(Node* &head,int pos){
    Node* temp=head;
    Node* startNode;

    int count=1;

    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp; //cycle ar starting node
        }
        temp=temp->next;
        count++;
    }
    //akon temp last node ai ase
    temp->next=startNode;
}

bool detectCycle(Node* &head){
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow= slow->next;
        fast= fast->next->next;

        if(fast==slow){
            return true;
        }


    }
    return false;
}

void removeCycle(Node* &head){
    Node* slow=head;
    Node* fast=head;

    do{
      slow=slow->next;
      fast=fast->next->next;  
    }while(slow!=fast);

    fast=head;

    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

int main(){

    //Node* head=NULL;

    Node* node1=new Node(10);

    //cout<< node1 -> data<<endl;
   // cout<<node1-> next<<endl;

   Node* head= node1;
   Node* tail= node1;//starting ai head ar tail in same position

   print(head);
   
  /* insertionAtHead(head,12);
   print(head);

   insertionAtHead(head,15);
   print(head);*/


   insertionAtTail(tail,12);
   print(head);

   insertionAtTail(tail,15);
   print(head);

   insertionAtPosition(tail,head,4,22);
   print(head);

    insertionAtTail(tail,200);
    print(head);

    insertionAtTail(tail,150);
    print(head);


   cout<<"head "<<head->data<<endl;
   cout<<"tail "<<tail->data<<endl;

   makeCycle(head,3);

   cout<<detectCycle(head)<<endl;
   removeCycle(head);

   cout<<detectCycle(head)<<endl;



   //deleteNode(4,tail,head);
  // print(head);

  // cout<<"head "<<head->data<<endl;
   //cout<<"tail "<<tail->data<<endl;

   


    
}