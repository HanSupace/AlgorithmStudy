#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        int x;
        int res=0;
        cin >> x;

        for(int j=5 ; j<=x ; j*=5){
            res+=x/j;
        }
        cout << res <<"\n";

    }
}