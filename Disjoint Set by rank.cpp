#include<iostream>
//#include<bits/stdc++.h>
using namespace std;
//make,find and union 
const int N=1e5+10;

int parent[N];
int rank2[N];


 void make(int v){
    parent[v]=v;
   
    rank2[v]=0;
   
}

 int find(int v){
    if(parent[v]==v)return v;
    return parent[v]=find(parent[v]);
 }

 

 //union by rank
void Union2(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(rank2[a]<rank2[b]) swap(a,b);

        parent[b]=a;
        if(rank2[a]==rank2[b]) rank2[a]++;
    }

 }




int main(){

    int n,k;
    //cin>>n>>k;
    n=5,k=3;

    for(int i=1;i<=n;i++)make(i);

    while(k--){
        int u,v;
        cin>>u>>v;
       
        //Union2(u,v);
        Union2(0,2);
        Union2(4,2);
         Union2(3,1);
        
    }

    if(find(4)==find(0)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }

    if(find(1)==find(0)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }



    return 0;
}
