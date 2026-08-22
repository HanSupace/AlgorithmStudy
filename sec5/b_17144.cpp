#include <bits/stdc++.h>
using namespace std;
int dy2[4] = {0,1,0,-1};
int dx2[4] = {1,0,-1,0};
int dy1[4] = {0,-1,0,1};
int dx1[4] = {1,0,-1,0};
int n,m,t,a[54][54],tmp[54][54],res;

vector<pair<int,int>> v1, v2;

void sol(vector<pair<int,int>> &v){
    for(int i=v.size()-1; i>0 ; i--){
        a[v[i].first][v[i].second] = a[v[i-1].first][v[i-1].second];
    }
    a[v[0].first][v[0].second] = 0; 
}

void mise(){
    fill(&tmp[0][0], &tmp[0][0]+54*54,0);
    queue<pair<int,int>> q;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(a[i][j]!=-1 && a[i][j]){
                q.push({i,j});
            }
        }
    }

    while(q.size()){
        int y,x;
        tie(y,x) = q.front(); q.pop();
        int spread = a[y][x]/5;
        for(int i=0 ; i<4 ; i++){
            int ny = y + dy1[i];
            int nx = x + dx1[i];
            if(ny >= n || ny<0 || nx>=m || nx<0 || a[ny][nx]==-1) continue;
            tmp[ny][nx] += spread;
            a[y][x] -= spread;
        }
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            a[i][j] += tmp[i][j];
        }
    }
}

vector<pair<int,int>> ro(int sy, int sx, int dy[], int dx[]){
    vector<pair<int, int>> v;
    int cnt = 0;
    int y = sy;
    int x = sx;
    while(true){
        int ny = y+dy[cnt];
        int nx = x+dx[cnt];
        if(ny==sy && nx == sx) break;
        if(ny >=n || ny<0 || nx >=m || nx<0){
            cnt++;
            ny = y + dy[cnt];
            nx = x + dx[cnt];
        }
        if(ny == sy && nx == sx)break;
        y=ny; x=nx;
        v.push_back({y,x});
    }
    return v;
}

int main(){
    cin >> n >> m >>t;
    bool flag = 1;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> a[i][j];
            if(a[i][j]==-1){
                if(flag){
                    v1 = ro(i,j,dy1,dx1);
                    flag = 0;
                }
                else{
                    v2 = ro(i,j,dy2,dx2);
                }
            }
        }
    }

    while(t--){
        mise();
        sol(v1);
        sol(v2);
    }

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(a[i][j]!=-1){
            res += a[i][j];

            }
        }
    }
    cout << res;
}