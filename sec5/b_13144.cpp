#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, cnt[100001], a[100001],l , r, res=0;;

int main(){
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }

    while(r<n){
        if(!cnt[a[r]]){
            cnt[a[r]]++;
            r++;
        }
        else{
            res += (r-l);
            cnt[a[l]]--;
            l++;
        }
    }
    res += (r-l) * (r-l+1) / 2;
    cout << res;
}
