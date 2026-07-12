#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

queue<pair<int,int>> q;
int per[1004][1004];
char a[1004][1004];
int fire[1004][1004];

const int INF = 987654321;
int n,m;
int sy,sx;

int main(){
    cin >> n >> m;
    fill(&fire[0][0], &fire[0][0]+1004*1004,INF);

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> a[i][j];
            if(a[i][j]=='F'){
                fire[i][j]=1;
                q.push({i,j});
            }
            if(a[i][j]=='J'){
                sy = i;
                sx = j;
                per[i][j]= 1;
            }
        }
    }
    int y,x;
    while(q.size()){
        tie(y,x) = q.front();
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || ny >=n || nx >=m || nx<0) continue;
            if(a[ny][nx]=='#' || fire[ny][nx] != INF) continue;
            fire[ny][nx] = fire[y][x]+1;
            q.push({ny,nx});
        }
    }

    q.push({sy,sx});
    int res=0;
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y==0 || x == 0 || y == n-1 || x== m-1){
            res=per[y][x];
            break;
        }
        for(int i=0 ; i<4 ; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny >=n || nx >=m || nx<0) continue;
            if(per[ny][nx] || a[ny][nx]=='#') continue; 
            if(fire[ny][nx] <= per[y][x] + 1) continue;
            per[ny][nx] = per[y][x]+1;
            q.push({ny,nx});

        }
    }
    if(res != 0) cout << res << "\n";
    else cout << "IMPOSSIBLE \n";
    return 0;

}