#include <bits/stdc++.h>
using namespace std;

int n,a[20],m,tmp;
vector<int> adj[20];
int visited[20];
int com[20];
int res=987654321;

pair<int,int> dfs(int here, int val){
    visited[here] = 1;
    pair<int,int> ret = {1,a[here]};
    for(int there : adj[here]){
        if(com[there]!=val) continue;
        if(visited[there]) continue;
        pair<int,int> _tmp = dfs(there,val);
        ret.first += _tmp.first;
        ret.second += _tmp.second;
    }
    return ret;
}

int main(){

    cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }
    for(int i=1 ; i<=n ; i++){
        cin >> m;
        for(int j=0 ; j<m ; j++){
            cin >> tmp;
            adj[i].push_back(tmp);
            adj[tmp].push_back(i);
        }
    }

    for(int i=1 ; i<(1<<n)-1 ; i++){
        fill(com,com+20,0);
        fill(visited,visited+20,0);
        int idx1 = -1;
        int idx2 = -1;
        for(int j=0 ; j<n ; j++){
            if(i & (1<<j)) {com[j+1] = 1; idx1 = j+1;}
            else idx2 = j+1;
        }
        pair<int,int> ret1 = dfs(idx1, 1);
        pair<int,int> ret2 = dfs(idx2, 0);
        if(ret1.first+ret2.first==n) res = min(res,abs(ret1.second-ret2.second));
        
    }
    if(res==987654321){
        cout << -1;
    }
    else{
        cout << res;
    }


}