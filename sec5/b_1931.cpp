#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
int a,b,from,to,res=1;

int main(){
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> a >>b;
        v.push_back({b,a});
    }
    sort(v.begin(), v.end());
    from = v[0].second;
    to = v[0].first;
    for(int i=1 ; i<n ; i++){
        if(v[i].second < to) continue;
        from = v[i].second; to = v[i].first; res++;
    }

    cout << res;

}