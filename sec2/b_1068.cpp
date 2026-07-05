#include <bits/stdc++.h>
using namespace std;


int n, r, root;
vector<int> adj[54];

int dfs(int here){
    int ret=0;
    int child=0;

    for(int there : adj[here]){
        if(r==there) continue;
        ret += dfs(there);
        child++;
    }
    if(child == 0) return 1;
    return ret;
}

int main(){

    cin >> n;
    int a;
    for(int i=0 ; i<n ; i++){
        cin >> a;
        if(a==-1) root = i;
        else adj[a].push_back(i);
    }

    cin >> r;

    if(r==root){
        cout << 0;
    
    }
    else{
    cout << dfs(root);

    }



}