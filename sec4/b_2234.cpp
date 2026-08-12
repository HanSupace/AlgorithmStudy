#include <bits/stdc++.h>
using namespace std;
int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};
int mx = 0;
int big = 0;
int n,m;
int cnt=0;
int a[51][51], visited[51][51], res[2505];

int dfs(int y, int x, int cnt){
    if(visited[y][x]) return 0;
    visited[y][x] = cnt;
    int ret = 1;
    for(int i=0 ; i<4 ; i++){
        if(!(a[y][x] & (1<<i))){
            int ny = y +dy[i];
            int nx = x +dx[i];
            ret += dfs(ny,nx,cnt);
        }
    }
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> a[i][j];
        }
    }

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(visited[i][j]) continue;
            cnt++;
            res[cnt] = dfs(i,j,cnt);
            mx = max(mx, res[cnt]);
        }
    }

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(i+1<m){
                if(visited[i+1][j]!=visited[i][j]){
                    int tmp = res[visited[i+1][j]] + res[visited[i][j]];
                    big = max(big,tmp);
                }
            }
            if(j+1<n){
                if(visited[i][j]!=visited[i][j+1]){
                    int tmp = res[visited[i][j]] + res[visited[i][j+1]];
                    big = max(big,tmp);
                }
            }
        }
    }

    cout << cnt << "\n";
    cout << mx << "\n";
    cout << big << "\n";




}