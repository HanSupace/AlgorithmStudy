#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int a[101][101];
bool ch[101][101];
bool vi[101][101];

int n, t=1;
int mx = -1;
int mx_region = 1;

void dfs(int y, int x, int d){
    vi[y][x] = 1;
    for(int i=0 ; i<4 ; i++){
        int ny = y + dy[i];
        int nx = x+ dx[i];

        if(ny >= n || ny < 0 || nx >= n || nx < 0) continue;

        if(!vi[ny][nx] && a[ny][nx]-d > 0){
            dfs(ny,nx,d);
        }
    }
}

int main(){

    cin >> n;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> t;
            if(t>mx) mx=t;
            a[i][j]=t;
        }
    }
    int res=1;

    for(int i=1 ; i<mx ; i++){
        fill(&vi[0][0], &vi[0][0]+101*101,0);
        int ret = 0;
        for(int j=0 ; j<n ; j++){
            for(int z=0 ; z<n ; z++){
                if(a[j][z] > i && !vi[j][z]){
                    dfs(j,z,i);
                    ret++;
                }
            }
        }
        res = max(res,ret);





    }
    cout << res;





}