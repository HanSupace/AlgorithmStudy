#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    int res = 1;
    cin >> k;
    while(k!=1){
        if(k & 1) res++;
        k/=2;
    }
    cout << res;
}