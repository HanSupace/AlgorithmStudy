#include <bits/stdc++.h>
using namespace std;

int _a[6][3] = {
    {9,3,1},
    {9,1,3},
    {1,9,3},
    {1,3,9},
    {3,9,1},
    {3,1,9}
};
int n;
int visited[64][64][64], a[3];

struct A{
    int a,b,c;
};

queue<A> q;
int sol(int a, int b, int c){
    visited[a][b][c]=1;
    q.push({a,b,c});

    while(q.size()){
        int x = q.front().a;
        int y = q.front().b;
        int z = q.front().c;
        q.pop();
        if(visited[0][0][0]) break;
        for(int i=0 ; i<6 ; i++){
            int nx = max(0,x-_a[i][0]);
            int ny = max(0,y-_a[i][1]);
            int nz = max(0,z-_a[i][2]);
            if(visited[nx][ny][nz]) continue;
            visited[nx][ny][nz] = visited[x][y][z]+1;
            q.push({nx,ny,nz});
        }
        

    }
    return visited[0][0][0] -1;

}

int main(){
    cin >> n;
    for(int i=0 ; i<3 ; i++){
        cin >> a[i];
    }
    cout << sol(a[0], a[1], a[2]);
}
