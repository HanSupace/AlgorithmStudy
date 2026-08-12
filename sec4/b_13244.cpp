#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1004];
int visited[1004];
int t,n,m;
int a,b;

void dfs(int here){
    visited[here] = 1;
    for(int there : adj[here]){
        if(!visited[there]) dfs(there);
    }
    return;
}

int main(){
    cin >> t;
    while(t--){
        int cnt=0;
        scanf("%d %d", &n, &m); 
        for(int i=0 ; i<1004 ; i++) adj[i].clear();
        fill(visited, visited+1004, 0);
        for(int i=0 ; i<m ; i++){
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i=1 ; i<=n ; i++){
            if(!visited[i]){
                dfs(i);
                cnt++;
            }
        }

        if(m==n-1 && cnt==1) cout << "tree\n";
        else cout << "graph\n";
    }

}