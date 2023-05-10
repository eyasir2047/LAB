#include<iostream>
#include<vector>
using namespace std;



bool dfs(int vertex,vector<bool>&color,vector<int>adj[],vector<int>&visited){
        
            visited[vertex]=1;
            
        //for(auto child:adj[vertex]){
            for(int i=0;i<adj[vertex].size();i++){

            int child=adj[vertex][i];

            if(!visited[child]){
            color[child]=!color[vertex];
            if(dfs(child,color,adj,visited)==false)return false;
            }
             else if(color[vertex]==color[child]) return false;
            
        }
        
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<bool>color(V);
	    color[0]=0; 
	    vector<int>visited(V,0);
	   
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            if(!dfs(i,color,adj,visited)){
	             return false;
	         }
	        }
	    }
	    
	    return true;
	     
	    
	   
	}

int main(){

    int n, m;  
   
    n=3,m=2;
    vector<int>adj[n];

    for (int i = 0; i < m; i++) {  
       // int u, v;
       
       // graph[u][v] = graph[v][u] = true;  // undirected graph
    
        
        adj[0].push_back(1);
        adj[1].push_back(0);
        adj[0].push_back(2);
        adj[2].push_back(0);
        //  adj[1].push_back(2);
        // adj[2].push_back(1);
       
}
        

    int start;  
    
    start=0;
    if(isBipartite(n,adj)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    


}