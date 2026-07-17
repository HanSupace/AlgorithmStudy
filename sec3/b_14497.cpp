#include <stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};

char a[301][301];
char visited[301][301];
int n,m,x1,x2,y1,y2;

queue<pair<int,int>> q;


int main(){

    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d %d %d %d", &y1,&x1,&y2,&x2);
    x1--; y1--; x2--; y2--;

    for(int i=0 ; i<n ; i++){
            scanf("%s", a[i]);
    }
    q.push({y1,x1});
    visited[y1][x1] = 1;
    int cnt = 0;

    while(a[y2][x2]!='0'){
        cnt ++;
        queue<pair<int,int>> tmp;
        while(q.size()){
            int y,x;
            tie(y,x) = q.front();
            q.pop();
            for(int i=0 ; i<4 ; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx<0 || nx>=m || visited[ny][nx]) continue;
                visited[ny][nx] = cnt;
                if(a[ny][nx]!='0'){
                    a[ny][nx]='0';
                    tmp.push({ny,nx});
                }
                else q.push({ny,nx});
            }
            
        }
        q=tmp;
    }

    printf("%d\n", visited[y2][x2]); 



}
