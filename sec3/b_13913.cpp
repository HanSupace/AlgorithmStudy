#include <bits/stdc++.h>
using namespace std;

int n,k;
int mx = 100000;
int a[100004], visited[100004], spot[100004];

int main(){
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while(q.size()){
        int here = q.front();
        if(here == k){
            break;
        }
        q.pop();
        for(int next : {here+1, here-1, here*2}){
            if(next < 0 || next >= mx || visited[next] ) continue;
            visited[next] = visited[here] + 1;
            q.push(next);
            spot[next] = here;
        } 
    }
    vector<int> v;
    for(int i=k ; i!=n ; i=spot[i]){
        v.push_back(i);
    }
    v.push_back(n);
    reverse(v.begin(), v.end());

    cout << visited[k] -1 << "\n";

    for(int i : v){
        cout << i << " ";
    }

}