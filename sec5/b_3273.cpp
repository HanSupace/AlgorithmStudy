#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,n,res=0;
    cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    cin >> x;
    sort(a.begin(),a.end());
    int l=0, r=n-1;

    while(l<r){
        if(a[l]+a[r]==x) {
            r--; res++;
        }
        else if(a[l]+a[r]<x) l++;
        else if(a[l]+a[r]>x) r--;
    }
    cout << res;
}