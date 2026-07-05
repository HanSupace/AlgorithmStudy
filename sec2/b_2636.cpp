#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int n,m;
int a[101][101];
bool visited[101][101];
int cnt , cnt1;
vector<pair<int,int>> v;


void sol(int y, int x){
    visited[y][x] = 1;
    if(a[y][x]==1){
        v.push_back({y,x});
        return;
    }

    for(int i=0 ; i<4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny>=n || nx >=m || nx<0 || ny < 0 || visited[ny][nx]) continue;
        sol(ny,nx);
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >>m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> a[i][j];
        }
    }

    while(true){
        fill(&visited[0][0],&visited[0][0]+101*101,0);
        v.clear();
        sol(0,0);
        cnt1 = v.size();
        for(pair<int,int> b : v){
            a[b.first][b.second] = 0;
        }
        bool flag = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(a[i][j]!=0) flag = 1;
            }
        }
        cnt++;
        if(flag == 0) break;
    }

    cout << cnt << "\n" << cnt1;

   


    
     
}