#include <iostream>
using namespace std;

const int MAX_SIZE = 1e3+10; 


void DFS(int graph[][MAX_SIZE], bool visited[], int v, int vertices) {
    visited[v] = true; 
    cout << v << " "; 

   
    for (int i = 0; i < vertices; ++i) {
        
        if (!visited[i] && graph[v][i] == 1) {
            DFS(graph, visited, i, vertices);  
        }
    }
}

int main() {
    int vertices=5, edges=4;
    
    //cin >> vertices;

   
    int graph[MAX_SIZE][MAX_SIZE] = {0};

    
   // cin >> edges;

   
    for (int i = 0; i <edges; ++i) {
        // int u, v;
        // cin >> u >> v;
        // graph[u][v] = 1;
        // graph[v][u] = 1; // Assuming an undirected graph

    
        graph[0][1] = graph[1][0] = 1;
         graph[0][2] = graph[2][0] = 1;
         graph[0][3] = graph[3][0] = 1;
         graph[1][4] = graph[4][1] = 1;
    }

    bool visited[MAX_SIZE] = {false}; 
    int startVertex=0;
   
    

    cout << "DFS traversal starting from vertex " << startVertex << ": ";
    DFS(graph, visited, startVertex, vertices);

    cout << endl;
    return 0;
}





/*graph[1][2] = graph[2][1] = true;
        graph[1][3] = graph[3][1] = true;
        graph[1][4] = graph[4][1] = true;
        graph[3][5] = graph[5][3] = true;*/