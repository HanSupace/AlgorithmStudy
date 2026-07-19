#include <bits/stdc++.h>
using namespace std;
int k;
int a[1200];

vector<int> v[14];

void sol(int s, int e, int level){
    if(s>e) return;
    if(s==e){
        v[level].push_back(a[s]);
        return;
    }
    int mid = (s+e)/2;
    v[level].push_back(a[mid]);
    sol(s,mid-1,level+1);
    sol(mid+1,e,level+1);
}

int main(){
    cin >> k;
    int _end = (int)pow(2,k)-1;
    for(int i=0 ; i<_end ; i++){
        cin >> a[i];
    }
    sol(0,_end,1);
    for(int i=1 ; i<=k ; i++){
        for(int j : v[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
}