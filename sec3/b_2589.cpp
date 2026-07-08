#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n,m,mx;

int a[51][51];
int visited[51][51];

void bfs(int y, int x){
    memset(visited, 0 , sizeof(visited));
    visited[y][x]=1;
    queue<pair<int,int>> q;
    q.push({y,x});

    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        for(int i=0 ; i<4 ; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(a[ny][nx]=='W' || visited[ny][nx]) continue;
            q.push({ny,nx});
            visited[ny][nx] = visited[y][x]+1;
            mx = max(mx, visited[ny][nx]);

        }
    }
    
}

int main(){
    string s;

    cin >> n >> m;

    for(int i=0; i < n ; i++){
        cin >> s;
        for(int j=0 ; j<m ; j++){
            a[i][j]= s[j];
        }
    }

    for(int i=0; i < n ; i++){
        for(int j=0 ; j<m ; j++){
            if(a[i][j]=='L') bfs(i,j);
        }
    }
    cout << mx-1;
}