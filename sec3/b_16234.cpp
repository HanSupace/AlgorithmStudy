#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n,l,r,sum;

int cnt = 0;;

int visited[104][104], a[104][104];
vector<pair<int,int>> v;

void dfs(int y, int x){
    for(int i=0 ; i<4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny>=n || nx>=n || nx<0 || visited[ny][nx]) continue;
        if(abs(a[y][x]-a[ny][nx]) >= l && abs(a[y][x]-a[ny][nx]) <= r){
            visited[ny][nx]=1;
            v.push_back({ny,nx});
            sum += a[ny][nx];
            dfs(ny,nx);
        }
    }
}

int main(){
    cin >> n >> l >> r;

    for(int i=0 ; i <n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> a[i][j];
        }

    }

    while(true){
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0]+104 * 104, 0);

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(!visited[i][j]){
                    v.clear();
                    visited[i][j]=1;
                    v.push_back({i,j});
                    sum = a[i][j];
                    dfs(i,j);
                    if(v.size()==1) continue;
                    for(pair<int,int> b : v){
                        a[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }

                }
            }
        }

        if(!flag){
            break;
        }
        cnt++;
    }
    cout << cnt;

}