#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }

    ~Node(){
        int val= this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory free for node with data "<<val<<endl;
    }

};

void print(Node* &head,Node* &tail){
    Node* temp=head;

    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp =temp->next;
    }
    cout<<endl;

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    
}

int getLength(Node* head){
    Node* temp=head;
    int len=0;

    while(temp!=NULL){
        len++;
        temp=temp->next;
    }

    return len;
}

void insertionAtHead(Node* &tail,Node* &head,int d){

    if(head== NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
    Node* temp= new Node(d);
    temp->next=head;
    head->prev=temp;
    temp->prev=NULL;
    head= temp;
    }
    
}

void insertionAtTail(Node* &tail,Node* &head,int d){

    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
    Node* temp= new Node(d);
    temp->next=NULL;
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
    }
}

void insertAtPosition(Node* &tail,Node* &head,int position,int d){
    if(position==1){
        insertionAtHead(tail,head,d);
        return;
    }
    else{

        Node* temp= head;
        int cnt=1;

        while(cnt<position-1){
            temp=temp->next;
            cnt++;
        }
        //temp is in the current position

        if(temp->next==NULL){
            insertionAtTail(tail,head,d);
            return;
        }

        Node* nodeToInsert= new Node(d);

        nodeToInsert->next=temp->next;
        temp->next->prev=nodeToInsert;

        nodeToInsert->prev=temp;
        temp->next=nodeToInsert;





       
    }
}

void deleteNode(int position,Node* &tail,Node* &head){
    if(position==1){
        Node* temp= head;
        temp->next->prev= NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{

        Node* curr=head;
        Node* prev=NULL;

        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        if(curr->next==NULL){
            Node* temp2= tail;
            temp2->prev=NULL;
            prev->next=NULL;
            tail= prev;
            temp2->next=NULL;
            delete temp2;

            return;
        }

        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;

        delete curr;


    }
}





int main(){

    //Node* node1= new Node(10);
   // Node* head= node1;
   // Node* tail= node1;
   Node* head= NULL;
   Node* tail=NULL;

   //print(head);
    //cout<<getLength(head)<<endl;
    
    insertionAtHead(tail,head,11);
    print(head,tail);

    insertionAtHead(tail,head,8);
    print(head,tail);

    insertionAtTail(tail,head,25);
    print(head,tail);

    insertAtPosition(tail,head,2,100);
    print(head,tail);

    insertAtPosition(tail,head,1,101);
    print(head,tail);

    insertAtPosition(tail,head,6,102);
    print(head,tail);

    deleteNode(6,tail,head);
    print(head,tail);






    return 0;
}