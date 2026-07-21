#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n,a[14][14], visited[14][14];
int ret = 987654321;

bool check(int y, int x){
    if(visited[y][x]){
        return false;
    }
    for(int i=0 ; i<4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || ny >=n || nx < 0 || nx >=n || visited[ny][nx]) return false;

    }
    return true;
}

int setFlower(int y, int x){
    int tmp=0;
    visited[y][x] = 1;
    tmp += a[y][x];
    for(int i=0 ; i<4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
        tmp += a[ny][nx];
    }
    return tmp;
}

void eraseFlower(int y, int x){
    visited[y][x] = 0;
    for(int i=0 ; i<4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}

void sol(int cnt, int hap){
    if(cnt == 3){
        ret = min(ret,hap);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { 
            if (check(i, j)) {   
                sol(cnt+1,hap + setFlower(i, j)); 
                eraseFlower(i, j);
            }
        }
    } 
}

int main(){
    cin >> n;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> a[i][j];
        }
    }

    sol(0,0);

    cout << ret;
}