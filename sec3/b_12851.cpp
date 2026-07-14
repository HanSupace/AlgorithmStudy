#include <bits/stdc++.h>
using namespace std;
int mx = 100004;
int cnt[100004],visited[100004];

int n,k;

queue<int> q;

int main(){
    cin >> n >> k;
    cnt[n]=1;
    visited[n]=1;
    q.push(n);
    while(q.size()){
        int now = q.front();
        q.pop();
        for(int next : {now+1, now-1, now*2}){
            if(next>=0 && next <=mx){

            if(!visited[next]){
                q.push(next);
                visited[next] = visited[now]+1;
                cnt[next] += cnt[now];
            }
            else if (visited[next] == visited[now] + 1) {
                    cnt[next] += cnt[now];
                }
            }

        }
    }
    cout << visited[k] - 1 << '\n';
    cout << cnt[k] << '\n';
}