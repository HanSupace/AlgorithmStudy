#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> virusList, wallList;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n,m;
int visited[10][10];
int a[10][10];
int mx = -1;
int res=0;

void dfs(int y, int x){
    for(int i=0 ; i<4 ; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny>=n || nx >=m || ny < 0 || nx <0 || a[ny][nx]==1) continue;
        if(!visited[ny][nx] && a[ny][nx] == 0){
            visited[ny][nx]=1;
            dfs(ny,nx);
        }
    }
}

int sol(){
    int cnt=0;
    fill(&visited[0][0],&visited[0][0]+10*10,0);

    for(pair<int,int> a : virusList){
        visited[a.first][a.second] = 1;
        dfs(a.first, a.second);
    }
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(a[i][j]==0 && !visited[i][j]) cnt++;
        }
    }
    return cnt;

}


int main(){

    cin >> n>>m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> a[i][j];
            if(a[i][j]==2) virusList.push_back({i,j});
            if(a[i][j]==0) wallList.push_back({i,j});
        }
    }

    for(int i=0 ; i<wallList.size() ; i++){
        for(int j=0 ; j<i ; j++){
            for(int k=0 ; k<j ; k++){
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[j].first][wallList[j].second] = 1;
                a[wallList[k].first][wallList[k].second] = 1;
                res = max(res,sol());
                a[wallList[i].first][wallList[i].second] = 0;
                a[wallList[j].first][wallList[j].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }
    cout << res;



}