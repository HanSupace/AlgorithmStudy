#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int m;
    cin >> m;

    int a[n];

    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    int cnt=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<i ; j++){
            if(a[i]+a[j]==m){
              cnt++;  
            }
        }
    }
    cout << cnt;
}