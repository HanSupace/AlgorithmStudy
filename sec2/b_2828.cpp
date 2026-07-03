#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, mx, t, d;
    int res = 0;

    cin >> n >> m;

    int mn = 1;
    mx = m;

    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> d;

        if(d < mn){
            int move = mn - d;
            res += move;
            mn -= move;
            mx -= move;
        }
        else if(d > mx){
            int move = d - mx;
            res += move;
            mn += move;
            mx += move;
        }
    }

    cout << res;
}