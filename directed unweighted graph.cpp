#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e3+10;
int adj[N][N]; 
bool visited[N];
int distance2[N];

void bfs(int source, int n) {

    memset(visited, false, sizeof (visited));
    memset(distance2, -1, sizeof (distance2));

    queue<int> q;
     visited[source] = true;
    distance2[source] = 0;
    q.push(source);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int v = 1; v <= n; v++) {
            if(adj[curr][v] == 1 && !visited[v]) {
                visited[v] = true;
                distance2[v] = distance2[curr] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m; // n vertices and m edges
    //cin >> n >> m;
    n=4,m=3;
    for(int i = 1; i <= m; i++) {
        // int u, v;
        // cin >> u >> v;
        // adj[u][v] = adj[v][u] = 1; // adding edge to the adjacency matrix
        adj[0][1]=adj[1][0]=1;
        adj[1][2]=adj[2][1]=1;
        adj[2][3]=adj[3][2]=1;

        //0-1-2-3
        //4
        
    }
    int source;
    // cin >> source;
    source=1;
    bfs(source, n);
    for(int i = 1; i <= n; i++) {
       cout << "Distance of vertex " << i << " from source vertex " << source << " is " << distance2[i] << "\n";
    }
    return 0;
}
