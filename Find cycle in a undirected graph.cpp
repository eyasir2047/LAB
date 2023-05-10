//#include <bits/stdc++.h>
#include<iostream>
using namespace std;

const int N = 1e3+10;

int n, m;
int adj[N][N], parent[N], color[N];

bool dfs(int u) {

    color[u] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[u][i]) {
            if (color[i] == 0) {
                parent[i] = u;
                if (dfs(i)) {
                    return true;
                }
            }
             else if (color[i] == 1 && parent[u] != i) {
                return true;
            }
        }
    }
    color[u] = 2;
    return false;
}

bool hasCycle() {

    memset(color, 0, sizeof(color));//initially color=0;

    memset(parent, -1, sizeof(parent));

    for (int i = 0; i < n; i++) {//n=vertices 
        if (color[i] == 0) {//uncolored
            if (dfs(i)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    //cin >> n >> m;
    n=4,m=3;
    for (int i = 0; i < m; i++) {
        // int u, v;
        // cin >> u >> v;
        //adj[u][v] = adj[v][u] = 1;
        adj[0][1]=adj[1][0]=1;
         adj[1][2]=adj[2][1]=1;
          adj[2][3]=adj[3][2]=1;
          //adj[3][1]=adj[1][3]=1;

    }
    if (hasCycle()) {
        cout << "Cycle exists in the graph" << endl;
    } else {
        cout << "No cycle exists in the graph" << endl;
    }
    return 0;
}
