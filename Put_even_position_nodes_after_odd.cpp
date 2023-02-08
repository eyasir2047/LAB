#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
    public:
    int data;
   
    Node* next;

    //constructor
    Node(int d){
        this->data=d;
        
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

   // cout<<"head "<<head->data<<endl;
   // cout<<"tail "<<tail->data<<endl;
    
}

int length(Node* head){
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
       

      
        temp->next=nodeToInsert;





       
    }
}

void deleteNode(int position,Node* &tail,Node* &head){
    if(position==1){
        Node* temp= head;
      
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
            
            prev->next=NULL;
            tail= prev;
            temp2->next=NULL;
            delete temp2;

            return;
        }

       
        prev->next=curr->next;
        curr->next=NULL;

        delete curr;


    }
}

void evenAfterOdd(Node* &head){

    if(head==NULL) return;

    Node* odd=head;
    Node* even=head->next;
    Node* evenStart= even;
    
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    
    
    odd->next=evenStart;
    


}



int main(){

    //Node* node1= new Node(10);
   // Node* head= node1;
   // Node* tail= node1;
   Node* head= NULL;
   Node* tail=NULL;

  
   //print(head);
    //cout<<getLength(head)<<endl;
    
    int arr[]={1,2,3,4,5,6};
   
    for(int i=0;i<6;i++){
        insertionAtTail(tail,head,arr[i]);
    }

    print(head,tail);
    evenAfterOdd(head);
     print(head,tail);
    


    

   


    

   








    return 0;
}

