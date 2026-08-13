#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<pair<ll,ll>> s;
ll n,tmp,res;
int main(){
    

    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> tmp;
        ll cnt = 1;
        while(s.size() && s.top().first <= tmp){
            res += s.top().second;
            if(s.top().first == tmp){
                cnt += s.top().second;
            }
            else{
                cnt=1;
            }
            s.pop();
        }
        if(s.size()) res++;
        s.push({tmp,cnt});

    }
    cout << res;
}