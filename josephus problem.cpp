#include<iostream>
using namespace std;
//josephus problem using circular linkedlist
//application of queue 


class node{
    public:
    int player_id;
    node* next;
    node(int player_id){
       this-> player_id=player_id;
        next=NULL;
    }

};
int main(){

    int n,k;
    cin>>n>>k;

    node* start=new node(1);
    node* ptr=start;
    node* new_node;

    int count,i;

    for(int i=2;i<=n;i++){
        new_node=new node(i);
        ptr->next=new_node;
         ptr=new_node;
        new_node->next=start;//circular
       

}

node* temp=start;
while(temp->next!=start){
    cout<<temp->player_id<<" ";
    temp=temp->next;
}
cout<<temp->player_id<<endl;



for(int count=n;count>1;count--){
    for( i=1;i<=k-1;++i){
        ptr=ptr->next;
    }
    cout<<"deleted element: "<<ptr->next->player_id<<endl;
    //node* temp=ptr->next;
    ptr->next=ptr->next->next;
    //delete temp;
}

cout<<"Winner:"<<ptr->player_id<<endl;














    return 0;
}