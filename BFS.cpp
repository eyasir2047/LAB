#include <iostream>
//level order print 
using namespace std;

const int MAXN = 1e3+10;  

bool graph[MAXN][MAXN];  
bool visited[MAXN];     
int queue[MAXN];        
int front = 0, rear = 0; 

void bfs(int start, int n) {//n=vertices 
    visited[start] = true;  
    queue[rear] = start;  
    rear++;

    while (front < rear) {  // while queue is not empty
        int curr = queue[front];
        front++;  
        cout << curr << " ";       

        for (int i = 1; i <= n; i++) {  // for each adjacent node
            if (graph[curr][i] && !visited[i]) {  
                visited[i] = true;    
                queue[rear] = i;
                rear++;
            }
        }
    }
}


int main() {
    int n, m;  
   
    n=5,m=5;

    for (int i = 0; i < m; i++) {  
       // int u, v;
       
       // graph[u][v] = graph[v][u] = true;  // undirected graph
        graph[0][1] = graph[1][0] = 1;
         graph[0][2] = graph[2][0] = 1;
         graph[0][3] = graph[3][0] = 1;
         graph[1][4] = graph[4][1] = 1;
         graph[3][5]=graph[5][3]=1;

    
     

    }

    int start;  
    
    start=0;

    bfs(start, n);

    return 0;
}
/*
graph[1][2] = graph[2][1] = true; 
       graph[2][3] = graph[3][2] = true; 
       graph[3][4] = graph[4][3] = true; 
       graph[4][5] = graph[5][4] = true; */