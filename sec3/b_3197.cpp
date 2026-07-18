#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int r,c;
int visited[1504][1504];
char a[1504][1504];
int swan_visited[1504][1504];
int swanX, swanY;
queue<pair<int,int>> waterQ, swanQ, swan_tmpQ, water_tmpQ;

void Qclear(queue<pair<int,int>> &q){
    queue<pair<int,int>> e;
    swap(q,e);
}

bool move_swan(){
    int y,x;
    
    while(swanQ.size()){
        tie(y,x) = swanQ.front();
        swanQ.pop();
        for(int i=0 ; i<4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny>=r || ny<0 || nx>=c || nx<0 || swan_visited[ny][nx]) continue;
            swan_visited[ny][nx] = 1;
            if(a[ny][nx]=='.') swanQ.push({ny,nx});
            if(a[ny][nx]=='X') swan_tmpQ.push({ny,nx});
            if(a[ny][nx]=='L') return true;
        }
    }
    return false;
}

void melt(){
    int x,y;
    while(waterQ.size()){
        tie(y,x) = waterQ.front();
        waterQ.pop();
        for(int i=0 ; i<4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny>=r || ny<0 || nx>=c || nx<0 || visited[ny][nx]) continue;
            if(a[ny][nx]=='X'){
                visited[ny][nx] = 1;
                water_tmpQ.push({ny,nx});
                a[ny][nx] = '.'; 
            }
        }
    }
    
}

int main(){
    string s;
    cin >> r >> c;
    for(int i=0 ; i<r ; i++){
        cin >> s;
        for(int j=0 ; j<c ; j++){
            a[i][j] = s[j];
            if(a[i][j]=='L'){swanY=i; swanX=j;}
            if(a[i][j]=='.' || a[i][j]=='L'){
                visited[i][j] = 1;
                waterQ.push({i,j});
            }
        }
    }
    swanQ.push({swanY, swanX});
    swan_visited[swanY][swanX] = 1;
    int cnt = 0;
    while(true){
        if(move_swan()){break;}
        melt();
        swanQ = swan_tmpQ;
        waterQ= water_tmpQ;
        Qclear(swan_tmpQ);
        Qclear(water_tmpQ);
        cnt ++;
    }

    cout << cnt;

}