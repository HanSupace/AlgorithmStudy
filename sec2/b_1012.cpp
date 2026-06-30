#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

const int max_n = 51;

int t,m,n,k,x,y;

int a[max_n][max_n];
bool vi[max_n][max_n];

void dfs(int y, int x){
    vi[y][x]= 1;
    for(int i=0 ; i<4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >=n || nx <0 || nx>=m) continue;
        if(!vi[ny][nx] && a[ny][nx]==1){
            dfs(ny,nx);
        }
    }
}

int main(){

    cin >> t;

    while(t--){
        cin >> m >> n >> k;

        fill(&a[0][0], &a[0][0]+51*51,0);
        fill(&vi[0][0], &vi[0][0]+51*51,0);

        int ret = 0;

        for(int i=0 ; i<k ; i++){
            cin >> x >> y;
            a[y][x] = 1;
        }
        for(int i = 0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vi[i][j] && a[i][j]==1){
                    dfs(i,j);
                    ret++;
                }
            }
        }
        cout << ret << "\n";
    }


}