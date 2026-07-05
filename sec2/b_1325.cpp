#include <bits/stdc++.h>
using namespace std;

int n,m,a,b;
vector<int> v[10004];
int dp[100004];
bool visited[10004];
int mx = -1;

int dfs(int here){
    visited[here] = 1;
    int ret = 1;
    for(int there : v[here]){
        if(visited[there]) continue;
        ret+= dfs(there);
    }
    return ret;
}

int main(){
    cin >> n >> m;

    for(int i=0 ; i<m ; i++){
        cin >> a >> b; 
        v[b].push_back(a);
    }

    for(int i=1 ; i<=n ; i++){
        fill(visited, visited+10004, 0);
        dp[i] = dfs(i);
        if(mx < dp[i]) mx=dp[i];
    }

    for(int i=1 ; i<=n ; i++){
        if(dp[i]==mx) {
            cout << i << " ";
        }
    }

    
}