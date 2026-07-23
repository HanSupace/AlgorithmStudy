#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int r, c, k;
int a[10][10];
int visited[10][10];
int cnt=0;

void sol(int y, int x){
    if(y==0 && x == c-1){
        if(visited[y][x] == k){
            cnt++;
        }
            return;
        
    }
    for(int i=0 ; i<4 ; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || a[ny][nx] == 'T')continue;
        visited[ny][nx] = visited[y][x] + 1; 
        sol(ny,nx);
        visited[ny][nx] = 0;
    }

}

int main(){
    cin >> r >> c >> k;
    string s;

    for(int i=0 ; i<r ; i++){
        cin >> s;
        for(int j=0 ; j<c ; j++){
            a[i][j] = s[j];
        }
    }
    visited[r-1][0] = 1;
    sol(r-1,0);
    cout << cnt;
}