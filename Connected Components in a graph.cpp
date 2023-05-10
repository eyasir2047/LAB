#include <stdio.h>
#include<iostream>
using namespace std;

const int N = 1e3+10;
int g[N][N];
bool visited[N];

void dfs(int vertex) {
    visited[vertex] = true;

    for (int i = 1; i <= N; i++) {
        if (g[vertex][i] == 0) continue;
        if (visited[i]) continue;

        dfs(i);
    }
}

int main() {
    int n, m;
   // cin >> n >> m;
   n=4,m=3;

    for (int i = 1; i <= m; i++) {
        // int u, v;
        // cin >> u >> v;

        // g[u][v] = g[v][u] = 1;
        g[1][2]=g[2][1]=1;
        g[2][3]=g[3][2]=1;
        g[3][1]=g[1][3]=1;
        //1-2-3-1
        //4 
        //g[3][4]=g[4][3]=1;
        
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs(i);
        cnt++;
    }
    cout << cnt << endl;
}
